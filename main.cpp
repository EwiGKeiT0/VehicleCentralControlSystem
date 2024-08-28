#include "widget.h"
#include <QCoreApplication>
#include <QGeoPositionInfoSource>
#include <QGeoPositionInfo>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
