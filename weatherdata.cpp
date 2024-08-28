#include "weatherdata.h"

weatherdata::weatherdata() {}

weatherdata::weatherdata (QString qu, QString c, QString p, QString t, QString ht, QString lt, QString wt, QString da, QString wd, QString wg, QString pm, QString w, int aqi) {
    this->city_name = c;
    this->parent_name = p;
    this->temperature = t;
    this->h_temperature = ht;
    this->l_temperature = lt;
    this->weather_type = wt;
    this->date = da;
    this->wind_direction = wd;
    this->wind_grade = wg;
    this->pm25 = pm;
    this->wet = w;
    this->quality = qu;
    this->aqi = aqi;
}

weatherdata::weatherdata (QString date, QString ht, QString lt, QString type, int aqi) {
    this->date = date;
    this->h_temperature = ht;
    this->l_temperature = lt;
    this->weather_type = type;
    this->aqi = aqi;
}
