#ifndef SHOWALLBLOOD_H
#define SHOWALLBLOOD_H

#include <QDialog>

namespace Ui {
class showAllBlood;
}

class showAllBlood : public QDialog
{
    Q_OBJECT

public:
    explicit showAllBlood(QWidget *parent = nullptr);
    ~showAllBlood();

private slots:
    void on_pushButton_clicked();

    void on_BackButton_clicked();

private:
    Ui::showAllBlood *ui;
};

#endif // SHOWALLBLOOD_H
