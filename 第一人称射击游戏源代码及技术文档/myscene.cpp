#include "myscene.h"
#include <stdlib.h>
#include "handler.h"

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    int i = 0;
    for(i=0;i<18;i++){
        this->item[i] = new myItem;
        this->item[i]->setPos(i%6 * this->item[i]->boundingRect().width(),i/6 * this->item[i]->boundingRect().height());
        this->addItem(this->item[i]);
    }
    this->ptimer = new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showWoof()));
    this->ctimer = new QTimer;
    connect(this->ctimer,SIGNAL(timeout()),this,SLOT(showCounter()));
}

void myScene::showWoof()
{
    //随机出现数字0-17
    //1-3
    int count = rand()%3 + 1;
    int i=0;
    for(i=0;i<18;i++){
        this->item[i]->setPic(":/bg/pic/tree.png");
        this->item[i]->setWoof(false);
    }
    for(i=0;i<count;i++){
        int index = rand()%18;
        /*if(index%6>2){
            if(index>14) index-=3;
            else index+=3;
        }*/
        this->item[index]->setPic(":/bg/pic/appear.png");
        this->item[index]->setWoof(true);
    }
}

void myScene::startGame()
{
    int i=0;
    for(i=0;i<18;i++){
        this->item[i]->setStart(true);
    }
    this->ptimer->start(800);
    this->ctimer->start(1000);
}

void myScene::stopGame()
{
    int i=0;
    for(i=0;i<18;i++){
        this->item[i]->setStart(false);
    }
    this->ptimer->stop();
    this->ctimer->stop();
}

void myScene::endGame()
{
    int i=0;
    for(i=0;i<18;i++){
        this->item[i]->setStart(false);
    }
    this->ptimer->stop();
    this->ctimer->stop();
    for(i=0;i<18;i++){
        this->item[i]->setPic(":/bg/pic/tree.png");
        this->item[i]->setWoof(false);
    }
    handler * hand = handler::getInstance();
    hand->setScore();
    hand->setCounter();
    hand->setGetscore();
    hand->setMissscore();
}

void myScene::showCounter()
{
    handler * hand = handler::getInstance();
    hand->startCounter();
}

