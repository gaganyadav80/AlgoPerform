#include "searchingresult.h"
#include "ui_searchingresult.h"

SearchingResult::SearchingResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchingResult)
{
    ui->setupUi(this);
}

SearchingResult::~SearchingResult()
{
    delete ui;
}
