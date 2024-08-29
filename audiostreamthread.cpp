#include "audiostreamthread.h"
#include <QDate>

AudioStreamThread::AudioStreamThread(const QString &url, QObject *parent)
    : QThread(parent), url(url), playing(false), formatContext(nullptr), codecContext(nullptr), swrContext(nullptr), audioSink(nullptr), audioDevice(nullptr), channels(0) {
}
AudioStreamThread::~AudioStreamThread() {
    stop();
}

void AudioStreamThread::stop() {
    playing = false;
    wait();
}

void AudioStreamThread::run() {
    if (avformat_open_input(&formatContext, url.toStdString().c_str(), nullptr, nullptr) != 0) {
        emit errorOccurred("无法打开输入流");
        return;
    }

    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        emit errorOccurred("无法获取流信息");
        avformat_close_input(&formatContext);
        return;
    }

    // 查找音频流
    int audioStreamIndex = -1;
    const AVCodec *codec = nullptr;
    for (unsigned i = 0; i < formatContext->nb_streams; i++) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
            audioStreamIndex = i;
            codec = avcodec_find_decoder(formatContext->streams[i]->codecpar->codec_id);
            break;
        }
    }
    if (audioStreamIndex == -1 || codec == nullptr) {
        emit errorOccurred("无法找到音频流或解码器");
        avformat_close_input(&formatContext);
        return;
    }

    // 初始化音频解码器
    codecContext = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(codecContext, formatContext->streams[audioStreamIndex]->codecpar);
    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        emit errorOccurred("无法打开音频解码器");
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        return;
    }

    channels = codecContext->ch_layout.nb_channels;

    // 初始化音频输出
    initializeAudioOutput();

    // 初始化重采样上下文
    swrContext = swr_alloc();
    av_opt_set_chlayout(swrContext, "in_chlayout", &codecContext->ch_layout, 0);
    av_opt_set_chlayout(swrContext, "out_chlayout", &codecContext->ch_layout, 0);
    av_opt_set_int(swrContext, "in_sample_rate", codecContext->sample_rate, 0);
    av_opt_set_int(swrContext, "out_sample_rate", codecContext->sample_rate, 0);
    av_opt_set_sample_fmt(swrContext, "in_sample_fmt", codecContext->sample_fmt, 0);
    av_opt_set_sample_fmt(swrContext, "out_sample_fmt", AV_SAMPLE_FMT_S16, 0);
    swr_init(swrContext);

    AVPacket *packet = av_packet_alloc();
    AVFrame *frame = av_frame_alloc();

    // 定义音频播放的时间基准
    qint64 startTime = QDateTime::currentMSecsSinceEpoch();

    playing = true;
    while (playing && av_read_frame(formatContext, packet) >= 0) {
        if (packet->stream_index == audioStreamIndex) {
            if (avcodec_send_packet(codecContext, packet) == 0) {
                while (avcodec_receive_frame(codecContext, frame) == 0) {
                    // 重采样
                    uint8_t *outputBuffer[2] = { nullptr };
                    av_samples_alloc(outputBuffer, nullptr, channels, frame->nb_samples, AV_SAMPLE_FMT_S16, 0);
                    int samples = swr_convert(swrContext, outputBuffer, frame->nb_samples, (const uint8_t **)frame->data, frame->nb_samples);

                    int dataSize = av_samples_get_buffer_size(nullptr, channels, samples, AV_SAMPLE_FMT_S16, 1);
                    QByteArray audioData(reinterpret_cast<char*>(outputBuffer[0]), dataSize);

                    // 计算音频播放的延迟
                    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
                    int64_t pts = frame->pts * av_q2d(formatContext->streams[audioStreamIndex]->time_base) * 1000;
                    int64_t delay = pts - (currentTime - startTime);
                    if (delay > 0) {
                        QThread::msleep(delay);
                    }

                    audioDevice->write(audioData);  // 播放音频

                    av_freep(&outputBuffer[0]);
                }
            }
        }
        av_packet_unref(packet);
    }
    av_frame_free(&frame);
    av_packet_free(&packet);
    cleanup();
}

void AudioStreamThread::initializeAudioOutput() {
    QAudioFormat format;
    format.setSampleRate(codecContext->sample_rate);
    format.setChannelCount(channels);
    format.setSampleFormat(QAudioFormat::Int16);

    audioSink = new QAudioSink(format, this);
    audioDevice = audioSink->start();
}

void AudioStreamThread::cleanup() {
    if (audioSink) {
        audioSink->stop();
        delete audioSink;
        audioSink = nullptr;
    }
    avcodec_free_context(&codecContext);
    swr_free(&swrContext);
    avformat_close_input(&formatContext);
}
