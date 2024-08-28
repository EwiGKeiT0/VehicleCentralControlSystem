#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include "widget.h"

namespace Ui {
    class chatWidget;
}

class chatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit chatWidget(QWidget *parent = nullptr, Widget *father = nullptr);
    ~chatWidget();

private:
    Ui::chatWidget *ui;
    Widget *mainWidget;
};

#endif // CHATWIDGET_H
