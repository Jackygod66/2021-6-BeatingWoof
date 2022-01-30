#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <myitem.h>
#include <QTimer>

class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr);

signals:

public slots:
    void showWoof();
    void startGame();
    void stopGame();
    void endGame();
    void showCounter();

private:
    myItem * item[18];
    QTimer * ptimer;
    QTimer * ctimer;
};

#endif // MYSCENE_H
