#ifndef STREAMTHREAD_H
#define STREAMTHREAD_H

#include <QThread>
#include <QImage>
#include <QMutex>
#include <QMutexLocker>
#include <QObject>

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

class mediaWidget;  // 前向声明 Widget 类

class StreamThread : public QThread {
    Q_OBJECT

public:
    StreamThread(const QString &url, mediaWidget *parent);
    ~StreamThread();
    void stop();

signals:
    void frameReady(const QImage &image);  // 新的一帧图像已经ready

protected:
    void run() override;

private:
    QString url;
    bool playing;
    QMutex mutex;
    int fps=0;
    mediaWidget *widget;
    const AVCodec *codec;
};

#endif // STREAMTHREAD_H
