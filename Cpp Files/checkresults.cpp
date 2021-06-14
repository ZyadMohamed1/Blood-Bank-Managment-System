#include "checkresults.h"
#include "ui_checkresults.h"
#include "Donor.h"
#include "QMessageBox"
#include "QFile"
#include <fstream>
CheckResults::CheckResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckResults)
{
    ui->setupUi(this);
}

CheckResults::~CheckResults()
{
    delete ui;
}

void CheckResults::on_checkButton_clicked()
{


    QString id = ui->id->text();
    QString line;
    QFile file("C://Users//Zyad//Documents//build-Blood-Desktop_Qt_6_1_0_MinGW_64_bit-Debug//"+id);
    file.open(QIODevice::ReadOnly);
    while(!file.atEnd()){
        line = file.readLine();
    }

    if(line == "your donation request has been accepted"){
        QMessageBox::information(nullptr/*or parent*/, "Important",
          QString(line));
    }
    else if(line == "your donation request has been rejected"){
        QMessageBox::information(nullptr/*or parent*/, "Important",
          QString(line));
    }
    else if(line == "your request has been accepted"){
        int lineSelector = 0;
        string resLine ;
        fstream USERFile;
        USERFile.open(id.toStdString());
        while (getline(USERFile,resLine))
            {
                switch(lineSelector){
                case 8:{
                QString qString = QString::fromStdString(resLine);
                QMessageBox::information(nullptr/*or parent*/, "Important",
                  QString(line+", Go to "+qString+" to recive your bags"));
                lineSelector++;
                break;
                }
                default:
                  lineSelector++;
                                    }
            }
                 USERFile.close();

    }
    else if(line == "your request has been rejected"){
        QMessageBox::information(nullptr/*or parent*/, "Important",
          QString(line));
    }
    else{
        QMessageBox::information(nullptr/*or parent*/, "Important",
          QString("The Donation Request is still under progress"));
    }

}

