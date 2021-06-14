#include "recipientregister.h"
#include "ui_recipientregister.h"
#include "Recipient.h"
#include "QFile"
#include "QMessageBox"
#include "QIODevice"
#include "regex"

RecipientRegister::RecipientRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecipientRegister)
{
    ui->setupUi(this);
}

RecipientRegister::~RecipientRegister()
{
    delete ui;
}

bool email_check(string email)
{
     const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}

int RecipientRegister::getIdNumber()
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


void RecipientRegister::on_submitRecipient_clicked()
{
    //here you will generate the new id for the user

        int ID = getIdNumber();
        QString num = QString::number(ID);

     string id = to_string(ID);
     string Name = ui->NameRecipient->text().toStdString();
     string mail = ui->emailRecipient->text().toStdString();
     string password = ui->PasswordRecipient->text().toStdString();
     string age = ui->AgeRecipient->text().toStdString();
     string gender = ui->genderRecipient->currentText().toStdString();
     string blood_type = ui->RecipientBloodType->currentText().toStdString();
     string Hospital = ui->hospitalRecipient->text().toStdString();
     string DoctoName = ui->doctorRecipient->text().toStdString();

     if(!email_check(mail)){
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
     else if(Hospital.empty()){
         QMessageBox::information(nullptr/*or parent*/, "Important",
             QString("Enter the nearest hospital to you!"));
     }
     else if(DoctoName.empty()){
         QMessageBox::information(nullptr/*or parent*/, "Important",
             QString("Enter the Doctor of the case!"));
     }
     else{

     Recipient R(id,Name,mail,password,age,gender,blood_type,Hospital,DoctoName);

     QMessageBox::information(nullptr/*or parent*/, "Important",
         QString("The ID For Your Login is : "+num));
      hide();
     }
}

