#include "chatwidget.h"
#include "ui_chatwidget.h"

chatWidget::chatWidget(QWidget *parent, Widget *father)
    : QWidget(parent)
    , ui(new Ui::chatWidget)
    , mainWidget(father)
{
    ui->setupUi(this);

    QGridLayout *cLayout = new QGridLayout();
    cLayout->setSpacing(0);
    cLayout->setContentsMargins(0, 0, 0, 0);
    for (int i = 0; i <= 0; i++)
    {
        QPixmap profile(210, 210);
        profile.fill();
        QPainter painter(&profile);
        for (int j = 0; j < 6; j++)
        {
            QPixmap uProfile(QString(":/profile/profile%1.png").arg(j));
            uProfile = mainWidget->getPixmapWithBorderRadius(uProfile.scaled(QSize(70, 70), Qt::KeepAspectRatio, Qt::SmoothTransformation), 10);
            painter.drawPixmap(j % 3 * 70, 35 + j / 3 * 70, uProfile);
        }
        painter.end();
        profile = mainWidget->getPixmapWithBorderRadius(profile.scaled(QSize(70, 70), Qt::KeepAspectRatio, Qt::SmoothTransformation), 10);
        userButton *uBtn = new userButton(ui->chatList->widget(), QString("Group%1").arg(i), profile);
        uBtn->installEventFilter(this);

        cLayout->addWidget(uBtn);
        groupList.push_back(uBtn);
    }
    for (int i = 0; i <= 5; i++)
        if (QString("User%1").arg(i) != myName)
        {
            QPixmap profile(QString(":/profile/profile%1.png").arg(i));
            profile = mainWidget->getPixmapWithBorderRadius(profile.scaled(QSize(70, 70), Qt::KeepAspectRatio, Qt::SmoothTransformation), 10);

            userButton *uBtn = new userButton(ui->chatList->widget(), QString("User%1").arg(i), profile);
            uBtn->installEventFilter(this);

            cLayout->addWidget(uBtn);
            userList.push_back(uBtn);
        }
    ui->chatList->widget()->setLayout(cLayout);

    currentUser = groupList[0];

    QFont font = ui->textEdit->font();
    font.setPointSize(13);
    ui->textEdit->setFont(font);

    ui->userName->setText(currentUser->name);

    mainWidget->setGradient(ui->sendButton, QColor(176, 224, 230), QColor(19, 145, 255), 150);
    mainWidget->setGradient(ui->fileButton, QColor(36, 36, 42), QColor(76, 76, 82), 150);
    mainWidget->setGradient(ui->videoButton, QColor(36, 36, 42), QColor(76, 76, 82), 150);

    myProfile = QPixmap(QString(":/profile/profile%1.png").arg(myName[4]));
    myProfile = mainWidget->getPixmapWithBorderRadius(myProfile.scaled(QSize(40, 40), Qt::KeepAspectRatio, Qt::SmoothTransformation), 10);

    refreshMessage(currentUser);
    QScrollBar *bar = ui->messageList->verticalScrollBar();
    QObject::connect(bar, &QScrollBar::rangeChanged, [bar]()
        {
            bar->setValue(bar->maximum());
        });

    ui->textEdit->installEventFilter(new keyboardEventfilter(ui->textEdit, this));
    ui->textEdit->setPlaceholderText("请发送非空内容");

    tcpSocket = new QTcpSocket();
    tcpSocket->connectToHost(serverIp, serverPort);

    connect(tcpSocket, &QTcpSocket::connected, this, [this](){
        QString sizeANDmsg = QString("%1:%2").arg(myName.size()).arg(myName);
        tcpSocket->write(sizeANDmsg.toUtf8().data());
    });

    connect(tcpSocket, &QTcpSocket::readyRead, this, &chatWidget::receiveMessage);

    // QDialog *dialog = new QDialog();
    // VideoEncoderThread *videoThread = new VideoEncoderThread(nullptr, serverIp, serverPort + 1);
    // VideoReceiver *videoReceiver = new VideoReceiver(nullptr, serverIp, serverPort + 1);
    // test = new FaceTime(nullptr, dialog, videoThread, videoReceiver);
}

std::pair<int, int> chatWidget::getBubbleSize(QString &str)
{
    QFont myFont;
    myFont.setPixelSize(14);
    QFontMetrics metrics(myFont);
    QString ret, cur;
    for (int i = 0; i < str.length(); i ++)
        if (str[i] == '\n' || metrics.boundingRect(cur + str[i]).width() > 500)
        {
            ret += cur + "\n";
            cur.clear();
            cur = str[i];
        } else
            cur += str[i];
    if (!cur.isEmpty())
        ret += cur;
    str = ret;
    QStringList strList = str.split("\n");
    int width = 0, height = 0;
    for (auto it = strList.constBegin(); it != strList.constEnd(); it++)
    {
        width = qMax(width, metrics.boundingRect(*it).width() + textOffset);
        height += qMax(metrics.boundingRect(*it).height(), 18);
    }
    return {width, height + 20};
}

