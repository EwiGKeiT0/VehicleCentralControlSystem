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
    socket = new QTcpSocket();
    socket->connectToHost(ip, port);

    if (!socket->waitForConnected(5000)) {
        qWarning() << "Failed to connect to cloud server";
        return;
    } else {
        qDebug() << "Connected to cloud server successfully";
    }

    // 连接信号和槽
    connect(socket, &QTcpSocket::readyRead, this, &VideoReceiver::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &VideoReceiver::onDisconnected);
}

void VideoReceiver::startListening()
{
    qDebug() << "Server is ready to receive frames from cloud server...";
}

void VideoReceiver::onReadyRead()
{
    buffer.append(socket->readAll());

    // 检查缓冲区中的 JPEG 图像标记，并确保接收到完整的图像数据
    while (buffer.contains("\xFF\xD8") && buffer.contains("\xFF\xD9")) {
        int startIdx = buffer.indexOf("\xFF\xD8");
        int endIdx = buffer.indexOf("\xFF\xD9") + 2;

        // 提取完整的 JPEG 数据
        if (startIdx != -1 && endIdx != -1 && endIdx > startIdx) {
            QByteArray jpegData = buffer.mid(startIdx, endIdx - startIdx);

            // 将 JPEG 数据转换为 QPixmap
            QPixmap pixmap;
            if (pixmap.loadFromData(jpegData, "JPEG")) {
                emit frameReceived(pixmap);  // 发送接收到的图片信号
                qDebug() << "Image received and displayed";

                // 保存图像
                if (pixmap.save("received_frame.jpg")) {
                    qDebug() << "Image saved as 'received_frame.jpg'";
                } else {
                    qDebug() << "Failed to save image";
                }
            } else {
                qDebug() << "Failed to decode image";
            }

            // 从缓冲区中移除已处理的数据
            buffer.remove(0, endIdx);
        } else {
            break;  // 如果数据不完整，等待接收更多数据
        }
    }
}

void VideoReceiver::onDisconnected()
{
    qDebug() << "Disconnected from cloud server";
    socket->deleteLater();
    socket = nullptr;
}
