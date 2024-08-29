/********************************************************************************
** Form generated from reading UI file 'mediawidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAWIDGET_H
#define UI_MEDIAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaWidget
{
public:
    QWidget *mainWidget;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLabel *rightButton;
    QLabel *photoLabel;
    QLabel *pictureEntry;
    QLabel *albumCoverLabel;
    QLabel *leftButton;
    QLabel *backButton;
    QLabel *musicEntry;
    QLabel *NameText;
    QLabel *videoEntry;
    QLabel *playButton;
    QLabel *InfoText;
    QLabel *addFileButton;
    QLabel *flowEntry;
    QLabel *flowRenderer;
    QLineEdit *flowInput;
    QPushButton *flowStart;
    QPushButton *flowStop;

    void setupUi(QWidget *mediaWidget)
    {
        if (mediaWidget->objectName().isEmpty())
            mediaWidget->setObjectName("mediaWidget");
        mediaWidget->resize(1110, 700);
        mediaWidget->setStyleSheet(QString::fromUtf8("#nameText\n"
"{\n"
"	font-size:28px;\n"
"	color: rgba(200, 200, 200, 1);\n"
"}\n"
"#infoText\n"
"{\n"
"	font-size:15px;\n"
"	color: rgba(200, 200, 200, 1);\n"
"}"));
        mainWidget = new QWidget(mediaWidget);
        mainWidget->setObjectName("mainWidget");
        mainWidget->setGeometry(QRect(40, -50, 1110, 700));
        mainWidget->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color:rgba(0,0,0,0);\n"
"}"));
        infoWidget = new QWidget(mainWidget);
        infoWidget->setObjectName("infoWidget");
        infoWidget->setGeometry(QRect(90, 20, 250, 121));
        verticalLayout = new QVBoxLayout(infoWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(mainWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(30, 100, 256, 192));
        rightButton = new QLabel(mainWidget);
        rightButton->setObjectName("rightButton");
        rightButton->setGeometry(QRect(620, 250, 69, 19));
        photoLabel = new QLabel(mainWidget);
        photoLabel->setObjectName("photoLabel");
        photoLabel->setGeometry(QRect(620, 320, 40, 12));
        pictureEntry = new QLabel(mainWidget);
        pictureEntry->setObjectName("pictureEntry");
        pictureEntry->setGeometry(QRect(170, 600, 101, 19));
        albumCoverLabel = new QLabel(mainWidget);
        albumCoverLabel->setObjectName("albumCoverLabel");
        albumCoverLabel->setGeometry(QRect(620, 280, 69, 19));
        leftButton = new QLabel(mainWidget);
        leftButton->setObjectName("leftButton");
        leftButton->setGeometry(QRect(620, 190, 81, 19));
        backButton = new QLabel(mainWidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(210, 210, 91, 19));
        musicEntry = new QLabel(mainWidget);
        musicEntry->setObjectName("musicEntry");
        musicEntry->setGeometry(QRect(170, 540, 101, 19));
        NameText = new QLabel(mainWidget);
        NameText->setObjectName("NameText");
        NameText->setGeometry(QRect(220, 140, 69, 19));
        videoEntry = new QLabel(mainWidget);
        videoEntry->setObjectName("videoEntry");
        videoEntry->setGeometry(QRect(170, 570, 91, 19));
        playButton = new QLabel(mainWidget);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(620, 220, 69, 19));
        InfoText = new QLabel(mainWidget);
        InfoText->setObjectName("InfoText");
        InfoText->setGeometry(QRect(220, 160, 61, 20));
        addFileButton = new QLabel(mainWidget);
        addFileButton->setObjectName("addFileButton");
        addFileButton->setGeometry(QRect(610, 580, 151, 19));
        flowEntry = new QLabel(mainWidget);
        flowEntry->setObjectName("flowEntry");
        flowEntry->setGeometry(QRect(590, 250, 71, 31));
        flowRenderer = new QLabel(mainWidget);
        flowRenderer->setObjectName("flowRenderer");
        flowRenderer->setGeometry(QRect(460, 360, 69, 19));
        flowInput = new QLineEdit(mainWidget);
        flowInput->setObjectName("flowInput");
        flowInput->setGeometry(QRect(450, 470, 113, 25));
        flowStart = new QPushButton(mainWidget);
        flowStart->setObjectName("flowStart");
        flowStart->setGeometry(QRect(660, 320, 93, 28));
        flowStop = new QPushButton(mainWidget);
        flowStop->setObjectName("flowStop");
        flowStop->setGeometry(QRect(680, 400, 93, 28));

        retranslateUi(mediaWidget);

        QMetaObject::connectSlotsByName(mediaWidget);
    } // setupUi

    void retranslateUi(QWidget *mediaWidget)
    {
        mediaWidget->setWindowTitle(QCoreApplication::translate("mediaWidget", "Form", nullptr));
        rightButton->setText(QString());
        photoLabel->setText(QString());
        pictureEntry->setText(QCoreApplication::translate("mediaWidget", "pictureEntry", nullptr));
        albumCoverLabel->setText(QString());
        leftButton->setText(QString());
        backButton->setText(QCoreApplication::translate("mediaWidget", "BackButton", nullptr));
        musicEntry->setText(QCoreApplication::translate("mediaWidget", "musicEntry", nullptr));
        NameText->setText(QCoreApplication::translate("mediaWidget", "\346\234\252\347\237\245\346\255\214\346\233\262", nullptr));
        videoEntry->setText(QCoreApplication::translate("mediaWidget", "vedioEntry", nullptr));
        playButton->setText(QString());
        InfoText->setText(QCoreApplication::translate("mediaWidget", "\346\234\252\347\237\245\344\277\241\346\201\257", nullptr));
        addFileButton->setText(QCoreApplication::translate("mediaWidget", "                 + Choose File", nullptr));
        flowEntry->setText(QCoreApplication::translate("mediaWidget", "flowEntry", nullptr));
        flowRenderer->setText(QCoreApplication::translate("mediaWidget", "flowRenderer", nullptr));
        flowInput->setText(QCoreApplication::translate("mediaWidget", "\350\257\267\350\276\223\345\205\245\347\275\221\345\235\200", nullptr));
        flowStart->setText(QCoreApplication::translate("mediaWidget", "\345\274\200\345\247\213", nullptr));
        flowStop->setText(QCoreApplication::translate("mediaWidget", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediaWidget: public Ui_mediaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAWIDGET_H
