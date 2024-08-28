#ifndef CALCULATEPATH_H
#define CALCULATEPATH_H
#include<bits/stdc++.h>
#include<QDebug>
using namespace std;
double calcdis(pair<double,double>p1,pair<double,double>p2);
class CalculatePath
{
public:
    CalculatePath();
    double findPath(double stx,double sty,double enx,double eny,bool needclear=1);
    void appendDot(double x,double y);
    void appendMapPoint(double x, double y);
    QString parseRawRes2Qstring();
    vector<pair<double,double>>rawRes;
    vector<double>rawResDistance;
    vector<vector<pair<double,double>>>rawLines;
    vector<vector<pair<double,double>>>rawBorders;
    vector<pair<double,double>>rawMapPoints;
    void updateRes(double x,double y);
    map<int,pair<double,double>>id2realpos;

    long long eps=31;
    int nodecont=0;//3064;
    // int bingchaji[4005];


private:
    map<pair<double,double>,int>realpos2id;
    map<long long,int>realid2id;
    map<int,long long>id2realid;
    vector<pair<int,double>>e[10005];
    vector<int>invaild;

};

#endif // CALCULATEPATH_H
