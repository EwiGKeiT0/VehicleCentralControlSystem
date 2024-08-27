#include "naviwidget.h"
#include "ui_naviwidget.h"
#include <QHostInfo>
#include <QDebug>
#include <QNetworkInterface>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTimer>
#include <QGeoPositionInfoSource>
#include <QGeoPositionInfo>
#include <QDebug>
#include<calculatepath.h>
#include <QDateTime>
#define endl '\n'

// NaviWidget::NaviWidget(QWidget *parent) :
//     QMainWindow(parent),
//     ui(new Ui::NaviWidget)
// {

//     QString qss;
//     QFile qssFile(":qss/myQss.qss");
//     qssFile.open(QFile::ReadOnly);
//     if(qssFile.isOpen())
//     {
//         qss = QLatin1String(qssFile.readAll());
//         this->setStyleSheet(qss);
//         qssFile.close();
//     }
//     ui->setupUi(this);
//     calcRes =  new CalculatePath ();

//     int randindex1 = rand()%calcRes->nodecont+1;
//     int randindex2 = rand()%calcRes->nodecont+1;
//     calcRes->findPath(calcRes->id2realpos[randindex1].first,calcRes->id2realpos[randindex1].second,
//                   calcRes->id2realpos[randindex2].first,calcRes->id2realpos[randindex2].second,0);
//     //注册事件过滤
//     installEventFilter(this);

//     //初始化
//     init();

    // QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    // if (source) {
    //     connect(source, &QGeoPositionInfoSource::positionUpdated, this, [](const QGeoPositionInfo &info) {
    //         qDebug() << "Position updated:" << info.coordinate().toString();
    //         // double latitude = info.coordinate().latitude();
    //         // double longitude = info.coordinate().longitude();
    //     });

    //     // 设置更新间隔
    //     source->setUpdateInterval(1000); // 1秒
    //     source->startUpdates();
    // } else {
    //     qDebug() << "No position source available";
    // }

//     getIp();
// }

NaviWidget::NaviWidget(QWidget *parent, Widget *father)
    : QWidget(parent)
    , ui(new Ui::NaviWidget)
    , mainWindow(father)
{
    QString qss;
    QFile qssFile(":qss/myQss.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }
    ui->setupUi(this);
    calcRes =  new CalculatePath ();

    int randindex1 = rand()%(calcRes->nodecont)+1;
    int randindex2 = rand()%(calcRes->nodecont)+1;
    calcRes->findPath(calcRes->id2realpos[randindex1].first,calcRes->id2realpos[randindex1].second,
                      calcRes->id2realpos[randindex2].first,calcRes->id2realpos[randindex2].second,0);
    //注册事件过滤
    installEventFilter(this);

    //初始化
    init();

    // QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    // if (source) {
    //     connect(source, &QGeoPositionInfoSource::positionUpdated, this, [](const QGeoPositionInfo &info) {
    //         qDebug() << "Position updated:" << info.coordinate().toString();
    //         // double latitude = info.coordinate().latitude();
    //         // double longitude = info.coordinate().longitude();
    //     });

    //     // 设置更新间隔
    //     source->setUpdateInterval(1000); // 1秒
    //     source->startUpdates();
    // } else {
    //     qDebug() << "No position source available";
    // }

    getIp();
}
void NaviWidget::pop_path_front()
{
    qDebug()<<"update rawRes";
    if(!(this->calcRes->rawRes.empty())){
        qDebug()<<calcRes->rawRes.size();
        this->calcRes->rawRes.pop_back();
        qDebug()<<calcRes->rawRes.size();
        if(calcRes->rawRes.size())
        sendSurroundingRequest(calcRes->rawRes.back().first,calcRes->rawRes.back().second);
    }
    // double prob = QRandomGenerator::global()->generateDouble();
    // if(prob<0.05&&calcRes->rawRes.size()){
    //     int randindex1 = rand()%calcRes->nodecont+1;
    //     int randindex2 = rand()%calcRes->nodecont+1;
    //     double ans = calcRes->findPath(calcRes->rawRes.back().first,calcRes->rawRes.back().second,
    //                       calcRes->id2realpos[randindex1].first,calcRes->id2realpos[randindex1].second);
    //     if(ans==-1){
    //         ui->lineEdit->setText(QString("寻路失败！"));
    //     }
    //     else{
    //         ui->lineEdit->setText(QString("最短路线长度为%1").arg(ans));
    //     }
    // }
    // else
        if(ui->mapWidget->isMouseEndPointSet&&ui->mapWidget->isMouseStartPointSet){
            ui->mapWidget->isMouseEndPointSet=0;
            ui->mapWidget->isMouseStartPointSet=0;
            QPair<double,double> stp= ui->mapWidget->mapRealPos(ui->mapWidget->mouseStartPoint.first,ui->mapWidget->mouseStartPoint.second);
            QPair<double,double> enp= ui->mapWidget->mapRealPos(ui->mapWidget->mouseEndPoint.first,ui->mapWidget->mouseEndPoint.second);
            double ans = calcRes->findPath(stp.first,stp.second,
                              enp.first,enp.second);
            if(ans==-1){
                ui->lineEdit->setText(QString("寻路失败！"));
            }
            else{
                ui->lineEdit->setText(QString("路线长度为%1KM").arg(ans));
            }
        }
    ui->mapWidget->setPath(calcRes->rawRes);


}
void NaviWidget::init(){
    qDebug()<<"init";

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &NaviWidget::pop_path_front);
    timer->start(1000);


    //网络管理对象
    m_ipManager =new QNetworkAccessManager(this);
    //请求响应事件
    connect(m_ipManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onGetIp(QNetworkReply*)));

    //网络管理对象
    m_locManager =new QNetworkAccessManager(this);
    //请求响应事件
    connect(m_locManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onGetCurrentLoc(QNetworkReply*)));

    m_searchManager=new QNetworkAccessManager(this);
    connect(m_searchManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(onSearchLoc(QNetworkReply*)));

    //网络管理对象
    m_mapManager =new QNetworkAccessManager(this);

    m_PathSurroundingManager = new QNetworkAccessManager(this);
    // sendSurroundingRequest();

}

