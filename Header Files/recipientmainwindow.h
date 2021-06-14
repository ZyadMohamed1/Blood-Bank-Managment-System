#ifndef RECIPIENTMAINWINDOW_H
#define RECIPIENTMAINWINDOW_H

#include <QDialog>
#include "Recipient.h"
namespace Ui {
class RecipientMainWindow;
}

class RecipientMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RecipientMainWindow(QString userID, QWidget *parent = nullptr);
    ~RecipientMainWindow();
    bool CheckRequests(string b, string q);
    QString getType();
    QString userID;
    QString hospital;

private slots:
    void on_showAllBlood_clicked();

    void on_BackButton_clicked();

    void on_requestButton_clicked();

    void on_searchButton_clicked();



    void on_updateRecipient_clicked();

    void on_deleteRecipient_clicked();

private:
    Ui::RecipientMainWindow *ui;
};

#endif // RECIPIENTMAINWINDOW_H
