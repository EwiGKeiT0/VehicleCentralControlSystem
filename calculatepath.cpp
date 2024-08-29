#include "calculatepath.h"

#include <QFile>
#define dnt double
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define dow(i,j,k) for(int i=(j);i>=(k);--i)
#define pr pair
#define pb push_back
#define mkp make_pair
#define endl '\n'
#define fi first
#define se second
double calcdis(pr<double,double>p1,pr<double,double>p2){
    return (p2.fi-p1.fi)*(p2.fi-p1.fi)+(p2.se-p1.se)*(p2.se-p1.se);
}
double calcDistance(pr<double,double>p1,pr<double,double>p2,bool km=0){
    double x = abs(p1.fi-p2.fi);
    double y = abs(p1.se-p2.se);

    double xdis = x*100000.0;
    double ydis=0.0;
    ydis+=((int)y)*111320.0;
    y-=(int)y;

    y*=10;
    ydis+=((int)y)*11132.0;
    y-=(int)y;

    y*=10;
    ydis+=((int)y)*1113.0;
    y-=(int)y;

    y*=10;
    ydis+=((int)y)*111.0;
    y-=(int)y;

    y*=10;
    ydis+=((int)y)*11.0;
    y-=(int)y;

    y*=10;
    ydis+=((int)y)*1.1;
    y-=(int)y;
    if(km){
        xdis/=1000.0;
        ydis/=1000.0;
    }
    return sqrt(xdis*xdis+ydis*ydis);
}
CalculatePath::CalculatePath() {
    realpos2id={};
    id2realpos={};
    realid2id={};
    id2realid={};

    const int MAXN = 1000000;
    // vector<pr<double,double>>dots(MAXN);
    this->invaild=vector<int>(MAXN);


     // ----------------------

    QFile file("://nodes.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    int id = 0;
    nodecont=0;
    while(1) {
        long long realid;
        double x, y;


        in >> realid;
        if(realid<0)
            break;
        in>> y >> x;


        if (in.status() != QTextStream::Ok) {
            qDebug() << "Error reading line, skipping.";
            continue;
        }

        // qDebug() << realid << x << y;  // 打印读取的值

            id++;
            nodecont++;
            vector<pr<int,double> >().swap(e[id]);
            realpos2id[mkp(x,y)]=id;
            id2realpos[id]=mkp(x,y);
            id2realid[id]=realid;
            realid2id[realid]=id;
            // dots[id]=mkp(x,y);
    }
    long long realid;
       // deal with line
    long long contned=0;
    vector<long long>nodes;
            while(!in.atEnd()){
                in>>realid;
                // qDebug()<<realid;
                if(realid==-1||realid==-2){
                    vector<pair<double,double>>lineNodes;
                    bool isFirstNode=1;
                    pair<double,double>pre;
                    for(const auto&u:nodes){
                        lineNodes.push_back(id2realpos[realid2id[u]]);
                        double tardis=0.0;
                        if(realid==-1&&!isFirstNode&&((tardis=calcDistance(id2realpos[realid2id[u]],pre))>30)){
                            pair<double,double>vec = mkp(id2realpos[realid2id[u]].fi-pre.fi,id2realpos[realid2id[u]].se-pre.se);
                            vec.fi*=30;
                            vec.se*=30;
                            vec.fi/=tardis;vec.se/=tardis;
                            int ned = tardis/30;
                            contned+=ned;
                            // qDebug()<<ned<<" "<<tardis;
                            while(ned){
                                if(!realpos2id[mkp(pre.fi+vec.fi,pre.se+vec.se)]){
                                    nodecont++;
                                    id++;
                                    assert(id==nodecont);
                                    realpos2id[mkp(pre.fi+vec.fi,pre.se+vec.se)]=nodecont;
                                    id2realpos[nodecont]=mkp(pre.fi+vec.fi,pre.se+vec.se);
                                }
                                pre.fi+=vec.fi;
                                pre.se+=vec.se;
                                ned--;
                            }
                        }
                        isFirstNode=0;
                        pre=id2realpos[realid2id[u]];
                    }
                    if(realid==-1)
                    rawLines.push_back(lineNodes);
                    else
                    rawBorders.push_back(lineNodes);
                    if(realid==-2){
                        for(const auto&u:nodes){
                            if(realid2id[u]){
                                invaild[realid2id[u]]=1;
                            }
                        }
                    }
                    nodes.clear();
                }
                else{
                    nodes.push_back(realid);
                }
            }
            qDebug()<<contned<<"asas";

            // for(const auto&u:nodes){
            //     for(const auto&v:nodes){
            //         if(u==v)
            //             continue;
            //         if(realid2id[u]&&realid2id[v]){
            //             int i=realid2id[u];
            //             int j=realid2id[v];
            //             e[i].push_back(mkp(j,calcdis(dots[i],dots[j])));
            //         }
            //     }
            // }



    file.close();

    long long contE=0;
    // ----------------------
    rep(i,1,nodecont){
        if(invaild[i])
            continue;
        rep(j,1,nodecont){
            if(i!=j&&!invaild[j]&&calcDistance(id2realpos[i],id2realpos[j])<eps){
                e[i].push_back(mkp(j,calcDistance(id2realpos[i],id2realpos[j])));
            }
        }
    }
    rep(i,1,nodecont){
        appendMapPoint(id2realpos[i].first,id2realpos[i].second);
    }

    qDebug()<<"created!!!!!!!!!!!!!!";
}
double CalculatePath::findPath(double stx, double sty, double enx, double eny,bool needclear)
{
    qDebug()<<"in"<<endl;
    qDebug()<<"nodecont"<<nodecont;
    vector<pair<double,double>>res_temp;
    if(needclear){
        rawRes.clear();
        rawResDistance.clear();
    }
    bool isstValid=0;
    bool isenValid=0;



    if(realpos2id[mkp(stx,sty)]&&!invaild[realpos2id[mkp(stx,sty)]]){
        isstValid=1;
    }

    if(realpos2id[mkp(enx,eny)]&&!invaild[realpos2id[mkp(enx,eny)]]){
        isenValid=1;
    }


    e[nodecont+1].clear();
    e[nodecont+2].clear();
    id2realpos[nodecont+1]=mkp(stx,sty);
    id2realpos[nodecont+2]=mkp(enx,eny);
    rep(i,1,nodecont){
        if(calcDistance(mkp(stx,sty),id2realpos[i])<eps)
        e[nodecont+1].push_back(mkp(i,calcDistance(id2realpos[nodecont+1],id2realpos[i])));
        if(calcDistance(mkp(enx,eny),id2realpos[i])<eps)
        e[nodecont+2].push_back(mkp(i,calcDistance(id2realpos[nodecont+2],id2realpos[i])));
        if(calcDistance(mkp(stx,sty),id2realpos[i])<eps)
        e[i].push_back(mkp(nodecont+1,calcDistance(id2realpos[nodecont+1],id2realpos[i])));
        if(calcDistance(mkp(enx,eny),id2realpos[i])<eps)
        e[i].push_back(mkp(nodecont+2,calcDistance(id2realpos[nodecont+2],id2realpos[i])));
    }
    priority_queue<pr<double,int>>q;// double,int ,not int,double!
    vector<double>dis(nodecont+3);
    vector<int>pre(nodecont+3);
    rep(i,1,nodecont+2){
        dis[i]=1000000000.0;
    }

    int stid=nodecont+1;
    int enid=nodecont+2;
    rep(i,1,nodecont+2){
        // qDebug()<<nodecont<<i;
        for(const auto u:e[i]){
            assert(u.second<eps);
        }
    }

    assert(q.empty());
    dis[stid]=0;
    q.push(mkp(dis[stid],stid));

    while(!q.empty()){
        // int dist = -q.top().fi;
        int u = q.top().se;
        q.pop();
        if(u==enid)
            break;
        assert(u);
        for(const auto&v:e[u]){
            assert(v.se<=eps);
            if(v.se+dis[u]<dis[v.fi]){
                dis[v.fi]=v.se+dis[u];
                q.push(mkp(-dis[v.fi],v.fi));
                pre[v.fi]=u;
                qDebug()<<v.fi<<u<<v.se<<calcDistance(id2realpos[v.fi],id2realpos[u]);
                assert(calcDistance(id2realpos[v.fi],id2realpos[u])<=eps);
            }
        }
    }
    int cur=enid;
    res_temp.push_back(id2realpos[cur]);
    rawResDistance.push_back(dis[cur]);
    double ans=0.0;
    if(isenValid){
        res_temp.push_back(id2realpos[cur]);
        rawResDistance.push_back(dis[cur]);
    }
    qDebug()<<"path:";
    while(cur!=stid){

        res_temp.push_back(id2realpos[pre[cur]]);
        rawResDistance.push_back(dis[pre[cur]]);
        if(pre[cur]){
            ans+=calcDistance(id2realpos[cur],id2realpos[pre[cur]],1);
            assert(calcDistance(id2realpos[cur],id2realpos[pre[cur]])<eps);
            qDebug()<<calcDistance(id2realpos[cur],id2realpos[pre[cur]]);
        }
        cur=pre[cur];
        if(!cur)
            break;
    }
    if(cur==stid&&isstValid){
        res_temp.push_back(id2realpos[cur]);
        rawResDistance.push_back(dis[cur]);
    }

    rep(i,1,nodecont){
        if(e[i].size()&&e[i].back().first>nodecont)
        e[i].pop_back();
        if(e[i].size()&&e[i].back().first>nodecont)
        e[i].pop_back();
    }
    e[nodecont+1].clear();
    e[nodecont+2].clear();
    rawRes.swap(res_temp);
    if(cur!=stid){
        qDebug()<<"failed";
        return -1;
    }

    return ans;
}

void CalculatePath::appendDot(double x, double y)
{
    // rawRes.push_back(mkp(x,y));
}
void CalculatePath::appendMapPoint(double x, double y)
{
    rawMapPoints.push_back(mkp(x,y));
}

QString CalculatePath::parseRawRes2Qstring()
{
    QString ans="";
    for(const auto u:rawRes){
        QString x = QString::number(u.first, 'g', 15);  // 'g' 表示通用格式，15 表示最大精度
        QString y = QString::number(u.second, 'g', 15);
        ans+=x+","+y;
        ans+=";";
    }
    qDebug()<<"path:"<<ans;
    return ans;
}


/*

 */
