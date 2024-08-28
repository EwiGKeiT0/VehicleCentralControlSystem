#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_checkBox_2_clicked(bool checked)
{
    ui->textEdit->clear();
    QFont ffont = ui->textEdit->font();
    ffont.setBold(checked^1);
    QColor ccolor = ui->textEdit->textColor();
    ccolor.setRed(100);
    ui->textEdit->setFont(ffont);
    ui->textEdit->setTextColor(ccolor);

}

