#include "searchbloodtype.h"
#include "ui_searchbloodtype.h"
#include "recipientmainwindow.h"
#include "QFile"
#include "QMessageBox"
searchBloodType::searchBloodType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchBloodType)
{
    ui->setupUi(this);
}

searchBloodType::~searchBloodType()
{
    delete ui;
}





void searchBloodType::on_searchButton_clicked()
{
    QString type = ui->comboBox->currentText();
    QFile file("C://Users//Zyad//Documents//build-Blood-Desktop_Qt_6_1_0_MinGW_64_bit-Debug//"+type);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info", file.errorString());
    QTextStream in(&file);
     ui->plainTextEdit->setPlainText(in.readAll());
}

