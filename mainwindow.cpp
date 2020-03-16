#include "mainwindow.h"
#include "ui_mainwindow.h"

static int n=0;

//QVector<double> valueData;
//QVector<double> keyData;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer;
    timer->start();
    timer->setInterval(1000);

//    keyData << 1 << 2;
//    valueData << 0 << 0;
//    myBars = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
//    myBars->setName("Bars Series 1");

    m_thread = new ThreadTest(this);

//    connect(timer, SIGNAL(timeout()), this, SLOT(realtimeData()));
    connect(m_thread, SIGNAL(lenValue(int)), this, SLOT(realtimeData(int)));

}


void MainWindow::realtimeData(const int value)
{
//    ui->customPlot->clearPlottables();
//    valueData[value]++;
//    myBars->setData(keyData, valueData);
//    ui->customPlot->rescaleAxes();
//    ui->customPlot->replot();

    ui->textBrowser->append(QString::number(value));
}


void MainWindow::on_pbStart_clicked()
{
    m_thread->start();
}



MainWindow::~MainWindow()
{
    delete ui;
}
