#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>

namespace Ui {
class AdminPage;
}

class AdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

private slots:
    void on_EXIT_clicked();

    void on_showAllInfo_clicked();

    void on_deposit_clicked();

    void on_showDonation_clicked();

    void on_pushButton_22_clicked();

    void on_EXIT_4_clicked();

private:
    Ui::AdminPage *ui;
};

#endif // ADMINPAGE_H
