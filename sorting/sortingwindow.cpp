#include "sortingwindow.h"
#include "ui_sortingwindow.h"
#include "sorting/sortingperform.h"
#include "sortingresult.h"

#include <QtCharts>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

SortingWindow::SortingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SortingWindow)
{
    ui->setupUi(this);
}

SortingWindow::~SortingWindow()
{
    delete ui;
}

void SortingWindow::on_closeButton_clicked()
{
    this->close();
}


void SortingWindow::on_radio10_3_clicked()
{
    Variables *var = Variables::getInstance();
    var->setSize(1000);
}


void SortingWindow::on_radio10_4_clicked()
{
    Variables *var = Variables::getInstance();
    var->setSize(10000);
}


void SortingWindow::on_radio22_10_4_clicked()
{
    Variables *var = Variables::getInstance();
    var->setSize(2.2*10000);
}


void SortingWindow::on_radio34_10_4_clicked()
{
    Variables *var = Variables::getInstance();
    var->setSize(3.4*10000);
}

QChartView* generateSortingResultChart(unordered_map<string, int> map);

void SortingWindow::on_startButton_clicked()
{
    SortingDialog *dialog =new SortingDialog();
    dialog->show();

    unordered_map<string, int> results = execSortingPerform();
    cout<<endl<<"generating chart"<<endl;
    QChartView* chartView = generateSortingResultChart(results);

    dialog->close();
    sortingResult =new SortingResult(this);
    sortingResult->setCentralWidget(chartView);
    sortingResult->show();
}

QChartView* generateSortingResultChart(unordered_map<string, int> umap) {
    QBarSet *set0 = new QBarSet("Insertion Sort");
    QBarSet *set1 = new QBarSet("Bubble Sort");
    QBarSet *set2 = new QBarSet("Selection Sort");
    QBarSet *set3 = new QBarSet("Quick Sort");
    QBarSet *set4 = new QBarSet("Merge Sort");

    cout<<umap["insertion"]<<" "<<umap["bubble"]<<" "<<umap["selection"]<<" "<<umap["quick"]<<" "<<umap["merge"]<<endl;

    *set0 << umap["insertion"];
    *set1 << umap["bubble"];
    *set2 << umap["selection"];
    *set3 << umap["quick"];
    *set4 << umap["merge"];

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Sorting Algorithm Performance");
    chart->setAnimationOptions(QChart::SeriesAnimations);

//   QStringList categories;
//   categories << "Array of size" << to_string(size);
//   QBarCategoryAxis *axisX = new QBarCategoryAxis();
//   axisX->append(categories);
//   chart->addAxis(axisX, Qt::AlignBottom);
//   series->attachAxis(axisX);

    Variables *var = Variables::getInstance();

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100*var->getSize());
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

