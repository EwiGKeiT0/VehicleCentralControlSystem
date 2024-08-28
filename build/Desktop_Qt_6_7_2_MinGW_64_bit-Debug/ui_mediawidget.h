/********************************************************************************
** Form generated from reading UI file 'mediawidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAWIDGET_H
#define UI_MEDIAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaWidget
{
public:
    QWidget *mainWidget;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *nameText;
    QSpacerItem *verticalSpacer_8;
    QLabel *infoText;

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
        mainWidget->setGeometry(QRect(0, 0, 1110, 700));
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

        verticalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_8);

        infoText = new QLabel(infoWidget);
        infoText->setObjectName("infoText");
        sizePolicy.setHeightForWidth(infoText->sizePolicy().hasHeightForWidth());
        infoText->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(infoText);


        verticalLayout->addLayout(verticalLayout_3);


        retranslateUi(mediaWidget);

        QMetaObject::connectSlotsByName(mediaWidget);
    } // setupUi

    void retranslateUi(QWidget *mediaWidget)
    {
        mediaWidget->setWindowTitle(QCoreApplication::translate("mediaWidget", "Form", nullptr));
        nameText->setText(QCoreApplication::translate("mediaWidget", "\345\244\232\345\252\222\344\275\223", nullptr));
        infoText->setText(QCoreApplication::translate("mediaWidget", "\350\277\231\346\230\257\345\244\232\345\252\222\344\275\223\350\277\231\346\230\257\345\244\232\345\252\222\344\275\223\350\277\231\346\230\257\345\244\232\345\252\222\344\275\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediaWidget: public Ui_mediaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAWIDGET_H
