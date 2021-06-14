#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include "bloodBagsQueue.h"
using namespace std;
class Blood
{

private:
    fstream savedFile;
	ofstream temp;
	string resultLine;
	bloodBagsQueue bagsQueue;
	void saveChange(string);
	string getProductionDate();
	string getExpiryDate();
	int convertToInteger(string);
	int calculateDifference(int, int);

public:
	void insertBloodBag(string  , string );
	void bagsWithdraw(string , string);
	void displayAllBloodBags(string );

};

