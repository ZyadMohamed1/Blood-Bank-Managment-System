#include "updateform.h"
#include "ui_updateform.h"
#include "QFile"
#include "QRegularExpression"
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QTextStream>
#include "QMessageBox"

UpdateForm::UpdateForm(QString userID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateForm)
{
    ui->setupUi(this);

    this->userID=userID;
}

UpdateForm::~UpdateForm()
{
    delete ui;
}

void UpdateForm::getID(QString id){
    this->id = id ;
}

void UpdateForm::rename(QFile *file, QString newid){

    file->rename(newid);
}

void UpdateForm::on_update_clicked()
{

        //QString idnew = ui->idEdit->text();
        QString oldData = ui->oldData->text();
        QString newD = ui->newData->text();

       QFile data("C:/Users/Zyad/Documents/build-Blood-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/"+userID);
       data.open(QIODevice::Text | QIODevice::ReadOnly);
       QString dataText = data.readAll();

       QRegularExpression text(oldData);
       QString replacementText(newD);

       dataText.replace(text, replacementText);

       QFile newData("C:/Users/Zyad/Documents/build-Blood-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/temp");
       if(newData.open(QFile::WriteOnly | QFile::Truncate)) {
          QTextStream out(&newData);
          out << dataText;
       }
       newData.close();
       data.close();
        data.remove();
        rename(&newData, userID);
        hide();



}
