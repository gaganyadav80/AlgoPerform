#ifndef SORTINGWINDOW_H
#define SORTINGWINDOW_H

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

private:
    Ui::SortingWindow *ui;
};

#endif // SORTINGWINDOW_H
