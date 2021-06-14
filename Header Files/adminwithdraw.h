#ifndef ADMINWITHDRAW_H
#define ADMINWITHDRAW_H

#include <QDialog>

using namespace std;
namespace Ui {
class AdminWithdraw;
}

class AdminWithdraw : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWithdraw(QWidget *parent = nullptr);
    ~AdminWithdraw();
    bool CheckRequest(string b, string q);

private slots:
    void on_WITHDRAW_clicked();

    void on_cancel_clicked();

private:
    Ui::AdminWithdraw *ui;
};

#endif // ADMINWITHDRAW_H
