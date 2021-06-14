#pragma once
#include <string>
#include <fstream>
#include "Blood.h"
using namespace std;
class Admin
{
private:
	fstream savedFile;
	ofstream temp;
	string adminID;
	string resultLine;
	string adminPassword;
	Blood bloodObj;
	void getDonorInfo(string);
	void bloodManagingMenu();
	string selectBloodType();

public:
	Admin();
	void adminMenu();
	void showDonationRequests();
	void showRecipiantRequests();

};

