#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>

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
    *_TimeRecord = _TimeRecord->addSecs(1);
    ui->WorkingTimer->display(_TimeRecord->toString("hh:mm:ss"));
}

void MainWindow::on_WorkingTimer_overflow()
{

}

void MainWindow::on_pushButton_clicked()
{
    _timer->start(1000);
    //while(true)
    //{
    //    ui->WorkingTimer->display(time.toString("hh:mm:ss"));
    //}
}
