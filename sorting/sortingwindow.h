#ifndef SORTINGWINDOW_H
#define SORTINGWINDOW_H

#include "sortingresult.h"

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

private:
    Ui::SortingWindow *ui;
    SortingResult *sortingResult;
};

#endif // SORTINGWINDOW_H
