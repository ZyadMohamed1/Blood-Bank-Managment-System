#include "adminwithdraw.h"
#include "ui_adminwithdraw.h"
#include "Blood.h"
#include "QMessageBox"

AdminWithdraw::AdminWithdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWithdraw)
{
    ui->setupUi(this);
}

AdminWithdraw::~AdminWithdraw()
{
    delete ui;
}

bool AdminWithdraw::CheckRequest(string b, string q){
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

void AdminWithdraw::on_WITHDRAW_clicked()
{
    Blood bloodAdd;
    string blood = ui->BLOODTYPE->currentText().toStdString();
    string quantity = ui->quantity->currentText().toStdString();
    QString q = ui->quantity->currentText();
    bool flag = CheckRequest(blood, quantity);


    if(flag == false){
        QMessageBox::information(nullptr/*or parent*/, "Done",
        QString("This number of bags not available right now!"));
    }
    else if(flag == true){
    //cout<<bloodtype<<" "<<quantity<<endl;

    bloodAdd.bagsWithdraw(blood, quantity);
    QMessageBox::information(nullptr/*or parent*/, "Done",
    QString(" You Withdraw " +q+" of bags"));
    }

}


void AdminWithdraw::on_cancel_clicked()
{
    hide();
}

