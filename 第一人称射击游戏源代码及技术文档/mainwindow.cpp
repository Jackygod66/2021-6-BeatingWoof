#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "handler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc = new myScene;
    this->ui->graphicsView->setScene(sc);
    connect(this->ui->start,SIGNAL(clicked(bool)),this->sc,SLOT(startGame()));
    connect(this->ui->stop,SIGNAL(clicked(bool)),this->sc,SLOT(stopGame()));
    connect(this->ui->end,SIGNAL(clicked(bool)),this->sc,SLOT(endGame()));
    this->score = 0;
    this->count = 60;
    this->got = 0;
    this->miss = 0;
    this->ui->lcdNumber->display(this->score);//初始化得分
    this->ui->TimeCounter->display(this->count);//初始化计时器
    this->ui->got->display(this->got);
    this->ui->miss->display(this->miss);
    handler * hand = handler::getInstance();
    hand->setGetscore();
    hand->setMissscore();
    connect(hand,SIGNAL(beatWoof()),this,SLOT(UpdateScore()));
    connect(hand,SIGNAL(setscore()),this,SLOT(ResetScore()));
    connect(hand,SIGNAL(setcounter()),this,SLOT(SetCounter()));
    connect(hand,SIGNAL(startcounter()),this,SLOT(StartCounter()));
    connect(hand,SIGNAL(getscore()),this,SLOT(GetScore()));
    connect(hand,SIGNAL(missscore()),this,SLOT(MissScore()));
    connect(hand,SIGNAL(setgetscore()),this,SLOT(SetGetscore()));
    connect(hand,SIGNAL(setmissscore()),this,SLOT(SetMissscore()));

}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::UpdateScore(){//加分
    this->score +=10;
    this->ui->lcdNumber->display(this->score);
}

void MainWindow::ResetScore(){//分数复位
    this->score = 0;
    this->ui->lcdNumber->display(this->score);
}

void MainWindow::StartCounter()//倒计时
{
    if(this->count>0){
        this->count -= 1;
        this->ui->TimeCounter->display(this->count);
    }
    else {

        sc->stopGame();
        //QString Score = QString::number(this->score);
        //connect(this,SIGNAL(sendScore(QString)),this->subtest,SLOT(scoreNum(QString)));
        //emit sendScore(Score);
        //int globalScore = this->score;


    }
}

void MainWindow::SetCounter()//计时器复位
{
    this->count = 60;
    this->ui->TimeCounter->display(this->count);
}

void MainWindow::GetScore(){//打中次数
    this->got+=1;
    this->ui->got->display(this->got);
}

void MainWindow::MissScore(){//打失次数
    this->miss+=1;
    this->ui->miss->display(this->miss);
}

void MainWindow::SetGetscore(){//打中复位
    this->got=0;
    this->ui->got->display(this->got);
}

void MainWindow::SetMissscore(){//打失复位
    this->miss=0;
    this->ui->miss->display(this->miss);
}


