#ifndef NAVIWIDGET_H
#define NAVIWIDGET_H
// #include<widget.h>
#include<painterWidget.h>
#include <QRandomGenerator>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QGeoPositionInfoSource>
#include <QGeoPositionInfo>
#include<QTimer>
#include<QFile>
#include<QPainter>
#include<calculatepath.h>
#include <QUrlQuery>
#include<qpair.h>
#include<hovereventfilter.h>
#include<colorgradient.h>
namespace Ui {
class NaviWidget;
}
class Widget;
class NaviWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NaviWidget(QWidget *parent = nullptr);
    explicit NaviWidget(QWidget *parent = nullptr, Widget *father = nullptr);
    ~NaviWidget();
    CalculatePath* calcRes;

    void setGradient(QWidget *a, QColor start, QColor end, int DURATION, QString extra="");
    void justGoToCanteen(QString);
private slots:
    //处理获取外网ip请求的 槽
    void onGetIp(QNetworkReply*);
    //根据ip获取经纬度  处理服务器响应内容
    void onGetCurrentLoc(QNetworkReply*);
    //处理服务器返回地图图片
    void onSendMapRequest();
    //搜索地址 发送请求
    void on_searchBtn_clicked();
    //搜索地址 处理响应内容

    void sendSurroundingRequest(double,double);

    void onSearchLoc(QNetworkReply*);

    void on_enlargeBtn_clicked();

    void on_reduceBtn_clicked();

    void pop_path_front();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Widget *mainWindow;
    Ui::NaviWidget *ui;
    QNetworkAccessManager *m_ipManager;
    QNetworkAccessManager *m_locManager;
    QNetworkAccessManager *m_searchManager;
    QNetworkAccessManager *m_PathSurroundingManager;
    //网络管理对象  发送地图图片

    QNetworkAccessManager *m_mapManager;
    //响应对象 接收地图图片
    QNetworkReply *m_mapReply=NULL;
    QGeoPositionInfoSource *CurrentSource;



    //初始化
    void init();
    //baidu App key
    QString ak="yYSnHDIgAbSRlyktehYXmvlzA0s3eEhX";
    QString ak2="CDE9axcE8tPnZZRLiPdgK8IIsXOJ77a3";
    //存储当前主机ip
    QString currentIp;
    //经度
    double m_lng;
    //纬度
    double m_lat;
    //控制好地图的精度  高清或低清[3-18]
    int m_zoom=15;
    //当前所在的城市
    QString m_city;
    //地图文件名
    QString m_mapFileName="map.png";
    QTimer m_timer;
    QFile mapFile;

    //是否按下鼠标按钮
    bool isPress=false;
    //是否释放鼠标按钮
    bool isRelease=false;
    //按下鼠标的坐标点
    QPoint startPoint;
    //释放鼠标的坐标点
    QPoint endPoint;
    //x轴距离差
    double mx;
    //y轴距离差
    double my;


    //获取当前主机ip
    void getIp();
    //根据ip获取经纬度  发送请求
    void getCurrentLoc();
    // 发送请求  获取地图图片
    void sendMapRequest();
    //过滤事件
    bool eventFilter(QObject *watched, QEvent *event);

    double pathLength=0.0;


};

#endif // NAVIWIDGET_H