//获取当前主机ip   发送请求
 void NaviWidget::getIp(){

      //声明url 请求地址
      QUrl url("http://httpbin.org/ip");
      //声明请求对象
      QNetworkRequest request(url);
       //通过网络管理对象 发送get请求
      m_ipManager->get(request);

 }

 //处理服务器响应内容
 void NaviWidget::onGetIp(QNetworkReply *reply){
     //reply->readAll()  服务响响应的正文内容
     //qDebug() << "Current IP:" << reply->readAll();
     QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
     QJsonObject jsonObj = jsonDoc.object();
     currentIp=jsonObj.value("origin").toString();
     qDebug() << "Current IP:" << currentIp<<endl;

     //调用获取当前经纬度的函数
     getCurrentLoc();
 }

 //根据ip获取经纬度  发送请求
 void NaviWidget::getCurrentLoc(){
    //url
    QString host= "http://api.map.baidu.com/location/ip";
    QString query_str=QString("ip=%1&coor=bd09ll&ak=%2")
            .arg(currentIp).arg(ak);
    //请求地址
    QUrl url(host+"?"+query_str);
    //请求对象
    //声明请求对象
    QNetworkRequest request(url);
     //发送请求
    m_locManager->get(request);
 }

 //根据ip获取经纬度  处理服务器响应内容
 void NaviWidget::onGetCurrentLoc(QNetworkReply *reply){

     QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
     QJsonObject jsonObj = jsonDoc.object();
     QJsonObject jsonContent=jsonObj.value("content").toObject();
     QJsonObject jsonPonit=jsonContent.value("point").toObject();
     m_lng=jsonPonit.value("x").toString().toDouble();
     m_lat=jsonPonit.value("y").toString().toDouble();
     m_city=jsonContent.value("address_detail").toObject().value("city").toString();


     m_lng = 116.18262244999999;//pre
     m_lat = 39.7365000;


     qDebug() << jsonPonit.value("x").toString() <<endl;
     qDebug() << jsonPonit.value("y").toString() <<endl;
     sendMapRequest();
 }



 // 发送请求  获取地图图片
 void  NaviWidget::sendMapRequest(){


     //断调前一次请求
     if(m_mapReply!=NULL){
         m_mapReply->disconnect();
         //断掉事件连接
         disconnect(m_mapReply,&QIODevice::readyRead,this,&NaviWidget::onSendMapRequest);
     }

     //开始新的请求
     //url
     //请求地址
     QString host= "http://api.map.baidu.com/staticimage/v2";
     //请求参数


     // m_lng = 116.18262244999999;//pre
     // m_lat = 39.7365000;

     QString query_str=QString("ak=%1&width=512&height=346&center=%2,%3&zoom=%4&scale=2") //scale=2使得高清
             .arg(ak).arg(m_lng).arg(m_lat).arg(m_zoom);


     // QString targetPath = calcRes->parseRawRes2Qstring();
     // QString temp=QString("ak=%1&center=%2,%3&width=512&height=256&"
     //                        "zoom=%4&scale=2&paths="+targetPath+"&pathStyles=0xff0000,2,1").arg(ak).arg(m_lng).arg(m_lat).arg(m_zoom);
     // query_str=temp;

     QUrl url(host+"?"+query_str);

     qDebug()<<host+"?"+query_str<<endl;

     QNetworkRequest request(url);
     //此处与前面的请求不同，等待服务器响应，
     m_mapReply= m_mapManager->get(request);
     //连接事件，处理服务器返回的 文件流
     connect(m_mapReply,&QIODevice::readyRead,this,&NaviWidget::onSendMapRequest);
 }



 //处理服务器返回地图图片
 void  NaviWidget::onSendMapRequest(){

     //删除原有的地图图片 使用系统命令删除
     //system("del map.png");
     //文件对象
     // QFile file;
     // file.setFileName(m_mapFileName);
     // if (file.exists())
     //     file.remove();
     // file.close();

    // mapFile.setFileName(m_mapFileName);

    //  //读取文件流，保存文件到本地,
    //  //open 没有则新建文件，打开
    // mapFile.open(QIODevice::WriteOnly| QIODevice::Truncate);
    m_timer.start(500);
    connect(&m_timer,&QTimer::timeout,[=](){
        m_timer.stop();
        QByteArray tempMap = m_mapReply->readAll();
        // mapFile.write(tempMap);
        // mapFile.close();

        QPixmap pixmap;

        // QPixmap pixmap(":/images/sample.png"); // 确保图片路径正确

        // if(pixmap.load(m_mapFileName)){
        //    ui->mapWidget->setImage(pixmap);
        // }


        if (tempMap.size() > 0)
        {
            pixmap.loadFromData(tempMap);
            ui->mapWidget->setImage(pixmap);
        }
        // else{
        //     qDebug()<<"fuck";
        // }
        ui->mapWidget->setLinesAndBordersAndMappoints(calcRes->rawLines,calcRes->rawBorders,calcRes->rawMapPoints);
        ui->mapWidget->setPath(calcRes->rawRes);

    });




 }






