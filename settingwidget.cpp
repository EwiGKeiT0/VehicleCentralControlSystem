#include "settingwidget.h"
#include "ui_settingwidget.h"

settingWidget::settingWidget(QWidget *parent, Widget *father)
    : QWidget(parent)
    , ui(new Ui::settingWidget)
    , mainWindow(father)
{
    ui->setupUi(this);

    // 设置窗口大小
    setFixedSize(1000, 600);

    // 定义偏移量
    int offsetY = 100;

    // 创建年月日显示的 QLabel
    dateDisplayLabel = new QLabel(this);
    dateDisplayLabel->setGeometry(350, 20 + offsetY - 50, 300, 30);  // 位置 (350, 20 + offsetY), 尺寸 (300, 30)
    dateDisplayLabel->setAlignment(Qt::AlignCenter);  // 居中显示
    dateDisplayLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: white;");

    // 创建显示当前时间的 QLabel
    timeDisplayLabel = new QLabel(this);
    timeDisplayLabel->setGeometry(350, 60 + offsetY - 50, 300, 50);  // 位置 (350, 60 + offsetY), 尺寸 (300, 50)
    timeDisplayLabel->setAlignment(Qt::AlignCenter);  // 居中显示
    timeDisplayLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: white;");

    // 年月日标签
    QLabel *yearLabel = new QLabel("年", this);
    yearLabel->setGeometry(600, 70 + offsetY, 100, 30);  // 位置 (600, 70 + offsetY), 尺寸 (100, 30)
    yearLabel->setAlignment(Qt::AlignCenter);
    yearLabel->setStyleSheet("color: black;");

    QLabel *monthLabel = new QLabel("月", this);
    monthLabel->setGeometry(710, 70 + offsetY, 100, 30);  // 位置 (710, 70 + offsetY), 尺寸 (100, 30)
    monthLabel->setAlignment(Qt::AlignCenter);
    monthLabel->setStyleSheet("color: black;");

    QLabel *dayLabel = new QLabel("日", this);
    dayLabel->setGeometry(820, 70 + offsetY, 100, 30);  // 位置 (820, 70 + offsetY), 尺寸 (100, 30)
    dayLabel->setAlignment(Qt::AlignCenter);
    dayLabel->setStyleSheet("color: black;");

    // 年月日选择器
    yearComboBox = new QComboBox(this);
    for (int i = 2000; i <= 2100; ++i) {
        yearComboBox->addItem(QString::number(i));
    }
    yearComboBox->setCurrentIndex(QDate::currentDate().year() - 2000);
    yearComboBox->setGeometry(600, 100 + offsetY, 100, 50);  // 位置 (600, 100 + offsetY), 尺寸 (100, 50)
    yearComboBox->setStyleSheet("color: black;");

    monthComboBox = new QComboBox(this);
    for (int i = 1; i <= 12; ++i) {
        monthComboBox->addItem(QString::number(i).rightJustified(2, '0'));
    }
    monthComboBox->setCurrentIndex(QDate::currentDate().month() - 1);
    monthComboBox->setGeometry(710, 100 + offsetY, 100, 50);  // 位置 (710, 100 + offsetY), 尺寸 (100, 50)
    monthComboBox->setStyleSheet("color: black;");

    dayComboBox = new QComboBox(this);
    updateDayComboBox();  // 根据当前选择的年和月更新天数
    dayComboBox->setCurrentIndex(QDate::currentDate().day() - 1);
    dayComboBox->setGeometry(820, 100 + offsetY, 100, 50);  // 位置 (820, 100 + offsetY), 尺寸 (100, 50)
    dayComboBox->setStyleSheet("color: black;");

    // 时分秒标签
    QLabel *hourLabel = new QLabel("时", this);
    hourLabel->setGeometry(600, 170 + offsetY, 100, 30);  // 位置 (600, 170 + offsetY), 尺寸 (100, 30)
    hourLabel->setAlignment(Qt::AlignCenter);
    hourLabel->setStyleSheet("color: black;");

    QLabel *minuteLabel = new QLabel("分", this);
    minuteLabel->setGeometry(710, 170 + offsetY, 100, 30);  // 位置 (710, 170 + offsetY), 尺寸 (100, 30)
    minuteLabel->setAlignment(Qt::AlignCenter);
    minuteLabel->setStyleSheet("color: black;");

    QLabel *secondLabel = new QLabel("秒", this);
    secondLabel->setGeometry(820, 170 + offsetY, 100, 30);  // 位置 (820, 170 + offsetY), 尺寸 (100, 30)
    secondLabel->setAlignment(Qt::AlignCenter);
    secondLabel->setStyleSheet("color: black;");

    // 时分秒选择器
    hourComboBox = new QComboBox(this);
    for (int i = 0; i < 24; ++i) {
        hourComboBox->addItem(QString::number(i).rightJustified(2, '0'));
    }
    hourComboBox->setCurrentIndex(QTime::currentTime().hour());
    hourComboBox->setGeometry(600, 200 + offsetY, 100, 50);  // 位置 (600, 200 + offsetY), 尺寸 (100, 50)
    hourComboBox->setStyleSheet("color: black;");

    minuteComboBox = new QComboBox(this);
    for (int i = 0; i < 60; ++i) {
        minuteComboBox->addItem(QString::number(i).rightJustified(2, '0'));
    }
    minuteComboBox->setCurrentIndex(QTime::currentTime().minute());
    minuteComboBox->setGeometry(710, 200 + offsetY, 100, 50);  // 位置 (710, 200 + offsetY), 尺寸 (100, 50)
    minuteComboBox->setStyleSheet("color: black;");

    secondComboBox = new QComboBox(this);
    for (int i = 0; i < 60; ++i) {
        secondComboBox->addItem(QString::number(i).rightJustified(2, '0'));
    }
    secondComboBox->setCurrentIndex(QTime::currentTime().second());
    secondComboBox->setGeometry(820, 200 + offsetY, 100, 50);  // 位置 (820, 200 + offsetY), 尺寸 (100, 50)
    secondComboBox->setStyleSheet("color: black;");

    // 创建设置时间按钮
    setTimeButton = new QPushButton("设置时间", this);
    setTimeButton->setGeometry(600, 270 + offsetY, 120, 50);  // 位置 (600, 270 + offsetY), 尺寸 (120, 50)
    setTimeButton->setStyleSheet("color: white; background-color: black;");

    // 创建时区选择器的 QComboBox
    timezoneComboBox = new QComboBox(this);
    timezoneComboBox->setGeometry(600, 330 + offsetY, 320, 50);  // 位置 (600, 330 + offsetY), 尺寸 (320, 50)
    const auto timeZoneIds = QTimeZone::availableTimeZoneIds();
    for (const QByteArray &zone : timeZoneIds) {
        timezoneComboBox->addItem(QString(zone));
    }
    timezoneComboBox->setCurrentText(QTimeZone::systemTimeZoneId());

    // 创建模式切换按钮，初始文本为 "黑夜模式"
    toggleModeButton = new QPushButton("黑夜模式", this);
    toggleModeButton->setGeometry(750, 270 + offsetY, 120, 50);  // 位置 (750, 270 + offsetY), 尺寸 (120, 50)
    toggleModeButton->setStyleSheet("color: white; background-color: black;");

    // 连接按钮的点击事件
    connect(setTimeButton, &QPushButton::clicked, this, &settingWidget::setTime);
    connect(toggleModeButton, &QPushButton::clicked, this, &settingWidget::toggleMode);  // 连接模式切换按钮
    connect(timezoneComboBox, &QComboBox::currentTextChanged, this, &settingWidget::updateTimeZoneTime);

    // 连接年份和月份的变化事件，动态更新日期选择器的天数
    connect(yearComboBox, &QComboBox::currentTextChanged, this, &settingWidget::updateDayComboBox);
    connect(monthComboBox, &QComboBox::currentTextChanged, this, &settingWidget::updateDayComboBox);

    // 初始化定时器，每秒触发一次更新
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &settingWidget::updateClock);
    timer->start(1000);

    // 初始化时间显示
    updateClock();  // 立即显示当前时间
    emit setTimeButton->clicked();
}

