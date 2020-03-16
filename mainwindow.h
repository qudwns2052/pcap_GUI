#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <unistd.h>
#include <pcap.h>
#include "qcustomplot.h"
#include "threadtest.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ThreadTest * m_thread;
    QCPBars *myBars;
private slots:
    void realtimeData(const int value);
    void on_pbStart_clicked();
};

#endif // MAINWINDOW_H
