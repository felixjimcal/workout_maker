#ifndef EXERCISESWINDOW_H
#define EXERCISESWINDOW_H

#include <QDialog>
#include <qlistwidget.h>

namespace Ui {
class ExercisesWindow;
}

class ExercisesWindow : public QDialog {
  Q_OBJECT

public:
  explicit ExercisesWindow(QWidget *parent = nullptr, int muscleGroup = 0);
  ~ExercisesWindow();

  enum MuscleGroups {
    Chest = 0,
    Traps = 1,
    FrontDelts = 2,
    LateralDelts = 3,
    RearDelts = 4,
    Back = 5,
    Lats = 6,
    LowerBack = 7,
    Biceps = 8,
    Triceps = 9,
    Abs = 10,
    Rest = 99
  };

  struct MuscleGroupNames {
    QString name = "";
    QString getMuscleGroupName(int mg) {
      switch (mg) {
      case MuscleGroups::Chest:
        name = "Chest";
        break;
      case MuscleGroups::Traps:
        name = "Traps";
        break;
      case MuscleGroups::FrontDelts:
        name = "Front Delts";
        break;
      case MuscleGroups::LateralDelts:
        name = "Lateral Delts";
        break;
      case MuscleGroups::RearDelts:
        name = "Rear Delts";
        break;
      case MuscleGroups::Back:
        name = "Back";
        break;
      case MuscleGroups::Lats:
        name = "Lats";
        break;
      case MuscleGroups::LowerBack:
        name = "Lower Back";
        break;
      case MuscleGroups::Biceps:
        name = "Biceps";
        break;
      case MuscleGroups::Triceps:
        name = "Triceps";
        break;
      case MuscleGroups::Abs:
        name = "Abs";
        break;
      }
      return name;
    }
  } mgNames;

private slots:
  void on_listWidget_itemActivated(QListWidgetItem *item);

private:
  Ui::ExercisesWindow *ui;
  void SetTitle(int muscleGroup);
  void LoadExercises(int muscleGroup);
  void DoubleClickedExercise(QListWidgetItem *item);
};

#endif // EXERCISESWINDOW_H
