#include "painterWidget.h"
#include<QDebug>
PainterWidget::PainterWidget(QWidget *parent)
    : QWidget(parent)
{
    vector<pair<double,double>>().swap(m_dots);
    // 可以在这里进行初始化
}
QPointF PainterWidget::mapPoint(double x, double y) {
    // <bounds minlat="39.7217800" minlon="116.1602100" maxlat="39.7382100" maxlon="116.1722700"/>
    //update: 39.7316998 116.16264244999999

    double x1,y1,x2,y2,Y1,Y2,X1,X2;
    // y1=39.72178;
    // y1=39.7085781;
    y1=39.7210781-0.001;

    // y2=39.7382100;
    // y2=39.748215;
    y2=39.740115-0.001;

    // x1=116.1602100;
    // x1=116.1360793;
    x1=116.1510793;

    // x2=116.1722700;
    // x2=116.1892056;
    x2=116.1912056;

    X1=0;
    Y1=0;
    X2=X1+width();
    Y2=Y1+height();
    // qDebug()<<"x: y:"<<x<<" "<<y<<endl;
    // qDebug()<<width()<<height();

    // 计算映射后的X坐标
    double X = X1 + (X2 - X1)*(x - x1) / (x2 - x1)*262/242*150.0/147.0-60*width()/1898-dx/0.001*54*width()/1898+7;
    // 计算映射后的Y坐标
    double Y = Y1 +  (Y2 - Y1)* ((y2-y)/ (y2 - y1))-30*height()/873+dy/0.001*45*height()/873;

    return {X, Y};
}



QPair<double,double> PainterWidget::mapRealPos(double X, double Y)
{
    double x1,y1,x2,y2,Y1,Y2,X1,X2;
    // y1=39.72178;
    // y1=39.7085781;
    y1=39.7210781-0.001;

    // y2=39.7382100;
    // y2=39.748215;
    y2=39.740115-0.001;

    // x1=116.1602100;
    // x1=116.1360793;
    x1=116.1510793;

    // x2=116.1722700;
    // x2=116.1892056;
    x2=116.1912056;

    X1=0;
    Y1=0;
    X2=X1+width();
    Y2=Y1+height();
    // 计算映射后的X坐标
    // double X = X1 + (X2 - X1)*(x - x1) / (x2 - x1)*262/242*150.0/147.0-60*width()/1898-dx/0.001*54*width()/1898;
    // 计算映射后的Y坐标
    // double Y = Y1 +  (Y2 - Y1)* ((y2-y)/ (y2 - y1))-30*height()/873+dy/0.001*45*height()/873;

    double x=(X-X1+60*width()/1898+dx/0.001*54*width()/1898)*147.0/150*242/262*(x2-x1)/(X2-X1)+x1;
    double y=y2-(Y-Y1+30*height()/873-dy/0.001*45*height()/873)*(y2-y1)/(Y2-Y1);
    return {x,y};
}
void PainterWidget::mousePressEvent(QMouseEvent *event)  {
    QPointF globalPosition = event->globalPos();
    QPointF position = this->mapFromGlobal(globalPosition);
    if(isMouseSetting==1){
        isMouseStartPointSet=1;
        mouseStartPoint.first=position.x();
        mouseStartPoint.second=position.y();
        isMouseSetting=0;
    }
    else if(isMouseSetting==2){
        isMouseEndPointSet=1;
        mouseEndPoint.first=position.x();
        mouseEndPoint.second=position.y();
        isMouseSetting=0;
    }
    QWidget::mousePressEvent(event);
}
void PainterWidget::setImage(const QPixmap &pixmap) {
    m_pixmap = pixmap;
    update();  // 设置图片后触发重绘
}

void PainterWidget::setPath(const vector<pair<double, double> > &x)
{
    m_dots =x;
    qDebug() <<"pathsize"<<x.size();

    update();
}

