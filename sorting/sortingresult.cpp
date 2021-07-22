#include "sortingresult.h"
#include "ui_sortingresult.h"

SortingResult::SortingResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SortingResult)
{
    ui->setupUi(this);
}

SortingResult::~SortingResult()
{
    delete ui;
}

