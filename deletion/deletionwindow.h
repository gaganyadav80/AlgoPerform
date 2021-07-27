#ifndef DELETIONWINDOW_H
#define DELETIONWINDOW_H

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

private:
    Ui::DeletionWindow *ui;
};

#endif // DELETIONWINDOW_H
