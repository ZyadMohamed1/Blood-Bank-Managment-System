#pragma once
#include "User.h"
#include "Filestream.h"
#include <string>

class Recipient : public User
{
private:

	string Hospital;
	string doctorName;
	Filestream f;

public:

	Recipient();
	void Register();
	Recipient(string id, string name, string mail, string password, string age, string gender, string blood_type, string Hospital, string doctorName);
	void searchForBlood();
	void displayBlood();
    void recipientRequest(string type, string quantity);

};


