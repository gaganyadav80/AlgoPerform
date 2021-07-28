#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sorting/sortingwindow.h"
#include "searching/searchingwindow.h"
#include "insertion/insertionwindow.h"
#include "deletion/deletionwindow.h"

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

    void on_searchingButton_clicked();

    void on_radio10_3_clicked();

    void on_radio10_4_clicked();

    void on_radio22_10_4_clicked();

    void on_radio34_10_4_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_insertionButton_clicked();

    void on_deletionButton_clicked();

private:
    Ui::MainWindow *ui;
    SortingWindow *sorting;
    SearchingWindow *searching;
    InsertionWindow *insertion;
    DeletionWindow *deletion;
};
#endif // MAINWINDOW_H
