#ifndef CHECKRESULTS_H
#define CHECKRESULTS_H

#include <QDialog>

namespace Ui {
class CheckResults;
}

class CheckResults : public QDialog
{
    Q_OBJECT

public:
    explicit CheckResults(QWidget *parent = nullptr);
    ~CheckResults();

private slots:
    void on_checkButton_clicked();

private:
    Ui::CheckResults *ui;
};

#endif // CHECKRESULTS_H
