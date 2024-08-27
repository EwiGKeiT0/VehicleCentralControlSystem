/********************************************************************************
** Form generated from reading UI file 'naviwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIWIDGET_H
#define UI_NAVIWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "naviwidget.h"
#include "painterwidget.h"

QT_BEGIN_NAMESPACE

class Ui_NaviWidget
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *enlargeBtn;
    QLineEdit *edit_search;
    PainterWidget *mapWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *searchBtn;
    QPushButton *reduceBtn;

    void setupUi(NaviWidget *NaviWidget)
    {
        if (NaviWidget->objectName().isEmpty())
            NaviWidget->setObjectName("NaviWidget");
        NaviWidget->resize(1000, 800);
        centralWidget = new QWidget(NaviWidget);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setGeometry(QRect(0, 0, 1000, 800));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 1001, 801));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        enlargeBtn = new QPushButton(layoutWidget);
        enlargeBtn->setObjectName("enlargeBtn");

        gridLayout->addWidget(enlargeBtn, 0, 2, 1, 1);

        edit_search = new QLineEdit(layoutWidget);
        edit_search->setObjectName("edit_search");

        gridLayout->addWidget(edit_search, 0, 0, 1, 1);

        mapWidget = new PainterWidget(layoutWidget);
        mapWidget->setObjectName("mapWidget");
        pushButton = new QPushButton(mapWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 75, 40));
        pushButton_2 = new QPushButton(mapWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(70, 0, 75, 40));
        lineEdit = new QLineEdit(mapWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(140, 0, 221, 40));

        gridLayout->addWidget(mapWidget, 1, 0, 1, 4);

        searchBtn = new QPushButton(layoutWidget);
        searchBtn->setObjectName("searchBtn");

        gridLayout->addWidget(searchBtn, 0, 1, 1, 1);

        reduceBtn = new QPushButton(layoutWidget);
        reduceBtn->setObjectName("reduceBtn");

        gridLayout->addWidget(reduceBtn, 0, 3, 1, 1);

        gridLayout->setColumnStretch(0, 5);

        retranslateUi(NaviWidget);

        QMetaObject::connectSlotsByName(NaviWidget);
    } // setupUi

    void retranslateUi(NaviWidget *NaviWidget)
    {
        NaviWidget->setWindowTitle(QCoreApplication::translate("NaviWidget", "NaviWidget", nullptr));
        enlargeBtn->setText(QString());
        pushButton->setText(QCoreApplication::translate("NaviWidget", "\351\200\211\346\213\251\350\265\267\347\202\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("NaviWidget", "\351\200\211\346\213\251\347\273\210\347\202\271", nullptr));
        searchBtn->setText(QCoreApplication::translate("NaviWidget", "\346\220\234\347\264\242", nullptr));
        reduceBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NaviWidget: public Ui_NaviWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIWIDGET_H
