#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sorting/sortingwindow.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_githubButton_clicked();

    void on_sortingButton_clicked();

private:
    Ui::MainWindow *ui;
    SortingWindow *sorting;
};
#endif // MAINWINDOW_H
