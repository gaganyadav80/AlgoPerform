#ifndef SORTINGRESULT_H
#define SORTINGRESULT_H

#include <QMainWindow>

namespace Ui {
class SortingResult;
}

class SortingResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortingResult(QWidget *parent = nullptr);
    ~SortingResult();

private:
    Ui::SortingResult *ui;
};

#endif // SORTINGRESULT_H
