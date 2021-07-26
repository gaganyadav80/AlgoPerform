#ifndef INSERTIONRESULT_H
#define INSERTIONRESULT_H

#include <QMainWindow>

namespace Ui {
class InsertionResult;
}

class InsertionResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit InsertionResult(QWidget *parent = nullptr);
    ~InsertionResult();

private:
    Ui::InsertionResult *ui;
};

#endif // INSERTIONRESULT_H
