/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *tabWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *NaviButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *BrowserButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *IndexButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *ChatButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QLabel *MediaButton;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_11;
    QLabel *SettingButton;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_7;
    QStackedWidget *mainWidget;
    QLabel *backButton;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1260, 720);
        Widget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-radius: 10px;\n"
"	border:none;\n"
"}"));
        tabWidget = new QWidget(Widget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 130, 700));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setMaximumSize(QSize(130, 16777215));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(tabWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        NaviButton = new QLabel(tabWidget);
        NaviButton->setObjectName("NaviButton");
        NaviButton->setMinimumSize(QSize(80, 80));
        NaviButton->setMaximumSize(QSize(80, 80));
        NaviButton->setScaledContents(false);
        NaviButton->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(NaviButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        BrowserButton = new QLabel(tabWidget);
        BrowserButton->setObjectName("BrowserButton");
        BrowserButton->setMinimumSize(QSize(80, 80));
        BrowserButton->setMaximumSize(QSize(80, 80));
        BrowserButton->setScaledContents(false);
        BrowserButton->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(BrowserButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        IndexButton = new QLabel(tabWidget);
        IndexButton->setObjectName("IndexButton");
        IndexButton->setMinimumSize(QSize(80, 80));
        IndexButton->setMaximumSize(QSize(80, 80));
        IndexButton->setScaledContents(false);
        IndexButton->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(IndexButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        ChatButton = new QLabel(tabWidget);
        ChatButton->setObjectName("ChatButton");
        ChatButton->setMinimumSize(QSize(80, 80));
        ChatButton->setMaximumSize(QSize(80, 80));
        ChatButton->setScaledContents(false);
        ChatButton->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(ChatButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        MediaButton = new QLabel(tabWidget);
        MediaButton->setObjectName("MediaButton");
        MediaButton->setMinimumSize(QSize(80, 80));
        MediaButton->setMaximumSize(QSize(80, 80));
        MediaButton->setScaledContents(false);
        MediaButton->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(MediaButton);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        SettingButton = new QLabel(tabWidget);
        SettingButton->setObjectName("SettingButton");
        SettingButton->setMinimumSize(QSize(80, 80));
        SettingButton->setMaximumSize(QSize(80, 80));
        SettingButton->setScaledContents(false);
        SettingButton->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(SettingButton);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        mainWidget = new QStackedWidget(Widget);
        mainWidget->setObjectName("mainWidget");
        mainWidget->setGeometry(QRect(140, 10, 1110, 700));
        backButton = new QLabel(Widget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(170, 50, 28, 50));
        backButton->setMinimumSize(QSize(28, 50));
        backButton->setMaximumSize(QSize(28, 50));
        backButton->setPixmap(QPixmap(QString::fromUtf8(":/icons/back.png")));
        backButton->setScaledContents(true);
        backButton->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1190, 20, 50, 50));
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setMaximumSize(QSize(50, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font.setPointSize(20);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(72, 72, 84);\n"
"}"));
        mainWidget->raise();
        tabWidget->raise();
        backButton->raise();
        pushButton->raise();

        retranslateUi(Widget);

        mainWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\350\275\246\350\275\275\344\270\255\346\216\247\347\263\273\347\273\237", nullptr));
        NaviButton->setText(QString());
        BrowserButton->setText(QString());
        IndexButton->setText(QString());
        ChatButton->setText(QString());
        MediaButton->setText(QString());
        SettingButton->setText(QString());
        backButton->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
