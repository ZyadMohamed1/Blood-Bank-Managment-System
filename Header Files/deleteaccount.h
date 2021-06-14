#ifndef DELETEACCOUNT_H
#define DELETEACCOUNT_H
#include "Filestream.h"
#include "fstream"
#include "QFile"
#include <QDialog>

namespace Ui {
class DeleteAccount;
}

class DeleteAccount : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteAccount(QWidget *parent = nullptr);
    ~DeleteAccount();
    void deleteAcc(string id, string pass);


private slots:
    void on_Delete_clicked();

private:
    Ui::DeleteAccount *ui;
};

#endif // DELETEACCOUNT_H
