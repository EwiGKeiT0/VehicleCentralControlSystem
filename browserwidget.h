#ifndef BROWSERWIDGET_H
#define BROWSERWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QWebEngineView>
#include <QLineEdit>
#include <QToolBar>
#include <QAction>
// #include "widget.h"
#include <QRegularExpression>
#include<hovereventfilter.h>
#include<colorgradient.h>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>
#include <QRegularExpression>
namespace Ui {
    class browserWidget;
}
class Widget;
class browserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit browserWidget(QWidget *parent = nullptr, Widget *father = nullptr);
    ~browserWidget();

private:
    Ui::browserWidget *ui;
    Widget *mainWindow;

public:
    browserWidget(QWidget *parent = nullptr);
    void sendMessageToLLM(QNetworkAccessManager *manager,QString question);
    void setGradient(QWidget *a, QColor start, QColor end, int duration, QString extra);
    void MessageFilter(QString inp);
signals:
    void messageReceived(QString result);
    void weatherReceived(QString result);
    void videoUrlReceived(QString result);


private slots:
    void navigateToUrl();
    void updateUrl(const QUrl &url);
    void navigateToUrlBySearch(const QString &urlstring);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    const int DURATION = 150;
    QWebEngineView *view;
    QNetworkAccessManager* manager;
    // QLineEdit *addressBar;
};

#endif // BROWSERWIDGET_H
