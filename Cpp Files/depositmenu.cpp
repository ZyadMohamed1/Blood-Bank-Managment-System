#include "depositmenu.h"
#include "ui_depositmenu.h"
#include "mainwindow.h"
#include <QMessageBox>

depositMenu::depositMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depositMenu)
{
    ui->setupUi(this);
    ui->BLOODTYPE->addItem("A+");
    ui->BLOODTYPE->addItem("A-");
    ui->BLOODTYPE->addItem("B+");
    ui->BLOODTYPE->addItem("B-");
    ui->BLOODTYPE->addItem("O+");
    ui->BLOODTYPE->addItem("O-");
    ui->BLOODTYPE->addItem("AB+");
    ui->BLOODTYPE->addItem("AB-");

        ui->quantity->addItem("1");
         ui->quantity->addItem("2");
         ui->quantity->addItem("3");
          ui->quantity->addItem("4");
          ui->quantity->addItem("5");
}

string depositMenu::getProductionDate()
{
    const int MAXLEN = 80;
    char productionDate[MAXLEN];
    time_t t = time(0);
    strftime(productionDate, MAXLEN, "%d/%m/%Y", localtime(&t));
    return productionDate;
}

string depositMenu::getExpiryDate()
{
    const int MAXLEN = 80;
    char expiryDate[MAXLEN];
    time_t t = time(0) + 86400 * 42;
    strftime(expiryDate, MAXLEN, "%d/%m/%Y", localtime(&t));
    return expiryDate;
}

int depositMenu::convertToInteger(string numOfbags)
{
    int numOfbags1 = 0;
    stringstream stringNumber(numOfbags);
    stringNumber >> numOfbags1;
    return numOfbags1;
}

int depositMenu::calculateDifference(int savedBags, int neededBags)
{
    if (savedBags > neededBags) {
        return 1;
    }
    else if (savedBags == neededBags) {
        return 0;
    }
    else {
        return -1;
    }
}

void depositMenu::depositBloodBag(string type, string numOfbags)
{

    int lineSelector = -1;
    char* fileName;
    fileName = &type[0];

    savedFile.open(type);
    temp.open("temp");

    while (getline(savedFile, resultLine))
    {
        if (resultLine == getProductionDate()) {
            lineSelector = 1;
            temp << resultLine << endl;
        }
        else if (lineSelector == 1) {
            lineSelector = 2;
            temp << resultLine << endl;
        }
        else if(lineSelector == 2){
            lineSelector = 0;
            int savedBag = convertToInteger(resultLine);
            int newBags = convertToInteger(numOfbags);
            int sum = savedBag + newBags;
            temp << sum << endl;
        }
        else {
            temp << resultLine << endl;
        }
    }
    if (lineSelector == -1) {
        temp
            << getProductionDate() << endl
            << getExpiryDate() << endl
            << numOfbags << endl;

        savedFile.close();
        temp.close();
        remove(fileName);
        rename("temp", fileName);
    }
    else {
        savedFile.close();
        temp.close();
        remove(fileName);
        rename("temp", fileName);
    }

}

depositMenu::~depositMenu()
{
    delete ui;
}

void depositMenu::on_DEPOSIT_clicked()
{
    string numOfbloodBags;
    numOfbloodBags = ui->quantity->currentText().toStdString();
    if( numOfbloodBags.empty()){
            QMessageBox::information(this,"DEPOSIT","please enter number of blood bags");
    }else{
    depositBloodBag( ui->BLOODTYPE->currentText().toStdString(),
                     ui->quantity->currentText().toStdString());
    QMessageBox::information(this,"DEPOSIT",ui->quantity->currentText() +" Blood bags have been added to "+ui->BLOODTYPE->currentText()+"BLOOD TYPE");

    }
}

void depositMenu::on_cancel_clicked()
{
    hide();
}

