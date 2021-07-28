#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sorting/sortingwindow.h"
#include "globalvariable.h"

#include <QUrl>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Variables *var = Variables::getInstance();
    ui->spinBox->setValue(var->getElement());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_radio10_3_clicked() {
    Variables *var = Variables::getInstance();
    var->setSize(1000);
}
void MainWindow::on_radio10_4_clicked() {
    Variables *var = Variables::getInstance();
    var->setSize(10000);
}
void MainWindow::on_radio22_10_4_clicked() {
    Variables *var = Variables::getInstance();
    var->setSize(2.2*10000);
}
void MainWindow::on_radio34_10_4_clicked() {
    Variables *var = Variables::getInstance();
    var->setSize(3.4*10000);
}
void MainWindow::on_spinBox_valueChanged(int arg1) {
    Variables *var = Variables::getInstance();
    var->setElement(arg1);
}


void MainWindow::on_githubButton_clicked() {
    QDesktopServices::openUrl(QUrl("https://github.com/gaganyadav80/AlgoPerform", QUrl::TolerantMode));
}
void MainWindow::on_dsaButton_clicked() {
    QDesktopServices::openUrl(QUrl("https://practice.geeksforgeeks.org/courses/dsa-self-paced", QUrl::TolerantMode));
}
void MainWindow::on_certificationButton_clicked() {
    QDesktopServices::openUrl(QUrl("https://drive.google.com/file/d/1NWGDVov9QlVjdYv8d_n8rcT2CPh0t5VT/view?usp=sharing", QUrl::TolerantMode));
}


void MainWindow::on_sortingButton_clicked()
{
    sorting =new SortingWindow(this);
    sorting->show();
}


void MainWindow::on_searchingButton_clicked()
{
    searching =new SearchingWindow(this);
    searching->show();
}


void MainWindow::on_insertionButton_clicked()
{
    insertion =new InsertionWindow(this);
    insertion->show();
}


void MainWindow::on_deletionButton_clicked()
{
    deletion = new DeletionWindow(this);
    deletion->show();
}

void MainWindow::on_visualButton_clicked()
{
    visual.show();
}

