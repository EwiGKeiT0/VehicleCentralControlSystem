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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_indexWidget
{
public:
    QWidget *mainWidget;
    QWidget *infoWidget;
    QLineEdit *searchbox;
    QPushButton *querybutton;
    QLabel *today_date_lab;
    QLabel *parent_lab;
    QLabel *cityname_lab;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *day1_date;
    QLabel *day2_date;
    QLabel *day3_date;
    QLabel *day4_date;
    QLabel *day5_date;
    QLabel *day6_date;
    QLabel *day7_date;
    QVBoxLayout *verticalLayout_4;
    QLabel *day1_pic;
    QLabel *day2_pic;
    QLabel *day3_pic;
    QLabel *day4_pic;
    QLabel *day5_pic;
    QLabel *day6_pic;
    QLabel *day7_pic;
    QVBoxLayout *verticalLayout_3;
    QLabel *day1_t;
    QLabel *day2_t;
    QLabel *day3_t;
    QLabel *day4_t;
    QLabel *day5_t;
    QLabel *day6_t;
    QLabel *day7_t;
    QLabel *weizhi_label;
    QWidget *chartwidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *today_lab2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *wet_icon;
    QVBoxLayout *verticalLayout_10;
    QLabel *lbShiDuTitle;
    QLabel *wet_lab;
    QHBoxLayout *horizontalLayout_10;
    QLabel *quality_icon;
    QVBoxLayout *verticalLayout_11;
    QLabel *lblQualityTitle;
    QLabel *quality_lab;
    QHBoxLayout *horizontalLayout_8;
    QLabel *pm25_icon;
    QVBoxLayout *verticalLayout_9;
    QLabel *lbPm25Title;
    QLabel *pm25_lab;
    QHBoxLayout *horizontalLayout;
    QLabel *wind_icon;
    QVBoxLayout *verticalLayout_2;
    QLabel *wind_dir_lab;
    QLabel *wind_grade;
    QWidget *today_lab1;
    QGridLayout *gridLayout_2;
    QLabel *today_temp_lab;
    QLabel *today_type_lab;
    QLabel *today_hlt_lab;
    QLabel *today_pic_lab;
    QPushButton *location;

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
        mainWidget->setGeometry(QRect(-1, -40, 1211, 700));
        mainWidget->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color:rgba(0,0,0,0);\n"
"}"));
        infoWidget = new QWidget(mainWidget);
        infoWidget->setObjectName("infoWidget");
        infoWidget->setGeometry(QRect(120, 110, 1051, 611));
        searchbox = new QLineEdit(infoWidget);
        searchbox->setObjectName("searchbox");
        searchbox->setGeometry(QRect(10, 10, 701, 51));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        searchbox->setFont(font);
        searchbox->setStyleSheet(QString::fromUtf8("border-radius:25px;\n"
"color:white;"));
        searchbox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        querybutton = new QPushButton(infoWidget);
        querybutton->setObjectName("querybutton");
        querybutton->setGeometry(QRect(730, 10, 51, 51));
        querybutton->setMaximumSize(QSize(519, 16777215));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        querybutton->setFont(font1);
        querybutton->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 80, 99);\n"
"border-radius:25px;\n"
""));
        today_date_lab = new QLabel(infoWidget);
        today_date_lab->setObjectName("today_date_lab");
        today_date_lab->setGeometry(QRect(40, 120, 101, 20));
        QFont font2;
        font2.setPointSize(10);
        today_date_lab->setFont(font2);
        today_date_lab->setStyleSheet(QString::fromUtf8("color: white;"));
        parent_lab = new QLabel(infoWidget);
        parent_lab->setObjectName("parent_lab");
        parent_lab->setGeometry(QRect(40, 80, 111, 31));
        QFont font3;
        font3.setPointSize(20);
        parent_lab->setFont(font3);
        parent_lab->setStyleSheet(QString::fromUtf8("color: white;"));
        parent_lab->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        cityname_lab = new QLabel(infoWidget);
        cityname_lab->setObjectName("cityname_lab");
        cityname_lab->setGeometry(QRect(160, 80, 91, 41));
        QFont font4;
        font4.setPointSize(15);
        cityname_lab->setFont(font4);
        cityname_lab->setStyleSheet(QString::fromUtf8("color: white;"));
        gridWidget = new QWidget(infoWidget);
        gridWidget->setObjectName("gridWidget");
        gridWidget->setGeometry(QRect(457, 120, 381, 451));
        gridWidget->setStyleSheet(QString::fromUtf8("background-color:rgb(31, 39, 53);\n"
"border-radius: 15px"));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        day1_date = new QLabel(gridWidget);
        day1_date->setObjectName("day1_date");
        QFont font5;
        font5.setPointSize(20);
        font5.setBold(false);
        day1_date->setFont(font5);
        day1_date->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color:rgb(31, 39, 53);\n"
