#ifndef SHOWALLBAGSINFO_H
#define SHOWALLBAGSINFO_H

#include <QDialog>

namespace Ui {
class showAllBagsInfo;
}

class showAllBagsInfo : public QDialog
{
    Q_OBJECT

public:
    explicit showAllBagsInfo(QWidget *parent = nullptr);
    ~showAllBagsInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::showAllBagsInfo *ui;
};

#endif // SHOWALLBAGSINFO_H
