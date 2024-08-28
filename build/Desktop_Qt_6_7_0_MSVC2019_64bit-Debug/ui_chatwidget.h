/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatWidget
{
public:
    QWidget *mainWidget;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *nameText;
    QScrollArea *chatList;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *messageList;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *nameWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *userName;
    QWidget *textWidget;
    QTextEdit *textEdit;
    QPushButton *fileButton;
    QPushButton *videoButton;
    QPushButton *sendButton;
    QWidget *widget;
    QWidget *widget_2;

    void setupUi(QWidget *chatWidget)
    {
        if (chatWidget->objectName().isEmpty())
            chatWidget->setObjectName("chatWidget");
        chatWidget->resize(1110, 700);
        chatWidget->setStyleSheet(QString::fromUtf8("#nameText, #userName\n"
"{\n"
"	font-size:28px;\n"
"	color: rgba(200, 200, 200, 1);\n"
"}\n"
"#userName\n"
"{\n"
"	font-size:22px;\n"
"}\n"
"#infoText\n"
"{\n"
"	font-size:15px;\n"
"	color: rgba(200, 200, 200, 1);\n"
"}"));
        mainWidget = new QWidget(chatWidget);
        mainWidget->setObjectName("mainWidget");
        mainWidget->setGeometry(QRect(0, 0, 1110, 700));
        mainWidget->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color:rgba(0,0,0,0);\n"
"}\n"
"#sendButton\n"
"{\n"
"	background-color: rgb(176, 224, 230);\n"
"	font-size:15px;\n"
"}"));
        infoWidget = new QWidget(mainWidget);
        infoWidget->setObjectName("infoWidget");
        infoWidget->setGeometry(QRect(110, 20, 141, 81));
        verticalLayout = new QVBoxLayout(infoWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        nameText = new QLabel(infoWidget);
        nameText->setObjectName("nameText");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameText->sizePolicy().hasHeightForWidth());
        nameText->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(nameText);


        verticalLayout->addLayout(verticalLayout_3);

        chatList = new QScrollArea(mainWidget);
        chatList->setObjectName("chatList");
        chatList->setGeometry(QRect(0, 110, 250, 590));
        chatList->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-radius: 0px;\n"
"	background-color: rgb(150,150,150);\n"
"}\n"
"QPushButton\n"
"{\n"
"	border: none;\n"
"	font-size: 20px;\n"
"	color: rgb(255,255,255);\n"
"	text-align:left;\n"
"	padding-left:18px;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background: rgb(160,160,160);\n"
"}\n"
"QScrollBar:vertical\n"
"{\n"
"	width: 8px;\n"
"	background:rgb(130,130,130);\n"
"	padding:0px;\n"
"	border-radius: 4px;\n"
"}\n"
"QScrollBar::handle:vertical\n"
"{\n"
"	background:rgb(180,180,180);\n"
"	border-radius: 4px;\n"
"}\n"
"QScrollBar::handle:vertical:hover\n"
"{\n"
"	background: rgb(160,160,160);\n"
"}\n"
"QScrollBar::handle:vertical:pressed\n"
"{\n"
"	background: rgb(150,150,150);\n"
"}\n"
"QScrollBar::add-page:vertical\n"
"{\n"
"	background:none;\n"
"}\n"
"QScrollBar::sub-page:vertical\n"
"{\n"
"	background:none;\n"
"}\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"	background:none;\n"
"}\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"	background: none;\n"
"}"));
        chatList->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        chatList->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        chatList->setWidgetResizable(true);
        chatList->setAlignment(Qt::AlignmentFlag::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 250, 590));
        chatList->setWidget(scrollAreaWidgetContents);
        messageList = new QScrollArea(mainWidget);
        messageList->setObjectName("messageList");
        messageList->setGeometry(QRect(250, 112, 860, 438));
        messageList->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-radius: 0px;\n"
