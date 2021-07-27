#include "insertionwindow.h"
#include "ui_insertionwindow.h"

#include "insertionperform.h"

#include <QtCharts>
#include <bits/stdc++.h>

using namespace std;

InsertionWindow::InsertionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InsertionWindow)
{
    ui->setupUi(this);
}

InsertionWindow::~InsertionWindow()
{
    delete ui;
}

void InsertionWindow::on_closeButton_clicked()
{
    this->close();
}

QChartView* generateInsertionResultChart(unordered_map<string, int> map);

void InsertionWindow::on_startButton_clicked()
{
    unordered_map<string, int> insertionResults = execInsertionPerform();
    cout<<endl<<"generating searching chart"<<endl;
    QChartView* chartView = generateInsertionResultChart(insertionResults);

    insertionResult =new InsertionResult(this);
    insertionResult->setCentralWidget(chartView);
    insertionResult->show();
}

QChartView* generateInsertionResultChart(unordered_map<string, int> insertionMap) {
    QBarSet *set0 = new QBarSet("Array Insertion at random Index");
    QBarSet *set1 = new QBarSet("Linked list insertion at end");
    QBarSet *set2 = new QBarSet("BST insertion at end");

    cout<<"Insertion Results = "<<insertionMap["instarray"]<<" "<<insertionMap["instllist"]<<" "<<insertionMap["instbst"]<<endl;

    *set0 << insertionMap["instarray"];
    *set1 << insertionMap["instllist"];
    *set2 << insertionMap["instbst"];

    QBarSeries *series = new QBarSeries();
    series->setLabelsVisible(true);
    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Insertion Algorithm Performance");
    chart->setAnimationOptions(QChart::SeriesAnimations);

//    QStringList categories;
//    categories << "Array" << "Tree";
//    QBarCategoryAxis *axisX = new QBarCategoryAxis();
//    axisX->append(categories);
//    chart->addAxis(axisX, Qt::AlignBottom);
//    series->attachAxis(axisX);

    Variables *var = Variables::getInstance();

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, var->getSize() * 0.053);
    axisY->applyNiceNumbers();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
