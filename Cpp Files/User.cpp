#include "User.h"
#include "fstream"
#include <map>
User::User()
{
}

User::User(string id, string name, string mail, string password, string age, string gender, string blood_type)
{
	this->id = id;
	this->name = name;
	this->mail = mail;
	this->passsword = password;
	this->age = age;
	this->gender = gender;
	this->blood_type = blood_type;

}

bool User::login(string idLogin, string passLogin)
{

        string Fid, Fpass;
        bool log = false;
        ifstream file;
        file.open("C:\\Users\\Zyad\\Documents\\build-Blood-Desktop_Qt_6_1_0_MinGW_64_bit-Debug\\Dindex");
        map<string, string> myMap;
        myMap.insert({ idLogin, passLogin });
        while (file >> Fid >> Fpass)
        {
            for (auto itr = myMap.begin(); itr != myMap.end(); ++itr) {
                if (itr->first == Fid && itr->second == Fpass) {
                    return true;
                }
            }

        }
        return false;

}


User::~User()
{
}
