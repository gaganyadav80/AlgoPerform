#include "deletionwindow.h"
#include "ui_deletionwindow.h"

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
