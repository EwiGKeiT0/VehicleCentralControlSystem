#include "videoencoderthread.h"
#include <QDebug>
#include <QNetworkDatagram>

VideoEncoderThread::VideoEncoderThread(QObject *parent, QString serverIp, int serverPort)
    : QThread(parent)
    , isEncoding(false)
    , codecContext(nullptr)
    , swsContext(nullptr)
    , tcpSocket(nullptr)
    , ip(serverIp)
    , port(serverPort)
{
    camera = new QCamera(this);
    captureSession = new QMediaCaptureSession(this);
    videoSink = new QVideoSink(this);
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(ip, port);
    tcpSocket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 64 * 1024 * 1024);

    captureSession->setCamera(camera);
    captureSession->setVideoSink(videoSink);

    connect(videoSink, &QVideoSink::videoFrameChanged, this, [this](const QVideoFrame &frame) {
        if (isEncoding) {
            qDebug() << "Video frame received, starting encoding.";
            encodeAndSendFrame(frame);
        }
    });
}

VideoEncoderThread::~VideoEncoderThread() {
    stopEncoding();
}

void VideoEncoderThread::startEncoding() {
    isEncoding = true;
    if (!isRunning()) {
        qDebug() << "Starting encoding thread...";
        start();
    }
}

void VideoEncoderThread::stopEncoding() {
    qDebug() << "Stopping encoding...";
    isEncoding = false;
    wait();
    qDebug() << "Encoding stopped.";
}

void VideoEncoderThread::run() {
    qDebug() << "Initializing encoder...";
    initializeEncoder();  // 初始化编码器并连接服务器

    camera->start();
    qDebug() << "Camera started, encoding in progress...";

    while (isEncoding) {
        QThread::msleep(30); // 控制帧率
    }

    cleanup();
}

void VideoEncoderThread::initializeEncoder() {
    if (!tcpSocket->waitForConnected(5000)) {
        qWarning() << "Failed to connect to TCP server";
        return;
    }

    qDebug() << "Connected to TCP server successfully.";

    // 找到 MJPEG 编码器
    const AVCodec *codec = avcodec_find_encoder(AV_CODEC_ID_MJPEG);
    if (!codec) {
        qWarning() << "MJPEG Codec not found!";
        return;
    }

    // 创建编码器上下文
    codecContext = avcodec_alloc_context3(codec);
    if (!codecContext) {
        qWarning() << "Could not allocate video codec context!";
        return;
    }

    // 设置 MJPEG 编码器参数
    codecContext->codec_id = AV_CODEC_ID_MJPEG;
    codecContext->bit_rate = 400000;
    codecContext->width = 640;
    codecContext->height = 480;
    codecContext->time_base = {1, 30};
    codecContext->framerate = {30, 1};
    codecContext->pix_fmt = AV_PIX_FMT_YUVJ420P;  // 注意：MJPEG 通常使用 YUVJ420P

    // 打开编码器
    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        qWarning() << "Failed to open MJPEG codec";
        avcodec_free_context(&codecContext);
        return;
    }

    qDebug() << "MJPEG Codec opened successfully.";

    // 初始化 swsContext，用于图像格式转换
    swsContext = sws_getContext(codecContext->width, codecContext->height, AV_PIX_FMT_NV12,
                                codecContext->width, codecContext->height, AV_PIX_FMT_YUVJ420P,
                                SWS_BILINEAR, nullptr, nullptr, nullptr);

    if (!swsContext) {
        qWarning() << "Failed to initialize swsContext";
        avcodec_free_context(&codecContext);
        return;
    } else {
        qDebug() << "swsContext initialized successfully.";
    }
}

