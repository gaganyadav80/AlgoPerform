#ifndef VISUALWINDOW_H
#define VISUALWINDOW_H

#include <QMainWindow>
#include "stack.h"
#include "bheap.h"
#include "queue.h"
#include "visualizer.h"

namespace Ui {
class VisualWindow;
}

class VisualWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VisualWindow(QWidget *parent = 0);
    ~VisualWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::VisualWindow *ui;
    stack stackui;
    Queue queueui;
    Bheap  bheapui;
};

#endif // VISUALWINDOW_H
