#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBarCategoryAxis>
#include <QBarSet>
#include <QRandomGenerator>
#include <QValueAxis>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // LoadChart();
    LoadImage();

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(
                QHeaderView::Stretch);
    // ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void MainWindow::LoadChart() {
    // Initialize chart
    series = new QBarSeries();
    chart = new QChart();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    weekDays << "L" << "M"  << "X" << "J"  << "V" << "S" << "D";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(weekDays);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    int topValue = 15;
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, topValue);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    ExercisesWindow::MuscleGroupNames m;
    for (auto e : ExercisesWindow::allMuscleGroups) {
        QBarSet *set0 = new QBarSet(m.getMuscleGroupName(e));
        for (const auto &c : weekDays) {
            *set0 << QRandomGenerator::global()->bounded(topValue);
        }
        series->append(set0);
    }
    chart->addSeries(series);

    // Initialize chartView
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->chartView->addWidget(chartView);
}

void MainWindow::LoadImage() {
    QPixmap pixmap("D:/Felix/Code/workout_maker/images/vitruvian.jpg");
    ui->label->setMinimumWidth(pixmap.width());
    ui->label->setMinimumHeight(pixmap.height());

    int w = ui->label->width(), h = ui->label->height();
    ui->label->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::UpdateChart() {
    /*
    chart->removeAllSeries();
    series = new QBarSeries();

    ExercisesWindow::MuscleGroupNames m;
    for (const auto &e : workoutPlan) {
        for(const auto &i : e.second){
            QBarSet *set0 = new QBarSet(m.getMuscleGroupName(i.mainMuscleGroup));
            for (const auto &c : weekDays) {
                *set0 << (i.series * i.reps);
            }
            series->append(set0);
        }
    }
    chart->addSeries(series);
    */
}

void MainWindow::PrintExercise(ExercisesWindow::Exercise ex) {
    QString text = ex.name + " (" + QString::number(ex.series) + "x" +
            QString::number(ex.reps) + ")";
    ui->tableWidget->setItem(exerciseRow, exerciseColumn,
                             new QTableWidgetItem(text));

    SaveWorkout(exerciseColumn, ex);
    UpdateChart();
}

void MainWindow::SaveWorkout(int exerciseColumn, ExercisesWindow::Exercise ex) {
    auto isPresent = workoutPlan.find(exerciseColumn); // returns an iterator
    if (isPresent != workoutPlan.end()) {
        isPresent->second.push_back(ex);
    } else {
        workoutPlan.insert(
                    {exerciseColumn, std::vector<ExercisesWindow::Exercise>{ex}});
    }
}

void MainWindow::OpenExercisesWindow() {
    ExercisesWindow exercisesWindow(nullptr);
    exercisesWindow.setModal(true);
    QObject::connect(
                &exercisesWindow, &ExercisesWindow::choosenExercise,
                [&](const ExercisesWindow::Exercise ex) { PrintExercise(ex); });
    exercisesWindow.exec();
}

void MainWindow::on_tableWidget_cellClicked(int row, int column) {
    exerciseColumn = column;
    exerciseRow = row;
    OpenExercisesWindow();
}
