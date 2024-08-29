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
     manager = new QNetworkAccessManager(this);

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
    connect(this, &browserWidget::messageReceived, this->view, &QWebEngineView::setUrl);

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
        QRegularExpression regex("^\\$(.*)\\$$");

        // 匹配正则表达式
        match = regex.match(ui->lineEdit->text());

        // 如果匹配成功，提取中间的内容
        if (match.hasMatch()) {
            sendMessageToLLM(manager,match.captured(1)); // 提取括号内的内容，即除开头结尾外的内容
        } else {
            QUrl url = QUrl("https://www.baidu.com/s?ie=UTF-8&wd="+ui->lineEdit->text());
            view->setUrl(url);
        }
    }

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
void browserWidget::sendMessageToLLM(QNetworkAccessManager *manager, QString question) {
    // 设置你的 DashScope API Key
    QString apiKey = "sk-7a2a9ad8ad06460ea13b61f31d73101f";

    // API 端点
    QUrl url("https://dashscope.aliyuncs.com/compatible-mode/v1/chat/completions");

    // 创建请求
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());

    // 创建请求数据
    QJsonObject systemMessage{
        {"role", "system"},
        {"content", "You are a helpful assistant. You should always answer questions by a single link which leads to correct website."}
    };

    QJsonObject userMessage{
        {"role", "user"},
        {"content", "请直接使用一个网址回答我的问题，保证网址是中国的合法网站.如果问题与天气相关，请直接回答以\"http://t.weather.itboy.net/api/weather/city/\""
                    "开始，后跟表示城市的九位整数的网址，如http://t.weather.itboy.net/api/weather/city/101011000.城市代码如下:"+QString(R"(
{
  "citys": [
    {
      "city": "北京",
      "code": "101010100"
    },
    {
      "city": "朝阳",
      "code": "101010300"
    },
    {
      "city": "顺义",
      "code": "101010400"
    },
    {
      "city": "怀柔",
      "code": "101010500"
    },
    {
      "city": "通州",
      "code": "101010600"
    },
    {
      "city": "昌平",
      "code": "101010700"
    },
    {
      "city": "延庆",
      "code": "101010800"
    },
    {
      "city": "丰台",
      "code": "101010900"
    },
    {
      "city": "石景山",
      "code": "101011000"
    },
    {
      "city": "大兴",
      "code": "101011100"
    },
    {
      "city": "房山",
      "code": "101011200"
    },
    {
      "city": "密云",
      "code": "101011300"
    },
    {
      "city": "门头沟",
      "code": "101011400"
    },
    {
      "city": "平谷",
      "code": "101011500"
    },
    {
      "city": "八达岭",
      "code": "101011600"
    },
    {
      "city": "佛爷顶",
      "code": "101011700"
    },
    {
      "city": "汤河口",
      "code": "101011800"
    },
    {
      "city": "密云上甸子",
      "code": "101011900"
    },
    {
      "city": "斋堂",
      "code": "101012000"
    },
    {
      "city": "霞云岭",
      "code": "101012100"
    },
    {
      "city": "北京城区",
      "code": "101012200"
    },
    {
      "city": "海淀",
      "code": "101010200"
    }
  ]
})")+QString(R"(如果和视频相关，则根据主题直接输出一个可以在线上传并播放 .mp4 视频文件的直接网址。该网站必须以.mp4结尾。例子:主题和海洋相关时，直接输出http://vjs.zencdn.net/v/oceans.mp4 .视频和母亲相关，输出http://mirror.aarnet.edu.au/pub/TED-talks/911Mothers_2010W-480p.mp4.保证网址以.mp4结尾，内容可播放)")+"下面是我的问题:" + question}
    };

    QJsonArray messagesArray;
    messagesArray.append(systemMessage);
    messagesArray.append(userMessage);

    QJsonObject requestBody{
        {"model", "qwen-turbo"},
        {"messages", messagesArray}
    };

    QJsonDocument jsonDoc(requestBody);
    QByteArray postData = jsonDoc.toJson();

    // 发送请求
    QNetworkReply *reply = manager->post(request, postData);

    // 处理响应
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        QString result = "https://www.baidu.com";
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response_data = reply->readAll();
            qDebug() << QString(response_data);

            QJsonDocument jsonDoc = QJsonDocument::fromJson(response_data);

            if (!jsonDoc.isNull() && jsonDoc.isObject()) {
                QJsonObject jsonObj = jsonDoc.object();

                // 获取 "choices" 数组
                QJsonArray choicesArray = jsonObj.value("choices").toArray();
                if (!choicesArray.isEmpty()) {
                    QJsonObject firstChoice = choicesArray.at(0).toObject();

                    // 获取 "message" 对象
                    QJsonObject messageObj = firstChoice.value("message").toObject();

                    // 获取 "content" 字符串
                    QString content = messageObj.value("content").toString();
                    qDebug() << "Content:" << content; // 输出 content
                    result = content;
                }
            }
        } else {
            qDebug() << "Request failed:" << reply->errorString();
        }
        MessageFilter(result);
        // emit messageReceived(result); // 发射信号传递结果
        reply->deleteLater(); // 释放资源
    });
}
void browserWidget::MessageFilter(const QString inp){
    QRegularExpression regex("\\d{9}$");
    QRegularExpressionMatch match = regex.match(inp);
    if(match.hasMatch()){
        ui->lineEdit->setText("已为您更新今日天气,请查看!");
        emit weatherReceived(inp);
        return ;
    }
    regex = QRegularExpression(".mp4$");
    match = regex.match(inp);
    if(match.hasMatch()){
        ui->lineEdit->setText("已为您更新视频,请查看流媒体播放器!");
        emit videoUrlReceived(inp);
        return ;
    }
    emit messageReceived(inp);
    return;
}

