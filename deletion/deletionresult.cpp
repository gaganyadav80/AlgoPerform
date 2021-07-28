#include "deletionresult.h"
#include "ui_deletionresult.h"

DeletionResult::DeletionResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeletionResult)
{
    ui->setupUi(this);
}

DeletionResult::~DeletionResult()
{
    delete ui;
}
