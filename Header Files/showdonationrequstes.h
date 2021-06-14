#ifndef SHOWDONATIONREQUSTES_H
#define SHOWDONATIONREQUSTES_H

#include <QDialog>
#include <fstream>
#include <QCloseEvent>
using namespace std;
namespace Ui {
class showDonationRequstes;
}

class showDonationRequstes : public QDialog
{
    Q_OBJECT

public:
    explicit showDonationRequstes(QWidget *parent = nullptr);
    void getDonorInfo(string  );
    void acceptDonationRequest(string );
    void rejectDonationRequest(string );
    ~showDonationRequstes();

private slots:
    void on_SHOW_clicked();

    void on_ACCEPT_clicked();

    void on_showDonationRequstes_destroyed();

    void on_save_clicked();

    void on_REJECT_clicked();

    void on_Exit_clicked();

    void on_Cancel_clicked();

private:
    Ui::showDonationRequstes *ui;
};

#endif // SHOWDONATIONREQUSTES_H
