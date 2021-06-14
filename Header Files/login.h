#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include "string"
#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_submitLogin_clicked();
    QString Donor_Or_Recipient(QString id);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
