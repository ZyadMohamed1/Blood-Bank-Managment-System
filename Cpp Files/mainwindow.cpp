#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Recipient.h"
#include "QMessageBox"
#include "donorregister.h"
#include "recipientregister.h"
#include "login.h"
#include "recipientmainwindow.h"
#include "checkresults.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Register_clicked()
{

    QMessageBox msg;
    QMessageBox msgBox;
    msgBox.setText("Register As Donor or Recipient ? ");
    QPushButton *donorButton = msgBox.addButton(tr("Donor"), QMessageBox::ActionRole);
    QPushButton *close = msgBox.addButton(tr("Close"), QMessageBox::AcceptRole);
    QPushButton *recipientButton = msgBox.addButton(tr("Recipient"), QMessageBox::ActionRole);


    msgBox.exec();

    if (msgBox.clickedButton() == donorButton) {
        // donor
        DonorRegister reg;
        reg.setModal(true);
        reg.exec();
    } else if (msgBox.clickedButton() == recipientButton) {
        // recipient
        RecipientRegister regR;
        regR.setModal(true);
        regR.exec();
    }
    else if (msgBox.clickedButton() == close){
        msg.hide();
    }


}



void MainWindow::on_Request_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("You have to Register or Login First !");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();

}


void MainWindow::on_Donate_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("You have to Register or Login First !");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}





void MainWindow::on_Login_clicked()
{
    Login log;
    log.setModal(true);
    log.exec();
}


void MainWindow::on_Check_clicked()
{
    CheckResults CR;
    CR.setModal(true);
    CR.exec();
}


void MainWindow::on_play_clicked()
{

}

