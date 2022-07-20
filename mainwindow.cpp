#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

#include <QValueAxis>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  series = new QLineSeries();
  *series << QPointF(0, 1) << QPointF(1, 4) << QPointF(2, 1) << QPointF(3, 3)
          << QPointF(4, 1);

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
  chart->removeAllSeries();

  series = new QLineSeries();
  int top = QRandomGenerator::global()->bounded(20);
  for (int i = 0; i < top; i++) {
    *series << QPointF(i, QRandomGenerator::global()->bounded(top));
  }
  chart->addSeries(series);
  chart->createDefaultAxes();
}

void MainWindow::PrintExercise(ExercisesWindow::Exercise ex) {
  qDebug() << ex.name << " - " << ex.series << "x" << ex.reps << " - "
           << ex.muscle_groups;
  // Aqui actualizamos el grafico de ejercicios
}

void MainWindow::on_tableWidget_cellClicked(int row, int column) {
  ExercisesWindow exercisesWindow(nullptr, row);
  exercisesWindow.setModal(true);
  QObject::connect(
      &exercisesWindow, &ExercisesWindow::choosenExercise,
      [&](const ExercisesWindow::Exercise ex) { PrintExercise(ex); });
  exercisesWindow.exec();
}
