/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCheckBox *checkBox;
    QTextEdit *textEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(290, 90, 80, 19));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(180, 180, 201, 101));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(180, 90, 91, 21));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_2 = new QCheckBox(widget);
        checkBox_2->setObjectName("checkBox_2");

        horizontalLayout->addWidget(checkBox_2);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(180, 130, 198, 21));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(widget1);
        radioButton->setObjectName("radioButton");

        horizontalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget1);
        radioButton_2->setObjectName("radioButton_2");

        horizontalLayout_2->addWidget(radioButton_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
