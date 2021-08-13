#include "searchingwindow.h"
#include "ui_searchingwindow.h"

#include "searchingperform.h"

#include <QtCharts>
#include <bits/stdc++.h>

using namespace std;

SearchingWindow::SearchingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchingWindow)
{
    ui->setupUi(this);
}

SearchingWindow::~SearchingWindow()
{
    delete ui;
}

void SearchingWindow::on_closeButton_clicked() {
    this->close();
}

QChartView* generateSearchingResultChart(unordered_map<string, int> searchMap);

void SearchingWindow::on_startButton_clicked()
{
    unordered_map<string, int> searchResults = execSearchingPerform();
    cout<<endl<<"generating searching chart"<<endl;
    QChartView* chartView = generateSearchingResultChart(searchResults);

    searchingResult =new SearchingResult(this);
    searchingResult->setCentralWidget(chartView);
    searchingResult->show();
}

QChartView* generateSearchingResultChart(unordered_map<string, int> searchMap) {
    QBarSet *set0 = new QBarSet("Linear Search [value*10]");
    QBarSet *set1 = new QBarSet("Binary Search");
    QBarSet *set2 = new QBarSet("Ternary Search");
    QBarSet *set3 = new QBarSet("BST Search [value*100]");
    QBarSet *set4 = new QBarSet("Linked List Search [value*10]");

    cout<<"Searching Results = "<<searchMap["linear"]<<" "<<searchMap["binary"]<<" "<<searchMap["ternary"];
    cout<<" "<<searchMap["bst"]<<" "<<searchMap["llist"]<<endl;

    *set0 << searchMap["linear"]*10;
    *set1 << searchMap["binary"];
    *set2 << searchMap["ternary"];
    *set3 << searchMap["bst"]*100;
    *set4 << searchMap["llist"]*10;

    QBarSeries *series = new QBarSeries();
    series->setLabelsVisible(true);
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Searching Algorithm Performance");
    chart->setAnimationOptions(QChart::SeriesAnimations);

//    QStringList categories;
//    categories << "Array" << "Tree";
//    QBarCategoryAxis *axisX = new QBarCategoryAxis();
//    axisX->append(categories);
//    chart->addAxis(axisX, Qt::AlignBottom);
//    series->attachAxis(axisX);

    Variables *var = Variables::getInstance();

    int yval = 0;
    switch(var->getSize()) {
    case 1000:
        yval = 200;
        break;
    case 10000:
        yval = 1000;
        break;
    case 22000:
        yval = 2500;
        break;
    case 34000:
        yval = 3500;
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