QWidget* chatWidget::getBubble(QPixmap profile, QString str, int type)
{
    std::pair<int, int> bubbleSize = getBubbleSize(str);
    int width = bubbleSize.first;
    int height = bubbleSize.second;

    QWidget *bubble = new QWidget();
    bubble->setFixedSize(860, qMax(height, 40));

    QLabel *pf = new QLabel(bubble);
    pf->setPixmap(profile);
    if (type == 0)
        pf->setGeometry(790, 0, 40, 40);
    else
        pf->setGeometry(30, 0, 40, 40);
    pf->setStyleSheet("padding:0px;");

    QLabel *message = new QLabel(bubble);
    mainWidget->setGradient(message, QColor(100, 100, 100), QColor(140, 140, 140), 150);
    if (type == 0)
        message->setGeometry(780 - width, 0, width, height);
    else
        message->setGeometry(80, 0, width, height);
    message->setText(str);
    message->setTextInteractionFlags(Qt::TextSelectableByMouse);

    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setOffset(0, 0);
    shadowEffect->setBlurRadius(15);
    shadowEffect->setColor(QColor(10, 10, 10));
    bubble->setGraphicsEffect(shadowEffect);

    return bubble;
}

QWidget* chatWidget::myBubble(QString str)
{
    return getBubble(myProfile, str, 0);
}

QWidget* chatWidget::oppositeBubble(userButton *user, QString str)
{
    return getBubble(user->profile.scaled(QSize(40, 40), Qt::KeepAspectRatio, Qt::SmoothTransformation), str, 1);
}

void chatWidget::refreshMessage(userButton *newUser)
{
    currentUser->setStyleSheet("");
    currentUser->selected = false;
    currentUser = newUser;
    currentUser->setStyleSheet("background-color:rgb(190,190,190);");
    currentUser->selected = true;
    ui->userName->setText(currentUser->name);

    QLayout *layout = ui->messageList->widget()->layout();
    if (layout != nullptr)
    {
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr)
        {
            if (child->widget())
            {
                child->widget()->setParent(nullptr);
                delete child->widget();
            }
            delete child;
            child = nullptr;
        }
        delete layout;
    }

    QGridLayout *mLayout = new QGridLayout();
    mLayout->setSpacing(20);
    mLayout->setContentsMargins(0, 20, 0, 20);
    for (auto & [user, str] : currentUser->messages)
        if (user == nullptr)
            mLayout->addWidget(myBubble(str));
        else
            mLayout->addWidget(oppositeBubble(user, str));
    ui->messageList->widget()->setLayout(mLayout);
}

bool chatWidget::eventFilter(QObject *obj, QEvent *event)
{
    userButton *cur = qobject_cast<userButton*>(obj);
    if (cur && event->type() == QEvent::MouseButtonRelease)
    {
        refreshMessage(cur);
        return true;
    }
    if (cur && event->type() == QEvent::Enter)
    {
        cur->animation->setDirection(QPropertyAnimation::Forward);
        cur->animation->start();
        return true;
    }
    if (cur && event->type() == QEvent::Leave)
    {
        cur->animation->setDirection(QPropertyAnimation::Backward);
        cur->animation->start();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void userButton::setGradient(QColor start, QColor end, int DURATION)
{
    ColorGradient *color = new ColorGradient(start, end);
    animation = new QPropertyAnimation(color, "gradient");
    animation->setDuration(150);
    animation->setStartValue(0);
    animation->setEndValue(1);
    QObject::connect(color, &ColorGradient::gradientChanged, this,
                     [this, color]
                     {
                        if (this->selected)
                        {
                            setStyleSheet("background-color:rgba("+
                                          QString::number(color->getCurrent().red() + 40)+","+
                                          QString::number(color->getCurrent().green() + 40)+","+
                                          QString::number(color->getCurrent().blue() + 40)+","+
                                          QString::number(color->getCurrent().alpha())+");");
                        }
                        else
                        {
                            setStyleSheet("background-color:rgba("+
                                            QString::number(color->getCurrent().red())+","+
                                            QString::number(color->getCurrent().green())+","+
                                            QString::number(color->getCurrent().blue())+","+
                                            QString::number(color->getCurrent().alpha())+");");
                        }
                     });
}

chatWidget::~chatWidget()
{
    delete ui;
}

userButton::userButton(QWidget *parent, QString userName, QPixmap userProfile)
    : QPushButton(parent)
    , name(userName)
    , profile(userProfile)
{
    setText("   "+name);
    setFixedSize(QSize(250, 100));
    setIcon(profile);
    setIconSize(QSize(70, 70));
    setGradient(QColor(150, 150, 150), QColor(170, 170, 170), 150);
    selected = false;
}

userButton::~userButton()
{
    delete animation;
}

keyboardEventfilter::keyboardEventfilter(QObject *parent, chatWidget *father) :
    QObject(parent), mainWidget(father) {}

bool keyboardEventfilter::eventFilter(QObject *obj, QEvent *event)
{
    QTextEdit *element = qobject_cast<QTextEdit *>(obj);
    if (element)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if ((keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) && !pressingShift)
            {
                mainWidget->sendMessage();
                return true;
            }
            if (keyEvent->key() == Qt::Key_Shift)
                pressingShift = true;
        }
        else if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent->key() == Qt::Key_Shift)
                pressingShift = false;
        }
    }
    return QObject::eventFilter(obj, event);
}

