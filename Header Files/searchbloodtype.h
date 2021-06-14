#ifndef SEARCHBLOODTYPE_H
#define SEARCHBLOODTYPE_H

#include <QDialog>

namespace Ui {
class searchBloodType;
}

class searchBloodType : public QDialog
{
    Q_OBJECT

public:
    explicit searchBloodType(QWidget *parent = nullptr);
    ~searchBloodType();

private slots:
    void on_pushButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::searchBloodType *ui;
};

#endif // SEARCHBLOODTYPE_H
