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

  // Adding pages with content
  /*
QFrame *framePage1 = new QFrame;
QListWidget *listExercisesPage1 = new QListWidget(framePage1);

struct cat {
    int i = 0;
    std::string name = "Kiwi";
} gato;

QVariant v = QVariant::fromValue(gato);
QListWidgetItem *dipsExercise = new QListWidgetItem("Dips");
dipsExercise->setData(0, v);
QListWidgetItem *bpExercise = new QListWidgetItem("Bench Press");
listExercisesPage1->addItem(gato.name.c_str());
listExercisesPage1->addItem(bpExercise);
ui->toolBox->addItem(listExercisesPage1, "Chest + Triceps + Shoulders");
*/
}

void ExercisesWindow::on_listWidget_itemActivated(QListWidgetItem *item) {
  qDebug() << "bb";
}
