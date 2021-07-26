#include "insertionresult.h"
#include "ui_insertionresult.h"

InsertionResult::InsertionResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InsertionResult)
{
    ui->setupUi(this);
}

InsertionResult::~InsertionResult()
{
    delete ui;
}