void chatWidget::sendMessage(QString message)
{
    if (message.isEmpty())
    {
        message = ui->textEdit->toPlainText();
        ui->textEdit->clear();
    }
    if (message.count("\n") == message.size())
        return;

    QString msg = QString("%1:%2").arg(currentUser->name, message);
    QString sizeANDmsg = QString("%1:%2").arg(msg.toUtf8().size()).arg(msg);
    tcpSocket->write(sizeANDmsg.toUtf8().data());

    currentUser->messages.push_back({nullptr, message});
    refreshMessage(currentUser);
}

void chatWidget::receiveMessage()
{
    QByteArray buffer = tcpSocket->readAll();
    qDebug() << buffer;
    while (buffer.size() > 0)
    {
        if (buffer.left(4) == "DAMN")
        {
            buffer.remove(0, 4);
            QMessageBox::critical(nullptr, "视频通话", "对方不在线",
                                  QMessageBox::StandardButtons(QMessageBox::Yes),
                                  QMessageBox::StandardButton(QMessageBox::NoButton));
        } else
        if (transferring)
        {
            if (successfullyOpen)
            {
                qint64 size = file.write(buffer.left(qMin(buffer.size(), fileSize - fileReceivedSize)));
                buffer.remove(0, size);
                fileReceivedSize += size;
                if (fileReceivedSize >= fileSize)
                {
                    file.close();
                    transferring = false;
                    for (auto uBtn : userList)
                        if (uBtn->name == fileSender)
                        {
                            currentUser = uBtn;
                            break;
                        }
                    sendMessage("Received file at: " + file.fileName());
                }
            } else
            {
                qint64 size = qMin(buffer.size(), fileSize - fileReceivedSize);
                buffer.remove(0, size);
                fileReceivedSize += size;
                if (fileReceivedSize >= fileSize)
                {
                    transferring = false;
                    sendMessage("File reception failed");
                }
            }
        } else
        if (buffer.left(4) == "FILE")
        {
            transferring = 1;

            int i = 0;
            for (; buffer[i] != ':'; i++);
            buffer.remove(0, i + 1);

            for (i = 0; buffer[i] != ':'; i++);
            fileSender = buffer.left(i);
            buffer.remove(0, i + 1);

            for (i = 0; buffer[i] != ':'; i++);
            fileName = buffer.left(i);
            buffer.remove(0, i + 1);

            for (i = 0; buffer[i] != ':'; i++);
            QString sizeStr = buffer.left(i);
            fileSize = sizeStr.toInt();
            buffer.remove(0, i + 1);

            fileReceivedSize = 0;
            QString filePath = QStandardPaths::standardLocations(QStandardPaths::DownloadLocation).takeAt(0) + "/" + fileName;
            file.setFileName(filePath);

            if (file.exists())
                file.remove();

            if (file.open(QIODevice::WriteOnly | QIODevice::Append))
            {
                successfullyOpen = true;
                if (buffer.size() > 0)
                {
                    qint64 size = file.write(buffer.left(qMin(buffer.size(), fileSize - fileReceivedSize)));
                    buffer.remove(0, size);
                    fileReceivedSize += size;
                }
                if (fileReceivedSize >= fileSize)
                {
                    file.close();
                    transferring = false;
                    for (auto uBtn : userList)
                        if (uBtn->name == fileSender)
                        {
                            currentUser = uBtn;
                            break;
                        }
                    sendMessage("Received file at: " + file.fileName());
                }
            }
            else
                successfullyOpen = false;
        } else
        if (buffer.left(5) == "VIDEO")
        {
            int i = 0;
            for (; buffer[i] != ':'; i++);
            buffer.remove(0, i + 1);

            for (i = 0; buffer[i] != ':'; i++);
            QString sizeInf = buffer.left(i);
            buffer.remove(0, i + 1);

            int size = sizeInf.toInt();
            QString sender = buffer.left(size);
            buffer.remove(0, size);

            for (auto uBtn : userList)
                if (uBtn->name == sender)
                {
                    currentUser = uBtn;
                    break;
                }

            if (QMessageBox::question(nullptr, "视频通话", QString("%1申请和您视频通话").arg(sender),
                                    QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No),
                                    QMessageBox::StandardButton(QMessageBox::NoButton)) == QMessageBox::Yes)
            {
                sendVideoAccept(sender, myName);
            } else
            {
                sendMessage("Refused.");
            }
        } else
        if (buffer.left(6) == "ACCEPT")
        {
            int i = 0;
            for (; buffer[i] != ':'; i++);
            buffer.remove(0, i + 1);

            for (i = 0; buffer[i] != ':'; i++);
            QString sizeInf = buffer.left(i);
            buffer.remove(0, i + 1);

            int size = sizeInf.toInt();
            QString message = buffer.left(size);
            buffer.remove(0, size);

            QString sender = message.section(":", 0, 0);
            int sign = message.section(":", 1, 1).toInt();

            for (auto uBtn : userList)
                if (uBtn->name == sender)
                {
                    currentUser = uBtn;
                    break;
                }

            qDebug() << (serverPort + sign);

            QDialog *dialog = new QDialog();
            VideoEncoderThread *videoThread = new VideoEncoderThread(nullptr, serverIp, serverPort + sign);
            VideoReceiver *videoReceiver = new VideoReceiver(nullptr, serverIp, (serverPort + sign) ^ 1);
            faceTime.push_back(new FaceTime(nullptr, dialog, videoThread, videoReceiver));
        } else
        if (buffer.left(5) == "GROUP")
        {
            int i = 0;
            for (; buffer[i] != ':'; i++);
            buffer.remove(0, i + 1);

            for (i = 0; buffer[i] != ':'; i++);
            QString sizeInf = buffer.left(i);
            buffer.remove(0, i + 1);

            int size = sizeInf.toInt();
            QString message = buffer.left(size);
            buffer.remove(0, size);

            qDebug() << message;

            QString groupName = message.section(":", 0, 0);
            QString sender = message.section(":", 1, 1);
            message = message.section(":", 2);

            for (auto group : groupList)
                if (group->name == groupName)
                {
                    for (auto uBtn : userList)
                        if (uBtn->name == sender)
                        {
                            group->messages.push_back({uBtn, message});
                            break;
                        }
                    if (group == currentUser)
                        refreshMessage(currentUser);
                    break;
                }
        } else
        {
            int i = 0;
            for (; buffer[i] != ':'; i++);
            QString sizeInf = buffer.left(i);
            buffer.remove(0, i + 1);

            int size = sizeInf.toInt();
            QString message = buffer.left(size);
            buffer.remove(0, size);

            QString sender = message.section(":", 0, 0);
            message = message.section(":", 1);

            for (auto uBtn : userList)
                if (uBtn->name == sender)
                {
                    uBtn->messages.push_back({uBtn, message});
                    if (uBtn == currentUser)
                        refreshMessage(currentUser);
                    break;
                }
        }
    }
}