void PainterWidget::setLinesAndBordersAndMappoints(const vector<vector<pair<double, double> > > &x,const vector<vector<pair<double, double> > > &y,const vector<pair<double, double> > &z)
{
    m_lines =x;
    m_borders=y;
    m_Mappoints=z;
    update();
}

void PainterWidget::paintEvent(QPaintEvent *event) {
    qDebug()<<"repaint!"<<m_dots.size();
    QPainter painter(this);

    // 绘制图片
    if (!m_pixmap.isNull()) {
        painter.drawPixmap(0, 0, width(), height(), m_pixmap);
    }
    QPointF st,end;

    painter.setPen(QPen(Qt::red, 4));

    for(const auto &u:m_Mappoints){
        st= mapPoint(u.first,u.second);
        painter.drawPoint(st);
    }
    /*
    QColor redColor = QColor(Qt::red);
    QColor greenColor = QColor(Qt::green);
    QColor blueColor = QColor(Qt::blue);
    QColor blackColor = QColor(Qt::black);
    // 创建 QPen 对象，并设置颜色
    QPen redPen(redColor);
    QPen greenPen(greenColor);
    QPen bluePen(blueColor);
    QPen blackPen(blackColor);
    // 将 QPen 对象存储在一个数组中
    std::array<QPen, 4> penArray = { redPen, greenPen, bluePen, blackPen };
    int idx=0;*/



    painter.setPen(QPen(Qt::blue, 2));
    for(const auto &singleLine:m_lines){
        if(singleLine.size()<=1)
            continue;
        st=mapPoint(singleLine[0].first,singleLine[0].second);
        for(int i=1;i<singleLine.size();i++){
            end=mapPoint(singleLine[i].first,singleLine[i].second);
            painter.drawLine(st,end);
            swap(st,end);
        }
    }

    painter.setPen(QPen(Qt::green, 2));
    for(const auto &singleLine:m_borders){
        if(singleLine.size()<=1)
            continue;
        st=mapPoint(singleLine[0].first,singleLine[0].second);
        for(int i=1;i<singleLine.size();i++){
            end=mapPoint(singleLine[i].first,singleLine[i].second);
            painter.drawLine(st,end);
            swap(st,end);
        }
    }



    painter.setPen(QPen(Qt::cyan, 4));

    if(m_dots.size()>1){
        //画路线
        st=mapPoint(m_dots[0].first,m_dots[0].second);
        for(int i=1;i<m_dots.size();i++){
            end=mapPoint(m_dots[i].first,m_dots[i].second);
            painter.drawLine(st,end);
            swap(st,end);
        }
        QPen pen(Qt::DashLine);
        pen.setColor(Qt::green);
        pen.setWidth(5);
        painter.setPen(pen);

        st=mapPoint(m_dots[0].first,m_dots[0].second);
        end = mapPoint(m_dots[1].first,m_dots[1].second);
        painter.drawLine(st,end);

        st=mapPoint(m_dots[m_dots.size()-2].first,m_dots[m_dots.size()-2].second);
        end = mapPoint(m_dots[m_dots.size()-1].first,m_dots[m_dots.size()-1].second);
        painter.drawLine(st,end);

        painter.setPen(QPen(Qt::black, 14));
        painter.drawPoint(mapPoint((*(m_dots.begin())).first,(*m_dots.begin()).second));
        painter.setPen(QPen(Qt::yellow, 14));
        painter.drawPoint(mapPoint((*(m_dots.end()-1)).first,(*(m_dots.end()-1)).second));
    }

    painter.setPen(QPen(Qt::red, 4));

    // for(const auto &u:m_Mappoints){
    //     st= mapPoint(u.first,u.second);
    //     painter.drawPoint(st);
    // }

    //画鼠标选择点
    painter.setPen(QPen(Qt::darkGreen, 14));
    if(isMouseStartPointSet)
        painter.drawPoint(mouseStartPoint.first,mouseStartPoint.second);
    if(isMouseEndPointSet)
        painter.drawPoint(mouseEndPoint.first,mouseEndPoint.second);

}
