#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QChartView>
#include <QLineSeries>
#include <QChart>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLineSeries* series = new QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->chartView->addWidget(chartView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addColumnBtn_clicked()
{
    int tableColumns = ui->tableWidget->columnCount();
    if(tableColumns < 7){
        ui->tableWidget->insertColumn(tableColumns);
    }
}

