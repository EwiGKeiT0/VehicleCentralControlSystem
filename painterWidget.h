#ifndef PAINTERWIDGT_H
#define PAINTERWIDGT_H
#include<QWidget>
#include<QPainter>
#include<bits/stdc++.h>
#include<calculatepath.h>
#include<QPointF>
#include<qpair.h>
#include <QMouseEvent>
using namespace std;
class PainterWidget : public QWidget {
    Q_OBJECT

public:
    explicit PainterWidget(QWidget *parent = nullptr);
    void setImage(const QPixmap &pixmap);
    void setPath(const vector<pair<double,double>>&x);
    void setLinesAndBordersAndMappoints(const vector<vector<pair<double,double>>>&x,const vector<vector<pair<double,double>>>&y,const vector<pair<double,double>>&z);
    QPointF mapPoint(double x, double y);
    QPair<double,double> mapRealPos(double x, double y);
    CalculatePath * painterCalc;
    double dx=0.0;
    double dy=0.0;
    bool isMouseStartPointSet=0;
    bool isMouseEndPointSet=0;
    int isMouseSetting;//0 1 2
    QPair<double,double>mouseStartPoint,mouseEndPoint;

protected:
    // 重写 paintEvent 方法
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    QPixmap m_pixmap;
    vector<pair<double,double>>m_dots;
    vector<pair<double,double>>m_Mappoints;
    vector<vector<pair<double,double>>>m_lines;
    vector<vector<pair<double,double>>>m_borders;

};

#endif // PAINTERWIDGT_H
