#include "blood_bags_managing.h"
#include "ui_blood_bags_managing.h"
#include "mainwindow.h"


BLOOD_BAGS_MANAGING::BLOOD_BAGS_MANAGING(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BLOOD_BAGS_MANAGING)
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
}
string BLOOD_BAGS_MANAGING::getProductionDate()
{
    const int MAXLEN = 80;
    char productionDate[MAXLEN];
    time_t t = time(0);
    strftime(productionDate, MAXLEN, "%d/%m/%Y", localtime(&t));
    return productionDate;
}

string BLOOD_BAGS_MANAGING::getExpiryDate()
{
    const int MAXLEN = 80;
    char expiryDate[MAXLEN];
    time_t t = time(0) + 86400 * 42;
    strftime(expiryDate, MAXLEN, "%d/%m/%Y", localtime(&t));
    return expiryDate;
}

int BLOOD_BAGS_MANAGING::convertToInteger(string numOfbags)
{
    int numOfbags1 = 0;
    stringstream stringNumber(numOfbags);
    stringNumber >> numOfbags1;
    return numOfbags1;
}

int BLOOD_BAGS_MANAGING::calculateDifference(int savedBags, int neededBags)
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

void BLOOD_BAGS_MANAGING::insertBloodBag(string type, string numOfbags)
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


BLOOD_BAGS_MANAGING::~BLOOD_BAGS_MANAGING()
{
    delete ui;
}

void BLOOD_BAGS_MANAGING::on_cancel_clicked()
{

}


void BLOOD_BAGS_MANAGING::on_DEPOSIT_clicked()
{

}

