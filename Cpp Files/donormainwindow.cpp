#include "donormainwindow.h"
#include "ui_donormainwindow.h"
#include "QMessageBox"
#include "QTime"
#include "Donor.h"
#include "Filestream.h"
#include "updateform.h"
#include "deleteaccount.h"
DonorMainWindow::DonorMainWindow(QString userID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DonorMainWindow)
{
    ui->setupUi(this);

    this->userID=userID;


}

bool DonorMainWindow::CheckDonation(){

    fstream file;
    file.open("donationRequests");
    string line;

    while (!file.eof()) {
        getline(file, line);
        QString qString =  QString::fromStdString(line);
        if(qString == userID){
            return false;
        }
    }

    return true;

}

void DonorMainWindow::bloodAnimation()
{

    animation =new QPropertyAnimation(ui->blood, "geometry");
    int x = ui->blood->x();
    int y = ui->blood->y();
    animation->setDuration(2000);
    animation->setStartValue(ui->blood->geometry());
    animation->setEndValue(QRect(x+325,y,351,541));
    animation->start();
}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(2);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

DonorMainWindow::~DonorMainWindow()
{
    delete ui;
}


void DonorMainWindow::on_pushButton_clicked()
{

    bool flag = CheckDonation();

    if(flag == false){
        QMessageBox::information(nullptr/*or parent*/, "Important",
            QString("You made donation request before !"));
    }
    else{
    Filestream file;
    file.blood_donation(userID.toStdString());
    bloodAnimation();
    delay();
    QMessageBox::information(nullptr/*or parent*/, "Important",
        QString("Your Request Has been sent to the Admin"
                " Wait For Response"));


    }
}

void DonorMainWindow::on_pushButton_2_clicked()
{
    UpdateForm up(userID);
    up.setModal(true);
    up.exec();
}


void DonorMainWindow::on_pushButton_3_clicked()
{
DeleteAccount DA;
DA.setModal(true);
DA.exec();
}

