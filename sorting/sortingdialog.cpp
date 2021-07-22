#include "sortingdialog.h"
#include "ui_sortingdialog.h"

SortingDialog::SortingDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SortingDialog)
{
    ui->setupUi(this);
}

SortingDialog::~SortingDialog()
{
    delete ui;
}
