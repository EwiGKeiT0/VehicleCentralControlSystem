#include "facetime.h"

FaceTime::FaceTime(QObject *parent, QDialog *videoDialog,
            VideoEncoderThread *videoEncoderThread, VideoReceiver *videoReceiver)
    : QObject(parent)
    , vDialog(videoDialog)
    , vThread(videoEncoderThread)
    , vReceiver(videoReceiver)
{
    videoDialog->show();
    vThread->startEncoding();
    connect(videoReceiver, &VideoReceiver::frameReceived, this, &FaceTime::frameReceived);
    connect(vDialog, &QDialog::finished, this, &FaceTime::dialogClose);
}

FaceTime::~FaceTime()
{
    dialogClose();
}

void FaceTime::dialogClose()
{
    vDialog->close();
    delete vThread;
    delete vReceiver;
    delete vDialog;
}

void FaceTime::frameReceived(const QPixmap &pixmap)
{
    QPalette palette = vDialog->palette();
    palette.setBrush(QPalette::Window, pixmap);
    vDialog->setPalette(palette);
}


