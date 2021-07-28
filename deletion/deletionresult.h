#ifndef DELETIONRESULT_H
#define DELETIONRESULT_H

#include <QMainWindow>

namespace Ui {
class DeletionResult;
}

class DeletionResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeletionResult(QWidget *parent = nullptr);
    ~DeletionResult();

private:
    Ui::DeletionResult *ui;
};

#endif // DELETIONRESULT_H
