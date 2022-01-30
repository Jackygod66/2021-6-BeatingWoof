#include "subwidget.h"
#include "ui_subwidget.h"
#include "mainwindow.h"

extern QString globalScore;

subwidget::subwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwidget)
{
    ui->setupUi(this);
    this->setWindowTitle("得分情况");
    this->ui->Score->setText("得分:");
    this->ui->Got->setText("打中次数:");
    this->ui->Miss->setText("打失次数:")

    //handler * hand = handler::getInstance();
    //this->ui->score->setText(QString::number(globalScore));
    //this->ui->got->setText(QString::number(mainwindow->got));
    //this->ui->miss->setText(QString::number(mainwindow->miss));
}

subwidget::~subwidget()
{
    delete ui;
}

/*void subwidget::getNum()
{

}

void subwidget::missNum()
{

}*/


/*void subwidget::scoreNum(QString str)
{
    this->ui->score->setText(str);
}*/

