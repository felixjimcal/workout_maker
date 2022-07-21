#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "exerciseswindow.h"
#include <QChart>
#include <QChartView>
#include <QBarSeries>
#include <QMainWindow>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void LoadChart();

  void LoadImage();

private slots:
  void on_pushButton_clicked();
  void on_tableWidget_cellClicked(int row, int column);

private:
  Ui::MainWindow *ui;
  QBarSeries *series;
  QChart *chart;
  QChartView *chartView;
  int exerciseColumn = 0, exerciseRow = 0;
  std::map<int, std::vector<ExercisesWindow::Exercise>> workoutPlan;

  void UpdateChart();
  void OpenExercisesWindow();
  void PrintExercise(ExercisesWindow::Exercise ex);
  void SaveWorkout(int exerciseColumn, ExercisesWindow::Exercise ex);
};
#endif // MAINWINDOW_H
