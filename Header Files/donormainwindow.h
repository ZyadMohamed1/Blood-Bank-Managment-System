#ifndef DONORMAINWINDOW_H
#define DONORMAINWINDOW_H

#include <QDialog>
#include <QPropertyAnimation>

namespace Ui {
class DonorMainWindow;
}

class DonorMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DonorMainWindow(QString userID, QWidget *parent = nullptr);
    ~DonorMainWindow();
    bool CheckDonation();
    QString userID;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::DonorMainWindow *ui;

    QPropertyAnimation *animation;
    void bloodAnimation();
};

#endif // DONORMAINWINDOW_H
