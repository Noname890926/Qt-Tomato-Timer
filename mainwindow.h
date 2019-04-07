#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void updateTime();

    void on_WorkingTimer_overflow();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer * _timer;      //定时器 每秒更新时间
    QTime * _TimeRecord;  //记录时间
    bool _isStart;        //记录是否已经开始计时
};

#endif // MAINWINDOW_H
