#ifndef BROWSERWIDGET_H
#define BROWSERWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QWebEngineView>
#include <QLineEdit>
#include <QToolBar>
#include <QAction>
#include "widget.h"
#include <QRegularExpression>
#include<hovereventfilter.h>
#include<colorgradient.h>
namespace Ui {
    class browserWidget;
}

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

    void setGradient(QWidget *a, QColor start, QColor end, int duration, QString extra);
private slots:
    void navigateToUrl();
    void updateUrl(const QUrl &url);
    void navigateToUrlBySearch(const QString &urlstring);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    QWebEngineView *view;
    // QLineEdit *addressBar;
};

#endif // BROWSERWIDGET_H
