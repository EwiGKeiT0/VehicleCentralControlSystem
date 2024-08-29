#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <QFont>
#include <QScrollBar>
#include <QScrollArea>
#include <QGridLayout>
#include <QTextEdit>
#include <QHostAddress>
#include <QTcpSocket>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include "widget.h"
#include "colorgradient.h"
#include "facetime.h"

namespace Ui {
    class chatWidget;
}

class userButton : public QPushButton
{
    Q_OBJECT

public:
    explicit userButton(QWidget *parent, QString userName, QPixmap userProfile);
    ~userButton();
    void setGradient(QColor start, QColor end, int DURATION);
    QPropertyAnimation *animation;
    bool selected;
    std::vector<std::pair<userButton*,QString>> messages;
    QString name;
    QPixmap profile;
};

class chatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit chatWidget(QWidget *parent = nullptr, Widget *father = nullptr);
    ~chatWidget();
    void sendMessage(QString msg = "");

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    QWidget* getBubble(QPixmap profile, QString str, int type);
    QWidget* myBubble(QString str);
    QWidget* oppositeBubble(userButton *user, QString str);
    void refreshMessage(userButton *newUser);
    std::pair<int, int> getBubbleSize(QString &str);
    void sendVideoRequest(userButton *target);
    void sendVideoAccept(QString sender, QString receiver);

private slots:
    void on_sendButton_clicked();
    void on_fileButton_clicked();
    void on_videoButton_clicked();
    void receiveMessage();

private:
    const int textOffset = 27;
    const QString myName = "User1";
    const QString serverIp = "10.194.156.111";
    const int serverPort = 8887;

    Ui::chatWidget *ui;
    Widget *mainWidget;
    std::vector<userButton*> userList;
    std::vector<userButton*> groupList;
    userButton *currentUser;
    QPixmap myProfile;
    QTcpSocket *tcpSocket;
    bool transferring = 0, successfullyOpen = 0;
    QString fileName, fileSender;
    qint64 fileSize, fileReceivedSize;
    QFile file;

    std::vector<FaceTime*> faceTime;

    FaceTime *test;
};

class keyboardEventfilter : public QObject
{
    Q_OBJECT
public:
    keyboardEventfilter(QObject *parent = nullptr, chatWidget *father = nullptr);
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
private:
    bool pressingShift = false;
    chatWidget *mainWidget;
};

#endif // CHATWIDGET_H
