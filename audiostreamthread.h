#ifndef AUDIOSTREAMTHREAD_H
#define AUDIOSTREAMTHREAD_H

#include <QThread>
#include <QAudioSink>
#include <QIODevice>
#include <QAudioFormat>
#include <QByteArray>
#include <QDebug>


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
#include <libswresample/swresample.h>  // 添加此行以支持音频重采样
}

class AudioStreamThread : public QThread {
    Q_OBJECT

public:
    AudioStreamThread(const QString &url, QObject *parent = nullptr);
    ~AudioStreamThread();
    void stop();

signals:
    void errorOccurred(const QString &error);

protected:
    void run() override;

private:
    QString url;
    bool playing;
    AVFormatContext *formatContext;
    AVCodecContext *codecContext;
    SwrContext *swrContext;
    QAudioSink *audioSink;
    QIODevice *audioDevice;
    int channels;

    void initializeAudioOutput();
    void cleanup();
};

#endif // AUDIOSTREAMTHREAD_H
