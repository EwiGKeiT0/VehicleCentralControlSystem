#include "videoreceiver.h"
#include <QBuffer>
#include <QDebug>
#include <QImageReader>
#include <QTcpSocket>

VideoReceiver::VideoReceiver(QObject *parent, QString serverIp, int serverPort)
    : QObject(parent)
    , ip(serverIp)
    , port(serverPort)
{
}

VideoReceiver::~VideoReceiver()
{
    closeTcpConnect();
}

void VideoReceiver::startListening()
{
    socket = new QTcpSocket(this);
    socket->connectToHost(ip, port);

    socket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 64 * 1024 * 1024);

    if (!socket->waitForConnected(5000)) {
        qWarning() << "Failed to connect to cloud server";
        return;
    } else {
        qDebug() << "Connected to cloud server successfully";
    }

    // 连接信号和槽
    connect(socket, &QTcpSocket::readyRead, this, &VideoReceiver::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &VideoReceiver::onDisconnected);
    qDebug() << "Server is ready to receive frames from cloud server...";
}

void VideoReceiver::onReadyRead()
{
    buffer.append(socket->readAll());
    qDebug() << buffer.size();
    while (buffer.contains("\xFF\xD9")) {
        int startIdx = buffer.indexOf("\xFF\xD8");
        int endIdx = buffer.indexOf("\xFF\xD9");

        if (startIdx != -1 && startIdx < endIdx) {
            QByteArray jpegData = buffer.mid(startIdx, qMin(endIdx - startIdx + 2, buffer.size() - startIdx));

            QPixmap pixmap;
            if (pixmap.loadFromData(jpegData, "JPEG")) {
                emit frameReceived(pixmap);
                qDebug() << "Image received and displayed";
            } else {
                qDebug() << "Failed to decode image";
            }
        }

        buffer.remove(0, endIdx + 2);
    }
}

void VideoReceiver::onDisconnected()
{
    qDebug() << "Disconnected from cloud server";
}

void VideoReceiver::closeTcpConnect()
{
    emit shouldClose();
    socket->disconnectFromHost();
    socket->close();
}
