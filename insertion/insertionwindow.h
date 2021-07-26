#ifndef INSERTIONWINDOW_H
#define INSERTIONWINDOW_H

#include "insertionresult.h"

#include <QMainWindow>

namespace Ui {
class InsertionWindow;
}

class InsertionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InsertionWindow(QWidget *parent = nullptr);
    ~InsertionWindow();

private slots:
    void on_closeButton_clicked();

private:
    Ui::InsertionWindow *ui;
    InsertionResult *insertionResult;
};

#endif // INSERTIONWINDOW_H
