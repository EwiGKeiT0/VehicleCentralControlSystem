#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include "widget.h"
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QTimeZone>
#include <QTimer>

namespace Ui {
class settingWidget;
}

class settingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit settingWidget(QWidget *parent = nullptr, Widget *father = nullptr);
    ~settingWidget();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void setTime();
    void updateClock();
    void toggleMode();
    void updateTimeZoneTime();
    void updateDayComboBox();

private:
    Ui::settingWidget *ui;
    Widget *mainWindow;

    // 用户界面元素
    QLabel *dateDisplayLabel;
    QLabel *timeDisplayLabel;

    QComboBox *yearComboBox;
    QComboBox *monthComboBox;
    QComboBox *dayComboBox;
    QComboBox *hourComboBox;
    QComboBox *minuteComboBox;
    QComboBox *secondComboBox;
    QComboBox *timezoneComboBox;

    QPushButton *setTimeButton;
    QPushButton *toggleModeButton;

    // 标签（年、月、日、时、分、秒）
    QLabel *yearLabel;
    QLabel *monthLabel;
    QLabel *dayLabel;
    QLabel *hourLabel;
    QLabel *minuteLabel;
    QLabel *secondLabel;

    // 时间相关
    QTime userSetTime;
    QDate userSetDate;
    QTimeZone currentTimeZone;
    QTime currentTime;
    bool useUserTime;
    bool isNightMode;

    // 定时器
    QTimer *timer;  // 添加定时器声明
};

#endif // SETTINGWIDGET_H
