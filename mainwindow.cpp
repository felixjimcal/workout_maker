#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QValueAxis>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  series = new QLineSeries();
  series->append(0, 6);
  series->append(2, 4);
  *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6)
          << QPointF(18, 3) << QPointF(20, 2);

  chart = new QChart();
  chart->legend()->hide();
  chart->addSeries(series);
  chart->createDefaultAxes();
  chart->setTitle("Simple line chart example");

  chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);
  chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  ui->chartView->addWidget(chartView);

  // ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  // ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  // series->attachedAxes().at(0)->setMax(counterX+1);
  // series->attachedAxes().at(1)->setMax(counterY+1);
}

void MainWindow::PrintExercise(ExercisesWindow::Exercise ex) {
  qDebug() << ex.name;
  // Aqui actualizamos el grafico de ejercicios
}

void MainWindow::on_tableWidget_cellClicked(int row, int column) {
  ExercisesWindow exercisesWindow(nullptr, row);
  exercisesWindow.setModal(true);
  QObject::connect(&exercisesWindow, &ExercisesWindow::choosenExercise, [&](const ExercisesWindow::Exercise ex) {
      PrintExercise(ex);
  });
  exercisesWindow.exec();
}