"	background: rgba(0,0,0,0);\n"
"}\n"
"QLabel\n"
"{\n"
"	background-color:rgb(100,100,100);\n"
"	border-radius:10px;\n"
"	font-size:14px;\n"
"	padding:10px;\n"
"	color: rgb(255,255,255);\n"
"}\n"
"QScrollBar:vertical\n"
"{\n"
"	width: 8px;\n"
"	background:rgb(130,130,130);\n"
"	padding:0px;\n"
"	border-radius: 4px;\n"
"}\n"
"QScrollBar::handle:vertical\n"
"{\n"
"	background:rgb(180,180,180);\n"
"	border-radius: 4px;\n"
"}\n"
"QScrollBar::handle:vertical:hover\n"
"{\n"
"	background: rgb(160,160,160);\n"
"}\n"
"QScrollBar::handle:vertical:pressed\n"
"{\n"
"	background: rgb(150,150,150);\n"
"}\n"
"QScrollBar::add-page:vertical\n"
"{\n"
"	background:none;\n"
"}\n"
"QScrollBar::sub-page:vertical\n"
"{\n"
"	background:none;\n"
"}\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"	background:none;\n"
"}\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"	background: none;\n"
"}"));
        messageList->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        messageList->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        messageList->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 860, 438));
        messageList->setWidget(scrollAreaWidgetContents_2);
        nameWidget = new QWidget(mainWidget);
        nameWidget->setObjectName("nameWidget");
        nameWidget->setGeometry(QRect(310, 20, 141, 81));
        verticalLayout_5 = new QVBoxLayout(nameWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        userName = new QLabel(nameWidget);
        userName->setObjectName("userName");
        sizePolicy.setHeightForWidth(userName->sizePolicy().hasHeightForWidth());
        userName->setSizePolicy(sizePolicy);
        QFont font;
        userName->setFont(font);

        verticalLayout_6->addWidget(userName);


        verticalLayout_5->addLayout(verticalLayout_6);

        textWidget = new QWidget(mainWidget);
        textWidget->setObjectName("textWidget");
        textWidget->setGeometry(QRect(250, 550, 861, 151));
        textWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border:none;\n"
"	border-radius: 0px;\n"
"}\n"
"QTextEdit\n"
"{\n"
"	color: rgb(255,255,255);\n"
"}\n"
"QScrollBar:vertical\n"
"{\n"
"	width: 8px;\n"
"	background:rgb(130,130,130);\n"
"	padding:0px;\n"
"	border-radius: 4px;\n"
"}\n"
"QScrollBar::handle:vertical\n"
"{\n"
"	background:rgb(180,180,180);\n"
"	border-radius: 4px;\n"
"}\n"
"QScrollBar::handle:vertical:hover\n"
"{\n"
"	background: rgb(160,160,160);\n"
"}\n"
"QScrollBar::handle:vertical:pressed\n"
"{\n"
"	background: rgb(150,150,150);\n"
"}\n"
"QScrollBar::add-page:vertical\n"
"{\n"
"	background:none;\n"
"}\n"
"QScrollBar::sub-page:vertical\n"
"{\n"
"	background:none;\n"
"}\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"	background:none;\n"
"}\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"	background: none;\n"
"}\n"
"QPushButton\n"
"{\n"
"	border-radius: 10px;\n"
"	color:rgb(255,255,255);\n"
"}"));
        textEdit = new QTextEdit(textWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 30, 841, 111));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit\n"
"{\n"
"	background-color: rgb(36,36,42);\n"
"}\n"
"QMenu\n"
"{\n"
"	border-radius: 10px;\n"
"}"));
        fileButton = new QPushButton(textWidget);
        fileButton->setObjectName("fileButton");
        fileButton->setGeometry(QRect(10, 3, 30, 30));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DocumentNew")));
        fileButton->setIcon(icon);
        fileButton->setIconSize(QSize(20, 20));
        fileButton->setFlat(false);
        videoButton = new QPushButton(textWidget);
        videoButton->setObjectName("videoButton");
        videoButton->setGeometry(QRect(50, 3, 30, 30));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::CameraVideo")));
        videoButton->setIcon(icon1);
        videoButton->setIconSize(QSize(20, 20));
        videoButton->setFlat(false);
        sendButton = new QPushButton(mainWidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(1020, 645, 70, 35));
        sendButton->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(mainWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(250, 550, 861, 2));
        widget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(50,50,50);\n"
"	border:none;\n"
"	border-radius: 0px;\n"
"}"));
        widget_2 = new QWidget(mainWidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(250, 110, 861, 2));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(50,50,50);\n"
"	border:none;\n"
"	border-radius: 0px;\n"
"}"));

        retranslateUi(chatWidget);

        QMetaObject::connectSlotsByName(chatWidget);
    } // setupUi

    void retranslateUi(QWidget *chatWidget)
    {
        chatWidget->setWindowTitle(QCoreApplication::translate("chatWidget", "Form", nullptr));
        nameText->setText(QCoreApplication::translate("chatWidget", "\350\201\212\345\244\251", nullptr));
        userName->setText(QCoreApplication::translate("chatWidget", "\345\220\215\345\255\227", nullptr));
        fileButton->setText(QString());
        videoButton->setText(QString());
        sendButton->setText(QCoreApplication::translate("chatWidget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatWidget: public Ui_chatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