settingWidget::~settingWidget()
{
    delete ui;
}

void settingWidget::setTime()
{
    // 获取用户设置的日期
    userSetDate = QDate(
        yearComboBox->currentText().toInt(),
        monthComboBox->currentText().toInt(),
        dayComboBox->currentText().toInt()
        );

    // 获取用户设置的时间
    userSetTime = QTime::fromString(
        hourComboBox->currentText() + ":" +
            minuteComboBox->currentText() + ":" +
            secondComboBox->currentText(),
        "HH:mm:ss"
        );
    useUserTime = true;  // 标记为手动设置时间

    // 立即触发更新以应用新时间
    update();
}

void settingWidget::updateClock()
{
    if (useUserTime) {
        // 用户手动设置的时间
        userSetTime = userSetTime.addSecs(1);
        currentTime = userSetTime;
    } else {
        // 使用时区时间
        QDateTime utcTime = QDateTime::currentDateTimeUtc();
        QDateTime localTime = utcTime.toTimeZone(currentTimeZone);
        currentTime = localTime.time();
        userSetDate = localTime.date();
    }

    // 在窗口标题中显示当前日期和时间
    QString currentDateTime = userSetDate.toString("yyyy-MM-dd") + " " + currentTime.toString("HH:mm:ss");
    setWindowTitle(currentDateTime);

    // 更新 QLabel 上的时间显示
    timeDisplayLabel->setText(currentTime.toString("HH:mm:ss"));
    dateDisplayLabel->setText(userSetDate.toString("yyyy-MM-dd"));  // 更新年月日显示

    // 触发重绘，确保 paintEvent 被调用
    update();
}

