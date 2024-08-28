#include "browserwidget.h"
#include "ui_browserwidget.h"
#include<QNetworkProxyFactory>
browserWidget::browserWidget(QWidget *parent, Widget *father)
    : QWidget(parent)
    , ui(new Ui::browserWidget)
    , mainWindow(father)
{
    ui->setupUi(this);
    view = new QWebEngineView(this);
    // view->resize(1000,800);
    // qDebug()<<view->size();
    QNetworkProxyFactory::setUseSystemConfiguration(false);
    ui->verticalLayout_2->addWidget(view);
    view->raise();
    ui->lineEdit->raise();

    view->setUrl(QUrl("https://www.baidu.com/"));

    setGradient(ui->pushButton,QColor(192, 192, 192),QColor(58,58,60),DURATION,"font-size: 20px;");
    setGradient(ui->pushButton_2,QColor(192, 192, 192),QColor(58,58,60),DURATION,"font-size: 20px;");
    setGradient(ui->pushButton_3,QColor(192, 192, 192),QColor(58,58,60),DURATION,"font-size: 20px;");
    setGradient(ui->lineEdit,QColor(192, 192, 192),QColor(58,58,60),DURATION,"font-size: 20px;");

    connect(ui->pushButton, &QPushButton::clicked, view, &QWebEngineView::back);
    connect(ui->pushButton_2, &QPushButton::clicked, view, &QWebEngineView::forward);
    connect(ui->pushButton_3, &QPushButton::clicked, view, &QWebEngineView::reload);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &browserWidget::navigateToUrl);
    connect(view, &QWebEngineView::urlChanged, this, &browserWidget::updateUrl);


}
void browserWidget::setGradient(QWidget *a, QColor start, QColor end, int duration,QString extra)
{
    /* 渐变颜色 */
    ColorGradient *color = new ColorGradient(start, end);
    /* 设置动画 */
    QPropertyAnimation *animation = new QPropertyAnimation(color, "gradient");
    animation->setDuration(duration);
    animation->setStartValue(0);
    animation->setEndValue(1);
    /* 设置hover的事件过滤器 */
    HoverEventfilter* filter = new HoverEventfilter(this, animation);
    a->installEventFilter(filter);

    a->setStyleSheet("background-color:rgba("+
                     QString::number(start.red())+","+
                     QString::number(start.green())+","+
                     QString::number(start.blue())+","+
                     QString::number(start.alpha())+");"+
                     "color:rgba("+
                     QString::number(255-start.red())+","+
                     QString::number(255-start.green())+","+
                     QString::number(255-start.blue())+","+
                     QString::number(start.alpha())+");"+extra);

    /* 将渐变值更改的信号链接上修改颜色的槽 */
    QObject::connect(color, &ColorGradient::gradientChanged, a,
                     [a, color,extra]
                     {
                         a->setStyleSheet("background-color:rgba("+
                                          QString::number(color->getCurrent().red())+","+
                                          QString::number(color->getCurrent().green())+","+
                                          QString::number(color->getCurrent().blue())+","+
                                          QString::number(color->getCurrent().alpha())+");"+
                                          "color:rgba("+
                                          QString::number(255-color->getCurrent().red())+","+
                                          QString::number(255-color->getCurrent().green())+","+
                                          QString::number(255-color->getCurrent().blue())+","+
                                          QString::number(color->getCurrent().alpha())+");"+extra);
                     });
}
browserWidget::~browserWidget()
{
    delete ui;
}

// // 槽函数：导航到地址栏中的网址
void browserWidget::navigateToUrl()
{
    // QString url = ui->lineEdit->text();
    QRegularExpression urlPattern(R"((https?://[^\s/$.?#].[^\s]*)|([www]+\.[^\s/$.?#].[^\s]*))");
    QRegularExpressionMatch match = urlPattern.match(ui->lineEdit->text());
    qDebug()<<"navigateToUrl";
    if(match.hasMatch()){
        QUrl url = QUrl::fromUserInput(ui->lineEdit->text());
        view->setUrl(url);
    }
    else{
        QUrl url = QUrl("https://www.baidu.com/s?ie=UTF-8&wd="+ui->lineEdit->text());
        view->setUrl(url);
    }
        // "https://www.baidu.com/s?ie=UTF-8&wd="
    // QUrl url = QUrl::fromUserInput(ui->lineEdit->text());

}

// 槽函数：更新地址栏中的网址
void browserWidget::updateUrl(const QUrl &url)
{
    qDebug()<<"updateUrl";
    ui->lineEdit->setText(url.toString());
}
void browserWidget::navigateToUrlBySearch(const QString &urlstring){
    qDebug()<<"urlstring";
    QUrl url = QUrl(urlstring);
    view->setUrl(url);
    view->update();
}

void browserWidget::on_pushButton_clicked()
{

}


void browserWidget::on_pushButton_2_clicked()
{

}



void browserWidget::on_pushButton_3_clicked()
{

}

