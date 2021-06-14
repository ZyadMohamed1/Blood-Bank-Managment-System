#include "recipientmainwindow.h"
#include "ui_recipientmainwindow.h"
#include "QPalette"
#include "showallblood.h"
#include "string"
#include "Recipient.h"
#include "QMessageBox"
#include "QFile"
#include "searchbloodtype.h"
#include "updateform.h"
#include "deleteaccount.h"
#include "fstream"
#include "showrecipientrequests.h"

using namespace std;

RecipientMainWindow::RecipientMainWindow(QString userID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecipientMainWindow)
{
    ui->setupUi(this);

    this->userID=userID;

    int lineSelector = 0;
    string resLine ;
    fstream USERFile;
    USERFile.open(userID.toStdString());
    while (getline(USERFile,resLine))
    {
        switch(lineSelector){
       case 2:{
            QString qString = QString::fromStdString(resLine);
            ui->label_9->setText("Welcome, "+qString);
            lineSelector++;
            break;
        }
        case 8:{
             QString qString = QString::fromStdString(resLine);
             hospital = qString;
             lineSelector++;
             break;
         }
        default:
            lineSelector++;
        }
    }
    USERFile.close();


}

bool RecipientMainWindow::CheckRequests(string b, string q){
    int Adder=0;
    int lineSelector = 0;
    string resLine ;
    fstream BloodFile;
    BloodFile.open(b);
   while(!BloodFile.eof()){
    while (getline(BloodFile,resLine))
    {


        switch(lineSelector){
       case 0:{
            QString qString = QString::fromStdString(resLine);
            lineSelector++;
            break;
        }
        case 1:{
             QString qString = QString::fromStdString(resLine);
             lineSelector++;
             break;
         }
        case 2:{
             QString qString = QString::fromStdString(resLine);
              Adder += qString.toInt();
             lineSelector++;
             break;
         }
        default:
            lineSelector++;
        }
    }
   }

    if(Adder >= std::stoi(q)){
        cout<<"Number of bags >= request"<<endl;
        return true;
    }
    else{
        cout<<"Number of bags < request"<<endl;
        return false;
    }

    BloodFile.close();



}

RecipientMainWindow::~RecipientMainWindow()
{
    delete ui;
}


void RecipientMainWindow::on_showAllBlood_clicked()
{
    showAllBlood sh;
    sh.setModal(true);
    sh.exec();
}


void RecipientMainWindow::on_BackButton_clicked()
{
    hide();
}


void RecipientMainWindow::on_requestButton_clicked()
{
    Recipient R;

    string bloodtype = ui->requestCombobox->currentText().toStdString();
    string quantity = ui->quantity->currentText().toStdString();

    bool flag = CheckRequests(bloodtype, quantity);


    if(flag == false){
        QMessageBox::information(nullptr/*or parent*/, "Done",
        QString("This number of bags not available right now!"));
    }
    else if(flag == true){
    //cout<<bloodtype<<" "<<quantity<<endl;

    R.recipientRequest(bloodtype, quantity);
    QMessageBox::information(nullptr/*or parent*/, "Done",
    QString(" Your Request Has been sent to your Nearest Hospital : " + hospital));

    }

}



void RecipientMainWindow::on_searchButton_clicked()
{
    searchBloodType sh;
    sh.setModal(true);
    sh.exec();

}



void RecipientMainWindow::on_updateRecipient_clicked()
{
    UpdateForm up(userID);
    up.setModal(true);
    up.exec();
}


void RecipientMainWindow::on_deleteRecipient_clicked()
{
    DeleteAccount DA;
    DA.setModal(true);
    DA.exec();
}

