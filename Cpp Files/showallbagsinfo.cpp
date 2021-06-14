#include "showallbagsinfo.h"
#include "ui_showallbagsinfo.h"
#include <QFile>
#include <QMessageBox>
showAllBagsInfo::showAllBagsInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showAllBagsInfo)
{
    ui->setupUi(this);


}

showAllBagsInfo::~showAllBagsInfo()
{
    delete ui;
}

void showAllBagsInfo::on_pushButton_clicked()
{
    QVector<QString> bloodTypes;
        bloodTypes.push_back("A+");
        bloodTypes.push_back("A-");
        bloodTypes.push_back("B+");
        bloodTypes.push_back("B-");
        bloodTypes.push_back("O+");
        bloodTypes.push_back("O-");
        bloodTypes.push_back("AB+");
        bloodTypes.push_back("AB-");

        for(int i=0;i<8;i++){
        QFile file("C://Users//Zyad//Documents//build-Blood-Desktop_Qt_6_1_0_MinGW_64_bit-Debug//"+bloodTypes[i]);
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"info", file.errorString());
        QTextStream in(&file);
        if(i==0)
            ui->Aplus->setPlainText(in.readAll());
        else if(i==1)
            ui->Aminus->setPlainText(in.readAll());
        else if(i==2)
            ui->Bplus->setPlainText(in.readAll());
        else if(i==3)
            ui->Bminus->setPlainText(in.readAll());
        else if(i==4)
            ui->Oplus->setPlainText(in.readAll());
        else if(i==5)
            ui->Ominus->setPlainText(in.readAll());
        else if(i==6)
            ui->ABplus->setPlainText(in.readAll());
        else if(i==7)
            ui->ABminus->setPlainText(in.readAll());
        }
}


void showAllBagsInfo::on_pushButton_2_clicked()
{
    hide();
}

