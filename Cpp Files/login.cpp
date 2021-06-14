#include "login.h"
#include "ui_login.h"
#include "Donor.h"
#include "Recipient.h"
#include "QFile"
#include "QMessageBox"
#include "recipientmainwindow.h"
#include "donormainwindow.h"
#include "updateform.h"
#include "adminpage.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}

QString Login::Donor_Or_Recipient(QString id){


    QFile inputFile("C:\\Users\\Zyad\\Documents\\build-Blood-Desktop_Qt_6_1_0_MinGW_64_bit-Debug\\"+id);
    QString line;
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          line = in.readLine();
          break;
       }

       return line;

       inputFile.close();
    }
}

void Login::on_submitLogin_clicked()
{
    User u;


    QString check = ui->loginID->text();
    QString publicId = ui->loginID->text();
    string id = ui->loginID->text().toStdString();
    string pass = ui->loginPassword->text().toStdString();
    bool access = u.login(id,pass);

    if(access == true){
        hide();
        QString user = Donor_Or_Recipient(check);

        if(user == "Donor"){
            //open Donor Page
            DonorMainWindow DM(publicId);
            DM.setModal(true);
            DM.exec();

        }
        else if(user=="Recipient"){
            //Open Recipient Page
            RecipientMainWindow RM(publicId);
            RM.setModal(true);
            RM.exec();
        }

    }
    else if(id == "Admin" && pass == "Admin"){
        hide();
        AdminPage Admin;
        Admin.setModal(true);
        Admin.exec();
    }
    else{
        QMessageBox::information(nullptr/*or parent*/, "Important",
            QString("Your ID or Password is Incorrect"));


    }


}

