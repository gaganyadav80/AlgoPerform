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

MainWindow::~MainWindow()
{
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


void MainWindow::on_githubButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/gaganyadav80/AlgoPerform", QUrl::TolerantMode));
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