void chatWidget::sendVideoRequest(userButton *target)
{
    QString msg = target->name;
    QString sizeANDmsg = QString("VIDEO:%1:%2").arg(msg.toUtf8().size()).arg(msg);
    tcpSocket->write(sizeANDmsg.toUtf8().data());
    qDebug() << "?";
}

void chatWidget::sendVideoAccept(QString sender, QString receiver)
{
    QString msg = QString("%1:%2").arg(sender).arg(receiver);
    QString sizeANDmsg = QString("ACCEPT:%1:%2").arg(msg.toUtf8().size()).arg(msg);
    tcpSocket->write(sizeANDmsg.toUtf8().data());
}

void chatWidget::on_sendButton_clicked()
{
    sendMessage();
}

void chatWidget::on_fileButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "选择文件", "./");
    QFile file;
    file.setFileName(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        QFileInfo info(filePath);
        QString fileName = info.fileName();
        qint64 fileSize = info.size();

        sendMessage("Sent file: " + fileName);

        QString header = QString("FILE:%1:%2:%3:").arg(currentUser->name, fileName).arg(fileSize);
        tcpSocket->write(header.toUtf8().data());

        for (qint64 bufferSize = 1; bufferSize > 0; )
        {
            char buffer[1024] = {0};
            bufferSize = file.read(buffer, sizeof buffer);
            tcpSocket->write(buffer, bufferSize);
        }
    }
}

void chatWidget::on_videoButton_clicked()
{
    if (currentUser->name[0] == 'G')
    {
        QMessageBox::critical(nullptr, "视频通话", "群组内暂不支持视频通话",
                            QMessageBox::StandardButtons(QMessageBox::Yes),
                            QMessageBox::StandardButton(QMessageBox::NoButton));
    } else
    {
        sendMessage("Requesting video call...");
        sendVideoRequest(currentUser);
    }
}

