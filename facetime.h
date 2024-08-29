#ifndef FACETIME_H
#define FACETIME_H

#include <QThread>
#include <QDialog>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPalette>
#include "videoencoderthread.h"
#include "videoreceiver.h"

class FaceTime : public QObject
{
    Q_OBJECT
public:
    FaceTime(QObject *parent = nullptr, QDialog *videoDialog = nullptr,
            VideoEncoderThread *videoEncoderThread = nullptr, VideoReceiver *videoReceiver = nullptr);
    ~FaceTime();
private slots:
    void frameReceived(const QPixmap &pixmap);
    void dialogClose();
private:
    VideoEncoderThread *vThread;
    VideoReceiver *vReceiver;
    QDialog *vDialog;
    QString ip;
    int port;
    QThread *thread;
};



#endif // FACETIME_H
