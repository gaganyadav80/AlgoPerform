#include "visualwindow.h"
#include "ui_visualwindow.h"

VisualWindow::VisualWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VisualWindow)
{
    ui->setupUi(this);
}

VisualWindow::~VisualWindow()
{
    delete ui;
}

void VisualWindow::on_pushButton_clicked()
{
    queueui.show();
}

void VisualWindow::on_pushButton_2_clicked()
{
    stackui.show();
}

void VisualWindow::on_pushButton_3_clicked()
{
    bheapui.show();
}
