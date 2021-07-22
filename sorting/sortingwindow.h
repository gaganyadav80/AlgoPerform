#ifndef SORTINGWINDOW_H
#define SORTINGWINDOW_H

#include "sortingresult.h"
#include "sortingdialog.h"

#include <QMainWindow>

namespace Ui {
class SortingWindow;
}

class SortingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortingWindow(QWidget *parent = nullptr);
    ~SortingWindow();

private slots:
    void on_closeButton_clicked();

    void on_startButton_clicked();

    void on_radio10_3_clicked();

    void on_radio10_4_clicked();

    void on_radio22_10_4_clicked();

    void on_radio34_10_4_clicked();

private:
    Ui::SortingWindow *ui;
    SortingResult *sortingResult;
};

#endif // SORTINGWINDOW_H
