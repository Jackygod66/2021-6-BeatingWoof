#include "myitem.h"
#include <QPixmap>
#include <QDebug>
#include "handler.h"
#include <QCursor>

myItem::myItem()
{
    this->setPixmap(QPixmap(":/bg/pic/tree.png"));
    this->start = false;
    this->woof = false;
}

void myItem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}

void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/woof/pic/target.png")));
}

void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/woof/pic/shoot.png")));
    if(this->isStart()){
        handler * hand = handler::getInstance();
        if(this->isWoof()){
            hand->addScore();
            hand->getScore();
            this->setPixmap(QPixmap(":/woof/pic/disappear.png"));
            this->woof = false;
//            qDebug()<<"打到了";
        }
        else{
            hand->missScore();

            //qDebug()<<"没打到";
        }

    }

}





void myItem::setWoof(bool woof)
{
    this->woof = woof;
}

bool myItem::isWoof()
{
    return this->woof;
}

void myItem::setStart(bool start)
{
    this->start=start;
}

bool myItem::isStart()
{
    return this->start;
}

