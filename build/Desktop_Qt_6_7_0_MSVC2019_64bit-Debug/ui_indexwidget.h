/********************************************************************************
** Form generated from reading UI file 'indexwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXWIDGET_H
#define UI_INDEXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_indexWidget
{
public:
    QWidget *mainWidget;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *nameText;
    QSpacerItem *verticalSpacer_8;
    QLabel *infoText;

    void setupUi(QWidget *indexWidget)
    {
        if (indexWidget->objectName().isEmpty())
            indexWidget->setObjectName("indexWidget");
        indexWidget->resize(1110, 700);
        indexWidget->setStyleSheet(QString::fromUtf8("#nameText\n"
"{\n"
"	font-size:28px;\n"
"	color: rgba(200, 200, 200, 1);\n"
"}\n"
"#infoText\n"
"{\n"
"	font-size:15px;\n"
"	color: rgba(200, 200, 200, 1);\n"
"}"));
        mainWidget = new QWidget(indexWidget);
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


        retranslateUi(indexWidget);

        QMetaObject::connectSlotsByName(indexWidget);
    } // setupUi

    void retranslateUi(QWidget *indexWidget)
    {
        indexWidget->setWindowTitle(QCoreApplication::translate("indexWidget", "Form", nullptr));
        nameText->setText(QCoreApplication::translate("indexWidget", "\347\264\242\345\274\225\351\241\265\357\274\237", nullptr));
        infoText->setText(QCoreApplication::translate("indexWidget", "\346\210\221\344\270\215\347\237\245\351\201\223\350\277\231\346\230\257\344\273\200\344\271\210\346\210\221\344\270\215\347\237\245\351\201\223\350\277\231\346\230\257\344\273\200\344\271\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class indexWidget: public Ui_indexWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXWIDGET_H
