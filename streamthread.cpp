#include "streamthread.h"
#include "mediawidget.h"
#include <QDebug>

StreamThread::StreamThread(const QString &url, mediaWidget *parent)
    : QThread(parent)
    , url(url)
    , playing(false)
    , codec(nullptr) {
}

StreamThread::~StreamThread() {
    stop();
}

void StreamThread::stop() {
    QMutexLocker locker(&mutex);
    playing = false;
}

void StreamThread::run() {
    AVFormatContext *formatContext = nullptr;//存储流的格式信息。
    if (avformat_open_input(&formatContext, url.toStdString().c_str(), nullptr, nullptr) != 0) {//成功返回0，否则非
        qDebug() << "无法打开输入流";
        return;//失败直接退出
    }
    qDebug()<<"在这里"<<formatContext->streams[0]->codecpar;
    /*
        功能：打开输入流，初始化 AVFormatContext。
        参数：
        &formatContext：指向 AVFormatContext 的指针，函数将通过该指针返回打开的输入流。
        url.toStdString().c_str()：输入流的 URL。
        nullptr：用于指定输入流的格式，通常设为 nullptr，让 FFmpeg 自动检测。
        nullptr：用于传递额外的选项，通常设为 nullptr。
        返回值：成功返回 0，失败返回非 0。
    */

    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        qDebug() << "无法获取流信息";
        avformat_close_input(&formatContext);
        return;//失败直接退出
    }
    /*
        功能：读取输入流的流信息（例如流的类型、编码信息等）。
        参数：
        formatContext：指向已打开的 AVFormatContext。
        nullptr：用于指定流信息的附加选项，通常设为 nullptr。
        返回值：成功返回 0，失败返回负值。
    */

    int videoStreamIndex = -1;
    for (unsigned i = 0; i < formatContext->nb_streams; i++) {
        AVStream *stream = formatContext->streams[i];

        if (stream->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStreamIndex = i;
            codec = avcodec_find_decoder(stream->codecpar->codec_id);
            break;
        }
    }

    if (videoStreamIndex == -1) {
        qDebug() << "无法找到视频流";
        avformat_close_input(&formatContext);
        return;
    }

    AVCodecContext *codecContext = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(codecContext, formatContext->streams[videoStreamIndex]->codecpar);
    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        qDebug() << "无法打开解码器";
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        return;
    }

    AVFrame *frame = av_frame_alloc();
    AVPacket *packet = av_packet_alloc();
    SwsContext *swsContext = sws_getContext(
        codecContext->width, codecContext->height, codecContext->pix_fmt,
        codecContext->width, codecContext->height, AV_PIX_FMT_RGB24,
        SWS_BILINEAR, nullptr, nullptr, nullptr);

    playing = true;
    int64_t start_time = av_gettime() / 1000;

    while (playing && av_read_frame(formatContext, packet) >= 0) {
        if (packet->stream_index == videoStreamIndex) {
            if (avcodec_send_packet(codecContext, packet) == 0) {
                while (avcodec_receive_frame(codecContext, frame) == 0) {
                    QImage image(codecContext->width, codecContext->height, QImage::Format_RGB888);
                    uint8_t *dest[4] = { image.bits(), nullptr, nullptr, nullptr };
                    int destLinesize[4] = { codecContext->width * 3, 0, 0, 0 };
                    sws_scale(swsContext, frame->data, frame->linesize, 0, codecContext->height, dest, destLinesize);

                    emit frameReady(image);  // 发送信号，通知新的一帧已准备好

                    // 计算当前帧的延迟时间
                    int64_t delay = (frame->pts * av_q2d(formatContext->streams[videoStreamIndex]->time_base)) * 1000;
                    int64_t current_time = av_gettime() / 1000;
                    int64_t wait_time = delay - (current_time - start_time);

                    if (wait_time > 0) {
                        QThread::msleep(wait_time);  // 等待一段时间以确保帧率
                    }

                    fps++;
                    qDebug() << fps;
                }
            }
        }
        av_packet_unref(packet);
    }
    qDebug()<<"出来了";
    av_frame_free(&frame);
    av_packet_free(&packet);
    avcodec_free_context(&codecContext);
    avformat_close_input(&formatContext);
    sws_freeContext(swsContext);
}