// void browserWidget::sendMessageToLLM(QNetworkAccessManager *manager,QString question)
// {
//     // 设置你的 DashScope API Key
//     QString apiKey = "sk-7a2a9ad8ad06460ea13b61f31d73101f";

//     // API 端点
//     QUrl url("https://dashscope.aliyuncs.com/compatible-mode/v1/chat/completions");


//     // 创建请求
//     QNetworkRequest request(url);
//     request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
//     request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());

//     // 创建请求数据
//     QJsonObject systemMessage {
//         {"role", "system"},
//         {"content", "You are a helpful assistant.You should always answer questions by a single link which leads to correct website."}
//     };

//     QJsonObject userMessage {
//         {"role", "user"},
//         {"content", "请直接使用一个网址回答我的问题，保证网址是中国的合法网站."+question}
//     };

//     QJsonArray messagesArray;
//     messagesArray.append(systemMessage);
//     messagesArray.append(userMessage);

//     QJsonObject requestBody {
//         {"model", "qwen-turbo"},
//         {"messages", messagesArray}
//     };

//     QJsonDocument jsonDoc(requestBody);
//     QByteArray postData = jsonDoc.toJson();

//     // 发送请求
//     QNetworkReply *reply = manager->post(request, postData);
//     QString result="https://www.baidu.com";
//     // 处理响应
//     QObject::connect(reply, &QNetworkReply::finished, [reply,&result]() {
//         if (reply->error() == QNetworkReply::NoError) {
//             QByteArray response_data = reply->readAll();
//             qDebug()<<QString(response_data);

//             QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(response_data).toUtf8());

//             if (!jsonDoc.isNull() && jsonDoc.isObject()) {
//                 QJsonObject jsonObj = jsonDoc.object();

//                 // 获取 "choices" 数组
//                 QJsonArray choicesArray = jsonObj.value("choices").toArray();
//                 if (!choicesArray.isEmpty()) {
//                     QJsonObject firstChoice = choicesArray.at(0).toObject();

//                     // 获取 "message" 对象
//                     QJsonObject messageObj = firstChoice.value("message").toObject();

//                     // 获取 "content" 字符串
//                     QString content = messageObj.value("content").toString();
//                     // navigateToUrl(content);
//                     qDebug() << "Content:" << content; // 输出 content
//                     result =  content;
//                 }
//             }

//             // qDebug() << "Response received:" << QString(response_data);
//         } else {
//             qDebug() << "Request failed:" << reply->errorString();
//         }
//         reply->deleteLater(); // 释放资源
//     });
//     return result;
// }


