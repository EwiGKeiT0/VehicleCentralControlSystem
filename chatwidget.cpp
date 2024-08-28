#include "chatwidget.h"
#include "ui_chatwidget.h"

chatWidget::chatWidget(QWidget *parent, Widget *father)
    : QWidget(parent)
    , ui(new Ui::chatWidget)
    , mainWidget(father)
{
    ui->setupUi(this);
}

chatWidget::~chatWidget()
{
    delete ui;
}
