#ifndef EXERCISESWINDOW_H
#define EXERCISESWINDOW_H

#include <QDialog>
#include <qlistwidget.h>
#include <qnetworkreply.h>

namespace Ui {
class ExercisesWindow;
}

class ExercisesWindow : public QDialog {
  Q_OBJECT

public:
  explicit ExercisesWindow(QWidget *parent = nullptr);
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
    Abs = 10
  };
  static constexpr std::initializer_list<MuscleGroups> allMuscleGroups = {
      Chest, Traps, FrontDelts, LateralDelts, RearDelts, Back, Lats, LowerBack, Biceps, Triceps, Abs
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

  struct Exercise {
    int reps = 0;
    int series = 0;
    QString name = "";
    int mainMuscleGroup = 0;
    std::vector<MuscleGroups> muscle_groups;
  } exercise;

 signals:
  void choosenExercise(const Exercise & exercise);

private slots:
  void on_listWidget_currentRowChanged(int currentRow);
  void on_SeriesSlider_sliderMoved(int position);
  void on_RepsSlider_sliderMoved(int position);
  void on_btnClose_clicked();
  void on_btnOK_clicked();
  void managerFinished(QNetworkReply *reply);

  void on_comboBox_currentIndexChanged(int index);

private:
  void UpdateTotalReps();
  Ui::ExercisesWindow *ui;
  void LoadComboBoxExercises();
  void LoadExercises(int muscleGroup);

  int mySeries = 1, myReps = 1;
};

#endif // EXERCISESWINDOW_H
