#include "exerciseswindow.h"
#include "ui_exerciseswindow.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QListWidgetItem>
#include <QRadioButton>

ExercisesWindow::ExercisesWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::ExercisesWindow) {
    ui->setupUi(this);

    LoadComboBoxExercises();
}

ExercisesWindow::~ExercisesWindow() { delete ui; }

void ExercisesWindow::LoadComboBoxExercises() {
    MuscleGroupNames m;
    for (auto e : allMuscleGroups) {
        ui->comboBox->addItem(mgNames.getMuscleGroupName(e));
    }
}

void ExercisesWindow::LoadExercises(int muscleGroup) {
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QObject::connect(manager, &QNetworkAccessManager::finished, this,
                     &ExercisesWindow::managerFinished);
    manager->get(QNetworkRequest(QUrl("http://127.0.0.1:8000/musclegroups/" + QString::number(muscleGroup) + "/exercises")));
}

void ExercisesWindow::managerFinished(QNetworkReply *reply) {
    QString ReplyText = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(ReplyText.toUtf8());
    QJsonObject obj = doc.object();
    QJsonArray json_exercises = obj["exercises"].toArray();
    foreach (const QJsonValue &value, json_exercises) {
        exercise.name = value["name"].toString();
        QJsonArray array = value["muscle_groups"].toArray();
        foreach (const QJsonValue &muscleGroup, array) {
            exercise.muscle_groups.push_back(MuscleGroups(muscleGroup.toInt(0)));
        }
        QVariant v = QVariant::fromValue(exercise);
        QListWidgetItem *listItem = new QListWidgetItem(exercise.name);
        listItem->setData(Qt::UserRole, v);
        ui->listWidget->addItem(listItem);
    }
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
    exercise.mainMuscleGroup = ui->comboBox->currentIndex();
    exercise.muscle_groups =
            QVariant::fromValue(ui->listWidget->currentItem()->data(Qt::UserRole))
            .value<Exercise>()
            .muscle_groups;
    emit choosenExercise(exercise);
    close();
}

void ExercisesWindow::on_comboBox_currentIndexChanged(int index)
{
    qDebug() << index;
}

