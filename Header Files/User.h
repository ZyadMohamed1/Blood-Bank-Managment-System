#pragma once
#include <string>
#include <iostream>

using namespace std;
class User
{
	string id;
    string name;
	string mail;
	string passsword;
	string age;
	string gender;
	string blood_type;

public:
	User();
    User(string id, string name, string mail, string password, string age, string gender, string blood_type);
    bool login(string idLogin, string passLogin);
	~User();
};

