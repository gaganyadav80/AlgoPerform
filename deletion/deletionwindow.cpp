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
//    cout<<endl<<"generating deletion chart"<<endl;
    printLog("chart#0 Generate deletion algoperform chart");
    QChartView* chartView = generateDeletionResultChart(results);

    deletionResult =new DeletionResult(this);
    deletionResult->setCentralWidget(chartView);
    deletionResult->show();
}

QChartView* generateDeletionResultChart(unordered_map<string, int> result) {
    QBarSet *set0 = new QBarSet("Array deletion");
    QBarSet *set1 = new QBarSet("Linked list deletion");
    QBarSet *set2 = new QBarSet("BST deletion [value*10]");

//    cout<<"Insertion Results = "<<result["delarray"]<<" "<<result["delllist"]<<" "<<result["delbst"]<<endl;
    printResult(result, "Deletion");

    *set0 << result["delarray"];
    *set1 << result["delllist"];
    *set2 << result["delbst"] * 10;

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

    int yval = 0;
    switch(var->getSize()) {
    case 1000:
        yval = 50;
        break;
    case 10000:
        yval = 100;
        break;
    case 22000:
        yval = 150;
        break;
    case 34000:
        yval = 250;
        break;
    }

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, yval);
    axisY->applyNiceNumbers();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
