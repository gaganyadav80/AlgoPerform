#ifndef DELETIONWINDOW_H
#define DELETIONWINDOW_H

#include "deletionresult.h"

#include <QMainWindow>

namespace Ui {
class DeletionWindow;
}

class DeletionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeletionWindow(QWidget *parent = nullptr);
    ~DeletionWindow();

private slots:
    void on_closeButton_clicked();
    void on_startButton_clicked();

private:
    Ui::DeletionWindow *ui;
    DeletionResult *deletionResult;
};

#endif // DELETIONWINDOW_H
