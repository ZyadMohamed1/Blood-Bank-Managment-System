#ifndef SHOWRECIPIENTREQUESTS_H
#define SHOWRECIPIENTREQUESTS_H

#include <QDialog>
#include "Recipient.h"
namespace Ui {
class showrecipientrequests;
}

class showrecipientrequests : public QDialog
{
    Q_OBJECT

public:
    explicit showrecipientrequests(QWidget *parent = nullptr);
    void getRecipientInfo(string);
    void acceptRecipientRequest(string );
    void rejectRecipientRequest(string );
    ~showrecipientrequests();

private slots:
    void on_ACCEPT_clicked();

    void on_REJECT_clicked();

    void on_SHOW_clicked();

    void on_save_clicked();

private:
    Ui::showrecipientrequests *ui;
};

#endif // SHOWRECIPIENTREQUESTS_H
