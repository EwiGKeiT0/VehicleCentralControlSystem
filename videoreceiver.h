#ifndef VIDEORECEIVER_H
#define VIDEORECEIVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QPixmap>

class VideoReceiver : public QObject
{
    Q_OBJECT

public:
    VideoReceiver(QObject *parent = nullptr, QString serverIp = "127.0.0.1", int serverPort = 8889);
    void startListening();  // 开始监听TCP连接并接收视频流

signals:
    void frameReceived(const QPixmap &pixmap);  // 信号：接收到新的视频帧

private slots:
    void onReadyRead();  // 当有数据可读时的槽函数
    void onDisconnected();  // 当连接断开时的槽函数

private:
    QTcpSocket *socket;  // 当前的TCP连接套接字
    QByteArray buffer;   // 缓冲区，用于存储接收到的二进制数据
    QString ip;
    int port;
};

#endif // VIDEORECEIVER_H
