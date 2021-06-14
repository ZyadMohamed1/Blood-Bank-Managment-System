#ifndef DONORREGISTER_H
#define DONORREGISTER_H

#include <QDialog>

namespace Ui {
class DonorRegister;
}

class DonorRegister : public QDialog
{
    Q_OBJECT

public:
    explicit DonorRegister(QWidget *parent = nullptr);
    ~DonorRegister();

private slots:
    void on_submitDonor_clicked();
    int getIdNumber();

private:
    Ui::DonorRegister *ui;
};

#endif // DONORREGISTER_H
