#ifndef RECIPIENTREGISTER_H
#define RECIPIENTREGISTER_H

#include <QDialog>

namespace Ui {
class RecipientRegister;
}

class RecipientRegister : public QDialog
{
    Q_OBJECT

public:
    explicit RecipientRegister(QWidget *parent = nullptr);
    ~RecipientRegister();

private slots:
    void on_submitRecipient_clicked();
    int getIdNumber();

private:
    Ui::RecipientRegister *ui;
};

#endif // RECIPIENTREGISTER_H
