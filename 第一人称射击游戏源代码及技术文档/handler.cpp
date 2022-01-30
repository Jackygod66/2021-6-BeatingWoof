#include "handler.h"

handler::handler(QObject *parent) : QObject(parent)
{

}

handler * handler::hand = new handler;

handler * handler::getInstance()
{
    return hand;
}

void handler::addScore()
{
    emit beatWoof();
}

void handler::setScore()
{
    emit setscore();
}

void handler::setCounter()
{
    emit setcounter();
}

void handler::startCounter()
{
    emit startcounter();
}

void handler::getScore()
{
    emit getscore();
}

void handler::missScore()
{
    emit missscore();
}

void handler::setGetscore()
{
    emit setgetscore();
}

void handler::setMissscore()
{
    emit setmissscore();
}

/*void handler::Get()
{
    emit get();
}

void handler::Miss()
{
    emit miss();
}

void handler::Score()
{
    emit score();
}*/
