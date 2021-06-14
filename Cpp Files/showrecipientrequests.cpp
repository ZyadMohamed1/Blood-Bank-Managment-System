#include "showrecipientrequests.h"
#include "ui_showrecipientrequests.h"
#include "qonationrequestqueue.h"
#include <fstream>
#include "QMessageBox"
#include "Recipient.h"


showrecipientrequests::showrecipientrequests(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showrecipientrequests)
{
    ui->setupUi(this);

}
qonationRequestQueue recipientQueue;
void showrecipientrequests::getRecipientInfo(string id)
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
            case 4:{
             QString qString = QString::fromStdString(resLine);
             ui->BloodType->setPlainText(qString);
             lineSelector ++ ;
                break;
                }
            case 5:{
            QString qString = QString::fromStdString(resLine);
              ui->AGE->setPlainText(qString);
            lineSelector++;
            break;
                }
            case 8:{
             QString qString = QString::fromStdString(resLine);
             ui->HospitalName->setPlainText(qString);
             lineSelector++;
             break;
                }
            default:
              lineSelector++;
                }
                }
USERFile.close();

}

void showrecipientrequests::acceptRecipientRequest(string id){

//show accept in file
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
temp2 << "your request has been accepted";
temp2.close();
USERFile.close();
remove(fileName);
rename("temp", fileName);

}

void showrecipientrequests::rejectRecipientRequest(string id){
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
temp2 << "your request has been rejected";
temp2.close();
USERFile.close();
remove(fileName);
rename("temp", fileName);
}


showrecipientrequests::~showrecipientrequests()
{
    delete ui;
}

void showrecipientrequests::on_ACCEPT_clicked()
{
    string s1 = ui->ID->toPlainText().toStdString();
    acceptRecipientRequest(s1);
    if(recipientQueue.peek() == "Queue is empty"){
        QMessageBox::information(nullptr/*or parent*/, "Important",
          QString("No Recipient request left"));

    }else{
     recipientQueue.deQueue();
     getRecipientInfo(recipientQueue.peek());
    }

    cout<<recipientQueue.size()<<endl;

}


void showrecipientrequests::on_REJECT_clicked()
{
    string s1 = ui->ID->toPlainText().toStdString();
    rejectRecipientRequest(s1);
    if(recipientQueue.peek() == "Queue is empty"){
        QMessageBox::information(nullptr/*or parent*/, "Important",
          QString("No Recicpient request left"));

    }else{
     recipientQueue.deQueue();
     getRecipientInfo(recipientQueue.peek());
    }
}


void showrecipientrequests::on_SHOW_clicked()
{
    string resLine ;
    fstream USERFile;


    USERFile.open("RecipientRequests");
    while (getline(USERFile,resLine)) {
        recipientQueue.enQueue(resLine);
    }
    USERFile.close();
    if(recipientQueue.peek() == "Queue is empty"){
        QMessageBox::information(nullptr/*or parent*/, "Important",
          QString("No Recipient request left"));

    }else{
     getRecipientInfo(recipientQueue.peek());
    }
   recipientQueue.display();
   ui->SHOW->setEnabled(false);
}


void showrecipientrequests::on_save_clicked()
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "DONOTONREQUESTS",tr("All the data will be saved\n"),
                                                               QMessageBox::Cancel | QMessageBox::No|QMessageBox::Yes) ;
    if(resBtn!= QMessageBox::Yes){

    }else {
        string resLine ;
        ofstream USERFile;
        USERFile.open("RecipientRequests");

        if(recipientQueue.size()==0){
            USERFile<<"";
            USERFile.close();
            hide();
        }else{

        while(recipientQueue.size()>0){
            USERFile<<recipientQueue.peek()<<endl;
            recipientQueue.deQueue();
        }

        USERFile.close();
        hide();
    }
}
}

