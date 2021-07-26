#include "insertionwindow.h"
#include "ui_insertionwindow.h"

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

