#ifndef SORTINGDIALOG_H
#define SORTINGDIALOG_H

#include <QMainWindow>

namespace Ui {
class SortingDialog;
}

class SortingDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortingDialog(QWidget *parent = nullptr);
    ~SortingDialog();

private:
    Ui::SortingDialog *ui;
};

#endif // SORTINGDIALOG_H
