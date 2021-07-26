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

QChartView* generateSearchingResultChart(unordered_map<string, int> map);

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
    QBarSet *set0 = new QBarSet("Linear Search");
    QBarSet *set1 = new QBarSet("Binary Search");
    QBarSet *set2 = new QBarSet("Ternary Search");
    QBarSet *set3 = new QBarSet("BST Search");

    cout<<"Linear Search  "<<searchMap["linear"]<<endl;
    cout<<"Binary Search  "<<searchMap["binary"]<<endl;
    cout<<"Ternary Search "<<searchMap["ternary"]<<endl;
    cout<<"BST Search     "<<searchMap["bst"]<<endl;

    *set0 << searchMap["linear"];
    *set1 << searchMap["binary"];
    *set2 << searchMap["ternary"];
    *set3 << searchMap["bst"];

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

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

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, var->getSize() + (var->getSize()*0.3));
    axisY->applyNiceNumbers();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

