#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sortingwindow.h"

#include <QUrl>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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

