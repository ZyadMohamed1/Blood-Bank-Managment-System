#include "Blood.h"

void Blood::saveChange(string type)
{
    char* fileName = &type[0];
    int lineSelector = 1;
    savedFile.open(type);
    temp.open("temp");
    while (getline(savedFile, resultLine))
    {
        switch (lineSelector) {
        case 1: {
            //production date
            lineSelector++;
            if (bagsQueue.peek() != 0) {
                temp << resultLine << endl;
            }
            break;
        }case 2: {
            //epiry date
            lineSelector++;
            if (bagsQueue.peek() != 0) {
                temp << resultLine << endl;
            }          
            break;
        }
        case 3: {
            //blood bags
            lineSelector = 1;
            if (bagsQueue.peek() != 0) {
                temp << bagsQueue.peek() << endl;
                bagsQueue.deQueue();
            }
            else {
                bagsQueue.deQueue();
            }
            break;
        }
        }
    }
        savedFile.close();
        temp.close();
        remove(fileName);
        rename("temp", fileName);
}

string Blood::getProductionDate()
{
    const int MAXLEN = 80;
    char productionDate[MAXLEN];
    time_t t = time(0);
    strftime(productionDate, MAXLEN, "%d/%m/%Y", localtime(&t));
    return productionDate;
}

string Blood::getExpiryDate()
{
    const int MAXLEN = 80;
    char expiryDate[MAXLEN];
    time_t t = time(0) + 86400 * 42;
    strftime(expiryDate, MAXLEN, "%d/%m/%Y", localtime(&t));
    return expiryDate;
}

int Blood::convertToInteger(string numOfbags)
{
    int numOfbags1 = 0;
    stringstream stringNumber(numOfbags);
    stringNumber >> numOfbags1;
    return numOfbags1;
}

int Blood::calculateDifference(int savedBags, int neededBags)
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

void Blood::insertBloodBag(string type, string numOfbags)
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

void Blood::bagsWithdraw(string type, string numOfbags)
{
    int lineSelector =  1;
    char* fileName = &type[0];

    savedFile.open(type);
    temp.open("temp");
    while (getline(savedFile, resultLine))
    {
        if (lineSelector == 1) {
            lineSelector++;
            temp << resultLine << endl;
        }
        else if (lineSelector == 2) {
            lineSelector++;
            temp << resultLine << endl;
        }
        else if (lineSelector == 3) {         
            lineSelector = 1;
            bagsQueue.enQueue(convertToInteger(resultLine));
            temp << resultLine << endl;
            
        }
    }
    savedFile.close();
    temp.close();
    remove(fileName);
    rename("temp", fileName);
    bagsQueue.Withdraw(convertToInteger(numOfbags));     
    saveChange(type);

}

void Blood::displayAllBloodBags(string type)
{
    int lineSelector = 1;
    savedFile.open(type);
    cout << "\n\t***********\n";
    cout << "\t   "<<type<<"    *\n";
    cout << "\t*         *\n";
    cout << "\t***********\n\n";

    while (getline(savedFile, resultLine)) {
        if (lineSelector == 1) {
            cout << "Production Date : "<<resultLine << "\t\t";
            lineSelector++;
        }
        else if (lineSelector == 2) {
            cout <<"Expiry Date : "<< resultLine << "\t\t";
            lineSelector++;
        }
        else if (lineSelector == 3){
            cout << "Number of Blood bags : " << resultLine << "\n";
            cout << "____________________________________________________________________________________________________________\n\n";
            lineSelector = 1;
        }
    }
    savedFile.close();
}
