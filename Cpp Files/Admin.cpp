#include "Admin.h"

void Admin::getDonorInfo(string id)
{
	int selection ;
	string resLine;
	fstream USERFile;
	ofstream temp2;
	char* fileName;
	fileName = &id[0];

	USERFile.open(id);
	temp2.open("temp");
	while (getline(USERFile,resLine))
	{
		temp2 << resLine << endl;
		cout << resLine << endl;
	}
	cout << "1 >> ACCEPT \n2 >>REJECT\n->";
	cin >> selection;
	if (selection == 1) {
		temp2 << "your donation request has been accepted" << endl;
	}
	else {
		temp2 << "your donation request has been rejected" << endl;
	}
	temp2.close();
	USERFile.close();
	remove(fileName);
	rename("temp", fileName);

}

void Admin::bloodManagingMenu()
{

}

string Admin::selectBloodType()
{

}

Admin::Admin()
{
	adminID = "admin";
	adminPassword = "admin";
}

void Admin::adminMenu()
{

}

void Admin::showDonationRequests()
{

}