NaviWidget::~NaviWidget()
{
    delete ui;
}

//搜索地址  发送请求
void NaviWidget::on_searchBtn_clicked()
{
    //1、取文本框的值
    qDebug()<<ui->edit_search->text()<<endl;

    //2、url
    QString host="http://api.map.baidu.com/place/v2/search";


    QString query_str=QString("query=%1&location=%2,%3&output=json&ak=%4&radius=20000")
            .arg(ui->edit_search->text()).arg(m_lat).arg(m_lng).arg(ak);

    QList<QString> list;
    list.append("湖北");
    list.append("湖南");
    list.append("北京");
    if(list.contains(ui->edit_search->text())){
        query_str.append("&region=%1").arg(ui->edit_search->text());
    }else {
        query_str.append("&region=%1").arg(m_city);
    }

    QUrl url(host+"?"+query_str);
    //3、request
    QNetworkRequest request(url);
    //4、发送请求
    m_searchManager->get(request);

}

void NaviWidget::sendSurroundingRequest(double x,double y)
{

    QString akk = QString("%1").arg(ak);

    // 服务地址
    QString host = "http://api.map.baidu.com";

    // 接口地址
    QString uri = "/place/v2/search";

    // 设置请求参数
    QUrlQuery query;
    query.addQueryItem("query", "路$街$巷$桥$港$园$店$湖$区$学");
    query.addQueryItem("radius", "50");
    query.addQueryItem("radius_limit", "true");
    query.addQueryItem("scope", "2");
    query.addQueryItem("filter", "sort_name:distance|sort_rule:1");
    QString tar=QString("%1,%2").arg(y).arg(x);

    query.addQueryItem("output", "json");
    query.addQueryItem("ak", akk);
    query.addQueryItem("location",tar);
    query.addQueryItem("coord_type","3");
    QUrl url(host + uri);
    url.setQuery(query);
    qDebug()<<url;


    QNetworkRequest request(url);

    // 发送请求
    QNetworkReply *reply = this->m_PathSurroundingManager->get(request);

    // 处理响应
    QObject::connect(reply, &QNetworkReply::finished, [reply, this]() {
        qDebug()<<"get feedback";
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
            QJsonObject jsonObj = jsonDoc.object();
            int status = jsonObj.value("status").toInt();
            QString message = jsonObj.value("message").toString();
            if (status != 0 || message != "ok") {
                qWarning() << "Request failed with status:" << status << "message:" << message;
                return;
            }
            QJsonArray jsonarray = jsonObj.value("results").toArray();
            if (!jsonarray.isEmpty()) {
                qDebug() << "返回结果为：";
                QJsonObject firstResult = jsonarray[0].toObject();  // 将 QJsonValue 转换为 QJsonObject
                QString name = firstResult.value("name").toString();  // 获取 "name" 字段的字符串值
                qDebug() << "Name:" << name;
                ui->edit_search->setText(name);

            }
            else{
                qDebug()<<"empty!";
            }
        } else {
            qDebug() << "请求失败：" << reply->errorString();
        }
        reply->deleteLater(); // 释放资源
    });
}

