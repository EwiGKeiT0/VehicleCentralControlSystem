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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "naviwidget.h"
#include "painterwidget.h"

QT_BEGIN_NAMESPACE

class Ui_NaviWidget
{
public:
    QWidget *centralWidget;
    QLineEdit *edit_search;
    QTextBrowser *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    PainterWidget *mapWidget;
    QPushButton *enlargeBtn;
    QPushButton *reduceBtn;

    void setupUi(NaviWidget *NaviWidget)
    {
        if (NaviWidget->objectName().isEmpty())
            NaviWidget->setObjectName("NaviWidget");
        NaviWidget->resize(1000, 800);
        NaviWidget->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(NaviWidget);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setGeometry(QRect(0, 0, 1000, 800));
        edit_search = new QLineEdit(centralWidget);
        edit_search->setObjectName("edit_search");
        edit_search->setGeometry(QRect(40, 0, 251, 40));
        lineEdit = new QTextBrowser(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(300, 0, 431, 40));
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(740, 0, 75, 40));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(810, 0, 75, 40));
        mapWidget = new PainterWidget(centralWidget);
        mapWidget->setObjectName("mapWidget");
        mapWidget->setGeometry(QRect(1, 40, 980, 750));
        enlargeBtn = new QPushButton(centralWidget);
        enlargeBtn->setObjectName("enlargeBtn");
        enlargeBtn->setGeometry(QRect(900, 0, 40, 40));
        reduceBtn = new QPushButton(centralWidget);
        reduceBtn->setObjectName("reduceBtn");
        reduceBtn->setGeometry(QRect(940, 0, 40, 40));
        lineEdit->raise();
        pushButton->raise();
        pushButton_2->raise();
        enlargeBtn->raise();
        reduceBtn->raise();
        edit_search->raise();

        retranslateUi(NaviWidget);

        QMetaObject::connectSlotsByName(NaviWidget);
    } // setupUi

    void retranslateUi(NaviWidget *NaviWidget)
    {
        NaviWidget->setWindowTitle(QCoreApplication::translate("NaviWidget", "NaviWidget", nullptr));
        pushButton->setText(QCoreApplication::translate("NaviWidget", "\351\200\211\346\213\251\350\265\267\347\202\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("NaviWidget", "\351\200\211\346\213\251\347\273\210\347\202\271", nullptr));
        enlargeBtn->setText(QCoreApplication::translate("NaviWidget", "\346\224\276\345\244\247", nullptr));
        reduceBtn->setText(QCoreApplication::translate("NaviWidget", "\347\274\251\345\260\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NaviWidget: public Ui_NaviWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIWIDGET_H
