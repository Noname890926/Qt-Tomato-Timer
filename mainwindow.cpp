#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>

#define INTERVAL (1000)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _isStart = false;     //初始为还未计时
    _timer = new QTimer;  //初始化定时器
    _TimeRecord = new QTime(0, 0, 0); //初始化时间

    //QTime time = QTime::currentTime();
    ui->WorkingTimer->setDigitCount(8);
    ui->WorkingTimer->setSegmentStyle(QLCDNumber::Flat);
    ui->WorkingTimer->display(_TimeRecord->toString("hh:mm:ss"));

    connect(_timer,SIGNAL(timeout()),this,SLOT(updateTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    int ms = _TimeRecord->elapsed();

    QTime tmpTime(0, 0);
    tmpTime = tmpTime.addMSecs(ms);
    ui->WorkingTimer->display(tmpTime.toString("hh:mm:ss"));

    int m = tmpTime.minute();
    if (m >= 1) {
        _timer->stop();

        ui->RelaxTimer->display(666);
    }
}

void MainWindow::on_WorkingTimer_overflow()
{

}

void MainWindow::on_pushButton_clicked()
{
    if (_timer->isActive()) {
        _timer->stop();
    }

    _TimeRecord->setHMS(0, 0, 0);
    _TimeRecord->start();
    _timer->start(INTERVAL);
}