"border-radius:0px;"));
        day1_date->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(day1_date);

        day2_date = new QLabel(gridWidget);
        day2_date->setObjectName("day2_date");
        day2_date->setFont(font3);
        day2_date->setStyleSheet(QString::fromUtf8("background-color:rgb(31, 39, 53);color: white;\n"
"border-radius:0;"));
        day2_date->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(day2_date);

        day3_date = new QLabel(gridWidget);
        day3_date->setObjectName("day3_date");
        day3_date->setFont(font3);
        day3_date->setStyleSheet(QString::fromUtf8("border-radius:0;background-color:rgb(31, 39, 53);color: white;"));
        day3_date->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(day3_date);

        day4_date = new QLabel(gridWidget);
        day4_date->setObjectName("day4_date");
        day4_date->setFont(font3);
        day4_date->setStyleSheet(QString::fromUtf8("border-radius:0;background-color:rgb(31, 39, 53);color: white;"));
        day4_date->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(day4_date);

        day5_date = new QLabel(gridWidget);
        day5_date->setObjectName("day5_date");
        day5_date->setFont(font3);
        day5_date->setStyleSheet(QString::fromUtf8("background-color:rgb(31, 39, 53);color: white;\n"
"border-radius:0;"));
        day5_date->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(day5_date);

        day6_date = new QLabel(gridWidget);
        day6_date->setObjectName("day6_date");
        day6_date->setFont(font3);
        day6_date->setStyleSheet(QString::fromUtf8("background-color:rgb(31, 39, 53);color: white;\n"
"border-radius:0;"));

        verticalLayout->addWidget(day6_date, 0, Qt::AlignmentFlag::AlignHCenter);

        day7_date = new QLabel(gridWidget);
        day7_date->setObjectName("day7_date");
        day7_date->setFont(font3);
        day7_date->setStyleSheet(QString::fromUtf8("background-color:rgb(31, 39, 53);color: white;\n"
"border-radius:0;"));
        day7_date->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(day7_date);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        day1_pic = new QLabel(gridWidget);
        day1_pic->setObjectName("day1_pic");
        day1_pic->setFont(font3);
        day1_pic->setStyleSheet(QString::fromUtf8("border-radius:0;\n"
"background-color:rgb(31, 39, 53);color: white;"));
        day1_pic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(day1_pic);

        day2_pic = new QLabel(gridWidget);
        day2_pic->setObjectName("day2_pic");
        day2_pic->setFont(font3);
        day2_pic->setStyleSheet(QString::fromUtf8("border-radius:0;background-color:rgb(31, 39, 53);color: white;"));
        day2_pic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(day2_pic);

        day3_pic = new QLabel(gridWidget);
        day3_pic->setObjectName("day3_pic");
        day3_pic->setFont(font3);
        day3_pic->setStyleSheet(QString::fromUtf8("border-radius:0;background-color:rgb(31, 39, 53);color: white;"));
        day3_pic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(day3_pic);

        day4_pic = new QLabel(gridWidget);
        day4_pic->setObjectName("day4_pic");
        day4_pic->setFont(font3);
        day4_pic->setStyleSheet(QString::fromUtf8("border-radius:0;background-color:rgb(31, 39, 53);color: white;"));

        verticalLayout_4->addWidget(day4_pic, 0, Qt::AlignmentFlag::AlignHCenter);

        day5_pic = new QLabel(gridWidget);
        day5_pic->setObjectName("day5_pic");
        day5_pic->setFont(font3);
        day5_pic->setStyleSheet(QString::fromUtf8("border-radius:0;\n"
"background-color:rgb(31, 39, 53);color: white;"));

        verticalLayout_4->addWidget(day5_pic, 0, Qt::AlignmentFlag::AlignHCenter);

        day6_pic = new QLabel(gridWidget);
        day6_pic->setObjectName("day6_pic");
        day6_pic->setFont(font3);
        day6_pic->setStyleSheet(QString::fromUtf8("border-radius:0;\n"
"background-color:rgb(31, 39, 53);color: white;"));

        verticalLayout_4->addWidget(day6_pic, 0, Qt::AlignmentFlag::AlignHCenter);

        day7_pic = new QLabel(gridWidget);
        day7_pic->setObjectName("day7_pic");
        day7_pic->setFont(font3);
        day7_pic->setStyleSheet(QString::fromUtf8("background-color:rgb(31, 39, 53);color: white;\n"
"border-radius:0;"));
        day7_pic->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(day7_pic);


        gridLayout->addLayout(verticalLayout_4, 0, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        day1_t = new QLabel(gridWidget);
        day1_t->setObjectName("day1_t");
        day1_t->setFont(font4);
        day1_t->setStyleSheet(QString::fromUtf8("color: white;\n"
"background-color:rgb(31, 39, 53);\n"
"border-radius:0;"));
        day1_t->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_3->addWidget(day1_t);

        day2_t = new QLabel(gridWidget);
        day2_t->setObjectName("day2_t");
        day2_t->setFont(font4);
        day2_t->setStyleSheet(QString::fromUtf8("border-radius:0;background-color:rgb(31, 39, 53);color: white;"));
        day2_t->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_3->addWidget(day2_t);

        day3_t = new QLabel(gridWidget);
        day3_t->setObjectName("day3_t");
        QFont font6;
        font6.setPointSize(15);
        font6.setBold(false);
        day3_t->setFont(font6);
        day3_t->setStyleSheet(QString::fromUtf8("border-radius:0;background-color:rgb(31, 39, 53);color: white;"));
        day3_t->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_3->addWidget(day3_t);

        day4_t = new QLabel(gridWidget);
        day4_t->setObjectName("day4_t");
        day4_t->setFont(font4);
        day4_t->setStyleSheet(QString::fromUtf8("border-radius:0;background-color:rgb(31, 39, 53);color: white;"));
        day4_t->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_3->addWidget(day4_t);

        day5_t = new QLabel(gridWidget);
        day5_t->setObjectName("day5_t");
        day5_t->setFont(font4);
        day5_t->setStyleSheet(QString::fromUtf8("border-radius:0;background-color:rgb(31, 39, 53);color: white;"));
        day5_t->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_3->addWidget(day5_t);

        day6_t = new QLabel(gridWidget);
        day6_t->setObjectName("day6_t");
        day6_t->setFont(font4);
        day6_t->setStyleSheet(QString::fromUtf8("border-radius:0;background-color:rgb(31, 39, 53);color: white;"));

        verticalLayout_3->addWidget(day6_t, 0, Qt::AlignmentFlag::AlignLeft);

        day7_t = new QLabel(gridWidget);
        day7_t->setObjectName("day7_t");
        day7_t->setFont(font4);
        day7_t->setStyleSheet(QString::fromUtf8("background-color:rgb(31, 39, 53);color: white;\n"
"border-radius:0;"));

        verticalLayout_3->addWidget(day7_t);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        weizhi_label = new QLabel(infoWidget);
        weizhi_label->setObjectName("weizhi_label");
        weizhi_label->setGeometry(QRect(10, 90, 31, 21));
        chartwidget = new QWidget(infoWidget);
        chartwidget->setObjectName("chartwidget");
        chartwidget->setGeometry(QRect(20, 370, 391, 201));
        chartwidget->setStyleSheet(QString::fromUtf8("background-color:rgb(72, 72, 84);\n"
"border-radius: 5px"));
        verticalLayout_5 = new QVBoxLayout(chartwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        today_lab2 = new QWidget(infoWidget);
        today_lab2->setObjectName("today_lab2");
        today_lab2->setGeometry(QRect(21, 266, 391, 101));
        today_lab2->setStyleSheet(QString::fromUtf8("background-color:rgb(72, 72, 84);\n"
"border-radius: 5px"));
        gridLayout_3 = new QGridLayout(today_lab2);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        wet_icon = new QLabel(today_lab2);
        wet_icon->setObjectName("wet_icon");
        wet_icon->setMinimumSize(QSize(40, 40));
        wet_icon->setMaximumSize(QSize(40, 40));
        wet_icon->setFont(font2);
        wet_icon->setPixmap(QPixmap(QString::fromUtf8(":/res/humidity.png")));
        wet_icon->setScaledContents(true);

        horizontalLayout_9->addWidget(wet_icon);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        lbShiDuTitle = new QLabel(today_lab2);
        lbShiDuTitle->setObjectName("lbShiDuTitle");
        lbShiDuTitle->setFont(font2);
        lbShiDuTitle->setStyleSheet(QString::fromUtf8("color:white;"));
        lbShiDuTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(lbShiDuTitle);

        wet_lab = new QLabel(today_lab2);
        wet_lab->setObjectName("wet_lab");
        wet_lab->setFont(font2);
        wet_lab->setStyleSheet(QString::fromUtf8("color:white;"));
        wet_lab->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(wet_lab);


        horizontalLayout_9->addLayout(verticalLayout_10);


        gridLayout_3->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        quality_icon = new QLabel(today_lab2);
        quality_icon->setObjectName("quality_icon");
        quality_icon->setMinimumSize(QSize(40, 40));
        quality_icon->setMaximumSize(QSize(40, 40));
        quality_icon->setFont(font2);
        quality_icon->setPixmap(QPixmap(QString::fromUtf8(":/res/aqi.png")));
        quality_icon->setScaledContents(true);

        horizontalLayout_10->addWidget(quality_icon);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        lblQualityTitle = new QLabel(today_lab2);
        lblQualityTitle->setObjectName("lblQualityTitle");
        lblQualityTitle->setFont(font2);
        lblQualityTitle->setStyleSheet(QString::fromUtf8("color:white;"));
        lblQualityTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_11->addWidget(lblQualityTitle);

        quality_lab = new QLabel(today_lab2);
        quality_lab->setObjectName("quality_lab");
        quality_lab->setFont(font2);
        quality_lab->setStyleSheet(QString::fromUtf8("color:white;"));
        quality_lab->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_11->addWidget(quality_lab);


        horizontalLayout_10->addLayout(verticalLayout_11);


        gridLayout_3->addLayout(horizontalLayout_10, 1, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        pm25_icon = new QLabel(today_lab2);
        pm25_icon->setObjectName("pm25_icon");
        pm25_icon->setMinimumSize(QSize(40, 40));
        pm25_icon->setMaximumSize(QSize(40, 40));
        pm25_icon->setFont(font2);
        pm25_icon->setPixmap(QPixmap(QString::fromUtf8(":/res/pm25.png")));
        pm25_icon->setScaledContents(true);

        horizontalLayout_8->addWidget(pm25_icon);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        lbPm25Title = new QLabel(today_lab2);
        lbPm25Title->setObjectName("lbPm25Title");
        lbPm25Title->setFont(font2);
        lbPm25Title->setStyleSheet(QString::fromUtf8("color:white;"));
        lbPm25Title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_9->addWidget(lbPm25Title);

        pm25_lab = new QLabel(today_lab2);
        pm25_lab->setObjectName("pm25_lab");
        pm25_lab->setFont(font2);
        pm25_lab->setStyleSheet(QString::fromUtf8("color:white;"));
        pm25_lab->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_9->addWidget(pm25_lab);


        horizontalLayout_8->addLayout(verticalLayout_9);


        gridLayout_3->addLayout(horizontalLayout_8, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        wind_icon = new QLabel(today_lab2);
        wind_icon->setObjectName("wind_icon");
        wind_icon->setMinimumSize(QSize(40, 40));
        wind_icon->setMaximumSize(QSize(40, 40));
        wind_icon->setFont(font2);
        wind_icon->setPixmap(QPixmap(QString::fromUtf8(":/res/wind.png")));
        wind_icon->setScaledContents(true);

        horizontalLayout->addWidget(wind_icon);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        wind_dir_lab = new QLabel(today_lab2);
        wind_dir_lab->setObjectName("wind_dir_lab");
        wind_dir_lab->setFont(font2);
        wind_dir_lab->setStyleSheet(QString::fromUtf8("color:white;"));
        wind_dir_lab->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(wind_dir_lab);

        wind_grade = new QLabel(today_lab2);
        wind_grade->setObjectName("wind_grade");
        wind_grade->setFont(font2);
        wind_grade->setStyleSheet(QString::fromUtf8("color:white;"));
        wind_grade->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(wind_grade);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        today_lab1 = new QWidget(infoWidget);
        today_lab1->setObjectName("today_lab1");
        today_lab1->setGeometry(QRect(21, 151, 391, 111));
        today_lab1->setStyleSheet(QString::fromUtf8("background-color:rgb(72, 72, 84);\n"
"border-radius: 5px"));
        gridLayout_2 = new QGridLayout(today_lab1);
        gridLayout_2->setObjectName("gridLayout_2");
        today_temp_lab = new QLabel(today_lab1);
        today_temp_lab->setObjectName("today_temp_lab");
        QFont font7;
        font7.setPointSize(35);
        today_temp_lab->setFont(font7);
        today_temp_lab->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout_2->addWidget(today_temp_lab, 0, 0, 1, 2, Qt::AlignmentFlag::AlignHCenter);

        today_type_lab = new QLabel(today_lab1);
        today_type_lab->setObjectName("today_type_lab");
        today_type_lab->setFont(font4);
        today_type_lab->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout_2->addWidget(today_type_lab, 1, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        today_hlt_lab = new QLabel(today_lab1);
        today_hlt_lab->setObjectName("today_hlt_lab");
        today_hlt_lab->setFont(font4);
        today_hlt_lab->setStyleSheet(QString::fromUtf8("color: white;"));

        gridLayout_2->addWidget(today_hlt_lab, 1, 1, 1, 2, Qt::AlignmentFlag::AlignHCenter);

        today_pic_lab = new QLabel(today_lab1);
        today_pic_lab->setObjectName("today_pic_lab");

        gridLayout_2->addWidget(today_pic_lab, 0, 2, 1, 1);

        location = new QPushButton(infoWidget);
        location->setObjectName("location");
        location->setGeometry(QRect(800, 10, 121, 51));
        location->setMaximumSize(QSize(519, 16777215));
        location->setFont(font);
        location->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 80, 99);\n"
"border-radius:15px;\n"
"color:white;\n"
"\n"
""));

        retranslateUi(indexWidget);

        QMetaObject::connectSlotsByName(indexWidget);
    } // setupUi

    void retranslateUi(QWidget *indexWidget)
    {
        indexWidget->setWindowTitle(QCoreApplication::translate("indexWidget", "Form", nullptr));
        querybutton->setText(QString());
        today_date_lab->setText(QCoreApplication::translate("indexWidget", "2024\345\271\26408\346\234\21020\346\227\245", nullptr));
        parent_lab->setText(QCoreApplication::translate("indexWidget", "\345\214\227\344\272\254\345\270\202", nullptr));
        cityname_lab->setText(QCoreApplication::translate("indexWidget", "\346\210\277\345\261\261", nullptr));
        day1_date->setText(QCoreApplication::translate("indexWidget", "\346\230\216\345\244\251", nullptr));
        day2_date->setText(QCoreApplication::translate("indexWidget", "08/23", nullptr));
        day3_date->setText(QCoreApplication::translate("indexWidget", "08/24", nullptr));
        day4_date->setText(QCoreApplication::translate("indexWidget", "08/25", nullptr));
        day5_date->setText(QCoreApplication::translate("indexWidget", "08/26", nullptr));
        day6_date->setText(QCoreApplication::translate("indexWidget", "08/27", nullptr));
        day7_date->setText(QCoreApplication::translate("indexWidget", "08/28", nullptr));
        day1_pic->setText(QCoreApplication::translate("indexWidget", "TextLabel", nullptr));
        day2_pic->setText(QCoreApplication::translate("indexWidget", "TextLabel", nullptr));
        day3_pic->setText(QCoreApplication::translate("indexWidget", "TextLabel", nullptr));
        day4_pic->setText(QCoreApplication::translate("indexWidget", "TextLabel", nullptr));
        day5_pic->setText(QCoreApplication::translate("indexWidget", "TextLabel", nullptr));
        day6_pic->setText(QCoreApplication::translate("indexWidget", "TextLabel", nullptr));
        day7_pic->setText(QCoreApplication::translate("indexWidget", "TextLabel", nullptr));
        day1_t->setText(QCoreApplication::translate("indexWidget", "17-21\302\260C  \345\244\232\344\272\221", nullptr));
        day2_t->setText(QCoreApplication::translate("indexWidget", "17-21\302\260C \346\231\264", nullptr));
        day3_t->setText(QCoreApplication::translate("indexWidget", "17-21\302\260C \351\230\264\345\244\251", nullptr));
        day4_t->setText(QCoreApplication::translate("indexWidget", "17-21\302\260C \345\260\217\351\233\250", nullptr));
        day5_t->setText(QCoreApplication::translate("indexWidget", "17-21\302\260C \344\270\255\351\233\250", nullptr));
        day6_t->setText(QCoreApplication::translate("indexWidget", "17-21\302\260C \344\270\255\351\233\250", nullptr));
        day7_t->setText(QCoreApplication::translate("indexWidget", "17-21\302\260C \344\270\255\351\233\250", nullptr));
        weizhi_label->setText(QString());
        wet_icon->setText(QString());
        lbShiDuTitle->setText(QCoreApplication::translate("indexWidget", "\346\271\277\345\272\246", nullptr));
        wet_lab->setText(QCoreApplication::translate("indexWidget", "60%", nullptr));
        quality_icon->setText(QString());
        lblQualityTitle->setText(QCoreApplication::translate("indexWidget", "\347\251\272\346\260\224\350\264\250\351\207\217", nullptr));
        quality_lab->setText(QCoreApplication::translate("indexWidget", "\344\274\230", nullptr));
        pm25_icon->setText(QString());
        lbPm25Title->setText(QCoreApplication::translate("indexWidget", "PM2.5", nullptr));
        pm25_lab->setText(QCoreApplication::translate("indexWidget", "10", nullptr));
        wind_icon->setText(QString());
        wind_dir_lab->setText(QCoreApplication::translate("indexWidget", "\350\245\277\345\214\227\351\243\216", nullptr));
        wind_grade->setText(QCoreApplication::translate("indexWidget", "1\347\272\247", nullptr));
        today_temp_lab->setText(QCoreApplication::translate("indexWidget", "32\342\204\203", nullptr));
        today_type_lab->setText(QCoreApplication::translate("indexWidget", "\346\231\264\345\244\251", nullptr));
        today_hlt_lab->setText(QCoreApplication::translate("indexWidget", "19\342\204\203~32\342\204\203", nullptr));
        today_pic_lab->setText(QString());
        location->setText(QCoreApplication::translate("indexWidget", "\346\237\245\350\257\242\346\211\200\345\234\250\345\237\216\345\270\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class indexWidget: public Ui_indexWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXWIDGET_H