void VideoEncoderThread::encodeAndSendFrame(const QVideoFrame &frame) {
    qDebug() << "Camera output format:" << frame.pixelFormat();
    if (!frame.isValid()) {
        qWarning() << "Received invalid frame!";
        return;
    }

    // 确保 QVideoFrame 的格式是 NV12
    if (frame.pixelFormat() != QVideoFrameFormat::Format_NV12) {
        qWarning() << "Unsupported pixel format!";
        return;
    }

    // 映射视频帧以访问其数据
    QVideoFrame videoFrame = frame;
    if (!videoFrame.map(QVideoFrame::ReadOnly)) {
        qWarning() << "Failed to map video frame!";
        return;
    }

    // 创建并初始化 AVFrame
    AVFrame *avFrame = av_frame_alloc();
    if (!avFrame) {
        qWarning() << "Failed to allocate AVFrame!";
        videoFrame.unmap();
        return;
    }

    avFrame->format = codecContext->pix_fmt; // YUVJ420P
    avFrame->width = codecContext->width;
    avFrame->height = codecContext->height;

    // 为 AVFrame 分配缓冲区
    if (av_frame_get_buffer(avFrame, 32) < 0) { // 32 是字节对齐值，通常为 16 或 32
        qWarning() << "Failed to allocate AVFrame buffer!";
        av_frame_free(&avFrame);
        videoFrame.unmap();
        return;
    }
    // 获取输入帧的数据 (NV12 格式)
    uint8_t *srcData[2] = { videoFrame.bits(0), videoFrame.bits(1) };
    int srcLinesize[2] = { videoFrame.bytesPerLine(0), videoFrame.bytesPerLine(1)};

    if (!swsContext) {
        qWarning() << "Failed to initialize swsContext!";
        av_frame_free(&avFrame);
        videoFrame.unmap();
        return;
    }

    // 使用 sws_scale 将 NV12 格式转换为 YUVJ420P
    int result = sws_scale(swsContext, srcData, srcLinesize, 0, codecContext->height, avFrame->data, avFrame->linesize);

    if (result <= 0) {
        qWarning() << "sws_scale failed, possible invalid data or memory issues.";
        av_frame_free(&avFrame);
        videoFrame.unmap();
        return;
    }

    // 设置 PTS (Presentation Timestamp)
    avFrame->pts = av_gettime() / 1000;

    // 编码帧
    AVPacket *pkt = av_packet_alloc();
    pkt->data = nullptr;
    pkt->size = 0;
    if (avcodec_send_frame(codecContext, avFrame) < 0) {
        qWarning() << "Failed to send frame to encoder!";
        av_frame_free(&avFrame);
        videoFrame.unmap();
        return;
    }
    qDebug() << "fafafa" ;
    // 获取编码后的数据并通过 TCP 发送
    while (avcodec_receive_packet(codecContext, pkt) == 0) {
        qDebug() << "Sending packet to TCP server, size:" << pkt->size;

        if (tcpSocket && tcpSocket->state() == QAbstractSocket::ConnectedState) {
            int bytesRemaining = pkt->size;
            const char* dataPtr = reinterpret_cast<const char*>(pkt->data);

            while (bytesRemaining > 0) {
                qint64 bytesToSend = qMin(bytesRemaining, 4096);  // 发送最多 4096 字节的数据
                qint64 bytesSent = tcpSocket->write(dataPtr, bytesToSend);

                if (bytesSent == -1) {
                    qWarning() << "Failed to write data to TCP socket:" << tcpSocket->errorString();
                    break;
                }

                if (!tcpSocket->flush()) {
                    qWarning() << "Failed to flush TCP socket:" << tcpSocket->errorString();
                    break;
                }

                bytesRemaining -= bytesSent;
                dataPtr += bytesSent;
            }

        } else {
            qWarning() << "TCP socket is not connected!";
            qWarning() << "Socket state:" << tcpSocket->state();
            qWarning() << "Socket error:" << tcpSocket->errorString();
            break;
        }

        av_packet_unref(pkt);
    }

    // 清理
    av_frame_free(&avFrame);
    videoFrame.unmap();
}

void VideoEncoderThread::cleanup() {
    qDebug() << "Cleaning up resources...";
    if (tcpSocket) {
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    }
    if (codecContext) {
        avcodec_free_context(&codecContext);
    }
    if (swsContext) {
        sws_freeContext(swsContext);
    }
    camera->stop();
}
