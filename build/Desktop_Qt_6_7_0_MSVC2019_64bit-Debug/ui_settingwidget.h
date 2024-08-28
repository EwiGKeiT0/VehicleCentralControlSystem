/********************************************************************************
** Form generated from reading UI file 'settingwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWIDGET_H
#define UI_SETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingWidget
{
public:
    QWidget *mainWidget;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *nameText;
    QSpacerItem *verticalSpacer_8;
    QLabel *infoText;

    void setupUi(QWidget *settingWidget)
    {
        if (settingWidget->objectName().isEmpty())
            settingWidget->setObjectName("settingWidget");
        settingWidget->resize(1110, 700);
        settingWidget->setStyleSheet(QString::fromUtf8("#nameText\n"
"{\n"
"	font-size:28px;\n"
"	color: rgba(200, 200, 200, 1);\n"
"}\n"
"#infoText\n"
"{\n"
"	font-size:15px;\n"
"	color: rgba(200, 200, 200, 1);\n"
"}"));
        mainWidget = new QWidget(settingWidget);
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


        retranslateUi(settingWidget);

        QMetaObject::connectSlotsByName(settingWidget);
    } // setupUi

    void retranslateUi(QWidget *settingWidget)
    {
        settingWidget->setWindowTitle(QCoreApplication::translate("settingWidget", "Form", nullptr));
        nameText->setText(QCoreApplication::translate("settingWidget", "\350\256\276\347\275\256", nullptr));
        infoText->setText(QCoreApplication::translate("settingWidget", "\350\277\231\346\230\257\350\256\276\347\275\256\350\277\231\346\230\257\350\256\276\347\275\256\350\277\231\346\230\257\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingWidget: public Ui_settingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWIDGET_H
