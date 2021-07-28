#include "deletionwindow.h"
#include "ui_deletionwindow.h"

#include "deletionperform.h"

#include <QtCharts>
#include <bits/stdc++.h>

using namespace std;

DeletionWindow::DeletionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeletionWindow)
{
    ui->setupUi(this);
}

DeletionWindow::~DeletionWindow()
{
    delete ui;
}

void DeletionWindow::on_closeButton_clicked()
{
    this->close();
}

QChartView* generateDeletionResultChart(unordered_map<string, int> umap);

void DeletionWindow::on_startButton_clicked()
{
    unordered_map<string, int> results = execDeletionPerform();
    cout<<endl<<"generating deletion chart"<<endl;
    QChartView* chartView = generateDeletionResultChart(results);

    deletionResult =new DeletionResult(this);
    deletionResult->setCentralWidget(chartView);
    deletionResult->show();
}

QChartView* generateDeletionResultChart(unordered_map<string, int> insertMap) {
    QBarSet *set0 = new QBarSet("Array deletion");
    QBarSet *set1 = new QBarSet("Linked list deletion");
    QBarSet *set2 = new QBarSet("BST deletion [value/100]");

    cout<<"Insertion Results = "<<insertMap["delarray"]<<" "<<insertMap["delllist"]<<" "<<insertMap["delbst"]<<endl;

    *set0 << insertMap["delarray"];
    *set1 << insertMap["delllist"];
    *set2 << insertMap["delbst"] * 100;

    QBarSeries *series = new QBarSeries();
    series->setLabelsVisible(true);
    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Deletion Algorithm Performance");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    Variables *var = Variables::getInstance();

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, var->getSize() * 0.06);
    axisY->applyNiceNumbers();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