void settingWidget::updateTimeZoneTime()
{
    // 获取新的时区
    currentTimeZone = QTimeZone(timezoneComboBox->currentText().toUtf8());
    useUserTime = false;  // 取消手动设置的时间，切换回时区时间
    updateClock();  // 更新显示
}

void settingWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // 获取窗口大小
    int side = qMin(width() * 0.6, height() * 0.8);  // 调整时钟尺寸以适应布局

    // 设置抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);

    // 调整坐标系，将表盘向下移动
    int offsetY = 50;  // 与其他组件保持一致的偏移量
    painter.translate(width() / 4.0, height() / 2.0 + offsetY);  // 将时钟偏向左侧中间并向下移动
    painter.scale(side / 200.0, side / 200.0);

    // 绘制钟表背景
    painter.setBrush(isNightMode ? Qt::black : Qt::white);  // 根据模式切换背景颜色
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(QPoint(0, 0), 100, 100);

    // 绘制表盘数字
    painter.setPen(isNightMode ? Qt::white : Qt::black);  // 根据模式切换数字颜色
    QFont font = painter.font();
    font.setPointSize(10);  // 调整数字大小
    painter.setFont(font);
    for (int i = 1; i <= 12; ++i) {
        int angle = 30 * i; // 每个数字间隔30度
        int x = 80 * qCos(qDegreesToRadians(angle - 90.0)); // 计算X坐标
        int y = 80 * qSin(qDegreesToRadians(angle - 90.0)); // 计算Y坐标
        QString number = QString::number(i);
        QRect textRect(x - 10, y - 10, 20, 20); // 调整文本框的大小和位置，使数字居中
        painter.drawText(textRect, Qt::AlignCenter, number); // 绘制数字
    }

    // 定义时针、分针和秒针的形状
    static const QPoint hourHand[4] = {
        QPoint(5, 8),
        QPoint(-5, 8),
        QPoint(-2, -50),
        QPoint(2, -50)
    };

    static const QPoint minuteHand[4] = {
        QPoint(4, 8),
        QPoint(-4, 8),
        QPoint(-1, -70),
        QPoint(1, -70)
    };

    static const QPoint secondHand[4] = {
        QPoint(2, 8),
        QPoint(-2, 8),
        QPoint(-1, -90),
        QPoint(1, -90)
    };

    // 设置时针样式
    painter.setBrush(isNightMode ? Qt::white : Qt::black);  // 根据模式切换时针颜色
    painter.setPen(Qt::NoPen);
    painter.save();
    painter.rotate(30.0 * ((currentTime.hour() + currentTime.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 4);
    painter.restore();

    // 设置分针样式
    painter.setBrush(isNightMode ? Qt::gray : Qt::darkGray);  // 根据模式切换分针颜色
    painter.setPen(Qt::NoPen);
    painter.save();
    painter.rotate(6.0 * ((currentTime.minute() + currentTime.second() / 60.0)));
    painter.drawConvexPolygon(minuteHand, 4);
    painter.restore();

    // 设置秒针样式
    painter.setBrush(isNightMode ? Qt::red : Qt::red);  // 秒针颜色保持不变
    painter.setPen(Qt::NoPen);
    painter.save();
    painter.rotate(6.0 * currentTime.second());
    painter.drawConvexPolygon(secondHand, 4);
    painter.restore();

    // 画时钟中心点
    painter.setBrush(isNightMode ? Qt::white : Qt::black);  // 根据模式切换中心点颜色
    painter.drawEllipse(QPoint(0, 0), 5, 5);

    // 画时钟外圈刻度
    painter.setPen(isNightMode ? Qt::white : Qt::black);  // 根据模式切换刻度颜色
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    painter.setPen(isNightMode ? Qt::gray : Qt::gray);  // 小刻度颜色保持不变
    for (int i = 0;  i < 60; ++i) {
        if (i % 5 != 0) {
            painter.drawLine(92, 0, 96, 0);
        }
        painter.rotate(6.0);
    }
}

void settingWidget::toggleMode()
{
    // 切换模式
    isNightMode = !isNightMode;

    // 更新按钮文本
    if (isNightMode) {
        toggleModeButton->setText("日间模式");
    } else {
        toggleModeButton->setText("黑夜模式");
    }

    // 更新窗口颜色，只影响表盘
    update();
}

void settingWidget::updateDayComboBox()
{
    int year = yearComboBox->currentText().toInt();
    int month = monthComboBox->currentText().toInt();
    int daysInMonth = QDate(year, month, 1).daysInMonth();  // 获取该月份的天数

    // 更新 dayComboBox
    dayComboBox->clear();
    for (int i = 1; i <= daysInMonth; ++i) {
        dayComboBox->addItem(QString::number(i).rightJustified(2, '0'));
    }
}
