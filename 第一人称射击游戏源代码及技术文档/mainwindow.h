#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myscene.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void UpdateScore();
    void ResetScore();
    void StartCounter();
    void SetCounter();
    void GetScore();
    void MissScore();
    void SetGetscore();
    void SetMissscore();

signals:
    //void sendScore(QString);

private:
    Ui::MainWindow *ui;
    myScene * sc;   
    int count;
    int score;
    int got;
    int miss;
};
#endif // MAINWINDOW_H
