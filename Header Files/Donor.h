#pragma once
#include <string>
#include <iostream>
#include "User.h"
#include "Filestream.h"
class Donor :public User
{
    string sick;
    string medicin;
	string last_donation_date;
	Filestream f;
public:
	Donor();
	void Register();
    Donor(string id, string name, string mail, string password, string age, string gender, string blood_type,string sick,string medicin, string last_donation_date);
	void donation_request(string id);

};
