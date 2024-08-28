#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include<QString>

class weatherdata
{
public:
    weatherdata();

    QString city_name;
    QString parent_name;
    QString temperature;
    QString h_temperature;
    QString l_temperature;
    QString weather_type;
    QString date;
    QString wind_direction;
    QString wind_grade;
    QString pm25;
    QString wet;
    QString quality;
    int aqi;
    weatherdata (QString qu, QString c, QString p, QString t, QString ht, QString lt, QString wt, QString da, QString wd, QString wg, QString pm, QString w, int aqi);
    weatherdata (QString date, QString ht, QString lt, QString type, int aqi);

};

#endif // WEATHERDATA_H
