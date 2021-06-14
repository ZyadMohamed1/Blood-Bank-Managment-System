#include "donorregister.h"
#include "ui_donorregister.h"
#include <string>
#include "Donor.h"
#include "QFile"
#include "QIODevice"
#include "QMessageBox"
#include "QTextStream"
#include "regex"

DonorRegister::DonorRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DonorRegister)
{
    ui->setupUi(this);
}

DonorRegister::~DonorRegister()
{
    delete ui;
}

bool Email_check(string email)
{
     const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}


int DonorRegister::getIdNumber()
{

    int numberOfLines = 1;

    QFile inputFile("C:\\Users\\Zyad\\Documents\\build-Blood-Desktop_Qt_6_1_0_MinGW_64_bit-Debug\\Dindex");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          numberOfLines++;
       }

       return numberOfLines;

       inputFile.close();
    }

}

void DonorRegister::on_submitDonor_clicked()
{
    //here you will generate the new id for the user

    int ID = getIdNumber();
    QString num = QString::number(ID);

     string id = to_string(ID);
     string Name = ui->NameDonor->text().toStdString();
     string mail = ui->emailDonor->text().toStdString();
     string password = ui->passwordDonor->text().toStdString();
     string age = ui->DonorAge->text().toStdString();
     string gender = ui->GenderDonor->currentText().toStdString();
     string blood_type = ui->bloodTypeDonor->currentText().toStdString();
     string sick = ui->DonorSuffer->currentText().toStdString();
     string medicin = ui->medicinDonor->toPlainText().toStdString();
     string last_donation_date = ui->dateLastDonation->text().toStdString();

     if(!Email_check(mail)){
         QMessageBox::information(nullptr/*or parent*/, "Important",
             QString("The email is incorrect"));
     }
     else if(password.size() < 6){
         QMessageBox::information(nullptr/*or parent*/, "Important",
             QString("The Password should be more than 6 character"));
     }
     else if(age.empty() || age == "0"){
         QMessageBox::information(nullptr/*or parent*/, "Important",
             QString("Enter your age!"));
     }
     else if(sick.empty()){
         QMessageBox::information(nullptr/*or parent*/, "Important",
             QString("If you have any disease choose it!"));
     }
     else if(last_donation_date.empty()){
         QMessageBox::information(nullptr/*or parent*/, "Important",
             QString("Enter your last donation date!"));
     }
     else{


    Donor D(id,Name,mail,password,age,gender,blood_type,sick,medicin,last_donation_date);

    QMessageBox::information(nullptr/*or parent*/, "Important",
        QString("The ID For Your Login is : "+num));

    hide();
}
}

