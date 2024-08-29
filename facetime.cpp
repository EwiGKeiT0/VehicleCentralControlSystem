#include "facetime.h"

FaceTime::FaceTime(QObject *parent, QDialog *videoDialog,
            VideoEncoderThread *videoEncoderThread, VideoReceiver *videoReceiver)
    : QObject(parent)
    , vDialog(videoDialog)
    , vThread(videoEncoderThread)
    , vReceiver(videoReceiver)
{
    vDialog->show();


    thread = new QThread;
    vReceiver->moveToThread(thread);
    connect(vReceiver, &VideoReceiver::frameReceived, this, &FaceTime::frameReceived);
    connect(vDialog, &QDialog::rejected, this, &FaceTime::dialogClose);

    vThread->startEncoding();
    thread->start();
    vReceiver->startListening();
}

FaceTime::~FaceTime()
{
    vDialog->close();
    dialogClose();
}

void FaceTime::dialogClose()
{
    qDebug() << "Dialog closed.";
    vReceiver->closeTcpConnect();
    thread->quit();
    thread->wait();
    vThread->stopEncoding();
}

void FaceTime::frameReceived(const QPixmap &pixmap)
{
    QPalette palette = vDialog->palette();
    palette.setBrush(QPalette::Window, pixmap);
    vDialog->setPalette(palette);
}


