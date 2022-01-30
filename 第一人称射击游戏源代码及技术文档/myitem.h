#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QGraphicsSceneMouseEvent>
class myItem : public QGraphicsPixmapItem
{
public:
    myItem();
    void setPic(QString path);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setWoof(bool woof);
    bool isWoof();
    void setStart(bool start);
    bool isStart();


private:
    bool woof;
    bool start;
};

#endif // MYITEM_H