//搜索地址  处理响应内容
void NaviWidget::onSearchLoc(QNetworkReply *reply){
//    qDebug()<<reply->readAll()<<endl;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
    reply->deleteLater();
     QJsonObject jsonObj = jsonDoc.object();
     QJsonArray addrArray= jsonObj.value("results").toArray();
     QJsonObject addrJson=addrArray.at(0).toObject();
     QJsonObject xyJson=addrJson.value("location").toObject();
     m_lng=xyJson.value("lng").toDouble();
     m_lat=xyJson.value("lat").toDouble();
     m_city=addrJson.value("city").toString();

     qDebug()<<m_lng<<endl;
     qDebug()<<m_lat<<endl;

     m_zoom=17;
     //调取地图图片的函数
     sendMapRequest();
}

//放大按钮，点击后改变m_zoom [3-18]
void NaviWidget::on_enlargeBtn_clicked()
{
    //判断m_zoom是否小于18，
    if(m_zoom<19){
        m_zoom+=1;
        //调用函数重新获取地图图片
        sendMapRequest();
    }
}

//缩小按钮，点击后改变m_zoom [3-18]
void NaviWidget::on_reduceBtn_clicked()
{
    if(m_zoom>3){
        m_zoom-=1;
        sendMapRequest();
    }
}



//过滤事件
bool  NaviWidget::eventFilter(QObject *watched, QEvent *event){

//    qDebug()<<event->type()<<endl;
    if(event->type()==QEvent::MouseButtonPress){
        qDebug()<<event->type()<< cursor().pos().x()<<":"<<cursor().pos().y()<<endl;
        isPress=true;
        startPoint.setX(cursor().pos().x());
        startPoint.setY(cursor().pos().y());
    }

    if(event->type()==QEvent::MouseButtonRelease){
        qDebug()<<event->type()<< cursor().pos().x()<<":"<<cursor().pos().y()<<endl;
        isRelease=true;
        endPoint.setX(cursor().pos().x());
        endPoint.setY(cursor().pos().y());
    }

    if(isPress&&isRelease){
        isPress=false;
        isRelease=false;
       //计算距离差
        mx=startPoint.x()-endPoint.x();
        my=startPoint.y()-endPoint.y();

        if(qAbs(mx)>5||qAbs(my)>5){
            m_lng+=mx*0.000002*(19-m_zoom)*(19-m_zoom);
            ui->mapWidget->dx+=mx*0.000002*(19-m_zoom)*(19-m_zoom);
            m_lat-=my*0.000002*(19-m_zoom)*(19-m_zoom);
            ui->mapWidget->dy-=my*0.000002*(19-m_zoom)*(19-m_zoom);
            sendMapRequest();
        }
    }

    return QWidget::eventFilter(watched,event);
}




void NaviWidget::on_pushButton_clicked()
{
    ui->mapWidget->isMouseSetting=1;
}


void NaviWidget::on_pushButton_2_clicked()
{
    ui->mapWidget->isMouseSetting=2;
}

