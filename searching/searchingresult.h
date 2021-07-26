#ifndef SEARCHINGRESULT_H
#define SEARCHINGRESULT_H

#include <QMainWindow>

namespace Ui {
class SearchingResult;
}

class SearchingResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchingResult(QWidget *parent = nullptr);
    ~SearchingResult();

private:
    Ui::SearchingResult *ui;
};

#endif // SEARCHINGRESULT_H
