#ifndef VIDEOENCODERTHREAD_H
#define VIDEOENCODERTHREAD_H

#include <QThread>
#include <QCamera>
#include <QMediaCaptureSession>
#include <QVideoSink>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QUdpSocket>
#include <QTime>
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
    #include <libavutil/imgutils.h>
}

class VideoEncoderThread : public QThread
{
    Q_OBJECT

public:
    VideoEncoderThread(QObject *parent = nullptr, QString serverIp = "127.0.0.1", int serverPort = 8889);
    ~VideoEncoderThread();
    void startEncoding(); // 开始编码并传输
    void stopEncoding();                          // 停止编码
protected:
    void run() override;                          // 线程入口

private:
    void initializeEncoder();                     // 初始化编码器
    void encodeAndSendFrame(const QVideoFrame &frame); // 编码并发送视频帧
    void cleanup();                                // 清理资源

    bool isEncoding;                               // 编码状态标志
    QTcpSocket *tcpSocket;                         // 用于传输视频的TCP套接字
    QCamera *camera;                               // 摄像头对象
    QMediaCaptureSession *captureSession;          // 媒体捕获会话
    QVideoSink *videoSink;                         // 视频帧接收器

    AVCodecContext *codecContext;                  // 编码器上下文
    SwsContext *swsContext;                        // 图像格式转换上下文

    QString ip;
    int port;
};

#endif // VIDEOENCODERTHREAD_H
