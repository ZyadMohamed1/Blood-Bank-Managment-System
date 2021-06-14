#include "showdonationrequstes.h"
#include "ui_showdonationrequstes.h"
#include "qonationrequestqueue.h"
#include <QMessageBox>
showDonationRequstes::showDonationRequstes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showDonationRequstes)
{
    ui->setupUi(this);
    //when_close()
}
        qonationRequestQueue donorQueue;
void showDonationRequstes::getDonorInfo(string id)
{

    int lineSelector = 0;
    string resLine ;
    fstream USERFile;
    USERFile.open(id );
    while (getline(USERFile,resLine))
    {
        switch(lineSelector){
        case 1:{
        QString qString = QString::fromStdString(resLine);
        ui->ID->setPlainText(qString);
        lineSelector++;
            break;    }
       case 2:{
            QString qString = QString::fromStdString(resLine);
            ui->NAME->setPlainText(qString);
            lineSelector++;
            break;
        }
        case 3:{
            QString qString = QString::fromStdString(resLine);
            ui->MHISTORY->setPlainText(qString);
            lineSelector ++ ;
            break;
        }
        case 4:{
           QString qString = QString::fromStdString(resLine);
           ui->bloodtype->setPlainText(qString);
           lineSelector++;
           break;
        }
        case 6:{
           QString qString = QString::fromStdString(resLine);
           ui->AGE->setPlainText(qString);
           lineSelector++;
           break;
        }
      case 9:{
            QString qString = QString::fromStdString(resLine);
            ui->LDD->setPlainText(qString);
            lineSelector++;
            break;
        }
        default:
            lineSelector++;
        }
    }
    USERFile.close();

}

void showDonationRequstes::acceptDonationRequest(string id){

    string resLine ;
    fstream USERFile;
    ofstream temp2;
    char* fileName;
    fileName = &id[0];

    USERFile.open(id );
   temp2.open("temp");
    while (getline(USERFile,resLine))
    {
       temp2 << resLine << endl;
    }
    temp2 << "your donation request has been accepted";
    temp2.close();
    USERFile.close();
    remove(fileName);
    rename("temp", fileName);

}

void showDonationRequstes::rejectDonationRequest(string id){
    string resLine ;
    fstream USERFile;
    ofstream temp2;
    char* fileName;
    fileName = &id[0];

    USERFile.open(id );
   temp2.open("temp");
    while (getline(USERFile,resLine))
    {
       temp2 << resLine << endl;
    }
    temp2 << "your donation request has been rejected";
    temp2.close();
    USERFile.close();
    remove(fileName);
    rename("temp", fileName);
}

showDonationRequstes::~showDonationRequstes()
{
    delete ui;
}

void showDonationRequstes::on_SHOW_clicked()
{
    string resLine ;
    fstream USERFile;


    USERFile.open("donationRequests");
    while (getline(USERFile,resLine)) {
        donorQueue.enQueue(resLine);
    }
    USERFile.close();
    if(donorQueue.peek() == "Queue is empty"){
        QMessageBox::information(nullptr/*or parent*/, "Important",
          QString("No Donation request left"));

    }else{
     getDonorInfo(donorQueue.peek());
    }
   donorQueue.display();
   ui->SHOW->setEnabled(false);
}


void showDonationRequstes::on_ACCEPT_clicked()
{
    string s1 = ui->ID->toPlainText().toStdString();
    acceptDonationRequest(s1);
    if(donorQueue.peek() == "Queue is empty"){
        QMessageBox::information(nullptr/*or parent*/, "Important",
          QString("No Donation request left"));

    }else{
     donorQueue.deQueue();
     getDonorInfo(donorQueue.peek());
    }

    cout<<donorQueue.size()<<endl;
}


void showDonationRequstes::on_save_clicked()
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "DONOTONREQUESTS",tr("All the data will be saved\n"),
                                                               QMessageBox::Cancel | QMessageBox::No|QMessageBox::Yes) ;
    if(resBtn!= QMessageBox::Yes){

    }else {
        string resLine ;
        ofstream USERFile;
        USERFile.open("donationRequests");

        if(donorQueue.size()==0){
            USERFile<<"";
            USERFile.close();
            hide();
        }else{

        while(donorQueue.size()>0){
            USERFile<<donorQueue.peek()<<endl;
            donorQueue.deQueue();
        }

        USERFile.close();
        hide();
    }
}
}


void showDonationRequstes::on_REJECT_clicked()
{
    string s1 = ui->ID->toPlainText().toStdString();
    rejectDonationRequest(s1);
    if(donorQueue.peek() == "Queue is empty"){
        QMessageBox::information(nullptr/*or parent*/, "Important",
          QString("No Donation request left"));

    }else{
     donorQueue.deQueue();
     getDonorInfo(donorQueue.peek());
    }
}



void showDonationRequstes::on_Cancel_clicked()
{
    hide();
}

