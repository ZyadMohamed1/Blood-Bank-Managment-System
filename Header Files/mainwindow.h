#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Register_clicked();

    void on_Request_clicked();

    void on_Donate_clicked();

    void on_Contact_clicked();

    void on_Login_clicked();

    void on_Check_clicked();

    void on_play_clicked();

private:

    Ui::MainWindow *ui;

    //Register *RegisterDialog;
    //test *registertest;
};
#endif // MAINWINDOW_H
