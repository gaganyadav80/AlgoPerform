#include "sortingwindow.h"
#include "ui_sortingwindow.h"

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

