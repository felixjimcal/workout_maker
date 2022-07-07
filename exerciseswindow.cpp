#include "exerciseswindow.h"
#include "ui_exerciseswindow.h"
#include <QGroupBox>
#include <QListWidgetItem>
#include <QRadioButton>

ExercisesWindow::ExercisesWindow(QWidget *parent, int muscleGroup)
    : QDialog(parent), ui(new Ui::ExercisesWindow) {
  ui->setupUi(this);

  SetTitle(muscleGroup);
  LoadExercises(muscleGroup);
}

ExercisesWindow::~ExercisesWindow() { delete ui; }

void ExercisesWindow::SetTitle(int muscleGroup) {
  QString title = mgNames.getMuscleGroupName(muscleGroup);
  title += " Exercises";
  ui->label->setText(title);
}

void ExercisesWindow::LoadExercises(int muscleGroup) {
  // Aquí saldría a pedir la info a la API
  // https://helloacm.com/model-view-controller-explained-in-c/

  exercise.name = "Dips";
  exercise.muscle_groups.push_back(MuscleGroups::Chest);
  exercise.muscle_groups.push_back(MuscleGroups::FrontDelts);
  exercise.muscle_groups.push_back(MuscleGroups::Triceps);

  QVariant v = QVariant::fromValue(exercise);
  QListWidgetItem *dipsExercise = new QListWidgetItem(exercise.name);
  dipsExercise->setData(Qt::UserRole, v);
  ui->listWidget->addItem(dipsExercise);
}

void ExercisesWindow::on_listWidget_currentRowChanged(int currentRow) {
  ui->btnOK->setEnabled(true);
}

void ExercisesWindow::on_SeriesSlider_sliderMoved(int position) {
  mySeries = position;
  UpdateTotalReps();
}

void ExercisesWindow::on_RepsSlider_sliderMoved(int position) {
  myReps = position;
  UpdateTotalReps();
}

void ExercisesWindow::UpdateTotalReps() {
  ui->lblTotalReps->setText(QString::number(mySeries * myReps));
}

void ExercisesWindow::on_btnClose_clicked() { this->close(); }

void ExercisesWindow::on_btnOK_clicked() {
  exercise.series = mySeries;
  exercise.reps = myReps;
  exercise.name = ui->listWidget->currentItem()->text();
  exercise.muscle_groups = QVariant::fromValue(ui->listWidget->currentItem()->data(Qt::UserRole)).value<Exercise>().muscle_groups;
  emit choosenExercise(exercise);
  close();
}
