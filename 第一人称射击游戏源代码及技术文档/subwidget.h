#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include "handler.h"
//#include "mainwindow.h"

namespace Ui {
class subwidget;
}

class subwidget : public QWidget
{
    Q_OBJECT

public:
    explicit subwidget(QWidget *parent = nullptr);
    ~subwidget();

private slots:
    //void getNum();
    //void missNum();
    //void scoreNum(QString);

private:
    Ui::subwidget *ui;
};

#endif // SUBWIDGET_H
