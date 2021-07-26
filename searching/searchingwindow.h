#ifndef SEARCHINGWINDOW_H
#define SEARCHINGWINDOW_H

#include <QMainWindow>
#include "searchingresult.h"

namespace Ui {
class SearchingWindow;
}

class SearchingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchingWindow(QWidget *parent = nullptr);
    ~SearchingWindow();

private slots:
    void on_closeButton_clicked();

    void on_startButton_clicked();

private:
    Ui::SearchingWindow *ui;
    SearchingResult *searchingResult;
};

#endif // SEARCHINGWINDOW_H
