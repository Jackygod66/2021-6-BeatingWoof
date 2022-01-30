#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>

class handler : public QObject
{
    Q_OBJECT

public:
    static handler * getInstance();
    void addScore();
    void setScore();
    void setCounter();
    void startCounter();
    void getScore();
    void missScore();
    void setGetscore();
    void setMissscore();
    /*void Get();
    void Miss();
    void Score();*/
private:
    explicit handler(QObject *parent = nullptr);

signals:
    void beatWoof();
    void setscore();
    void setcounter();
    void startcounter();
    void getscore();
    void missscore();
    void setgetscore();
    void setmissscore();
    /*void get();
    void miss();
    void score();*/
public slots:

private:
    static handler * hand;

};

#endif // HANDLER_H
