#pragma once
#include <string>
#include <fstream>

using namespace std;
class Filestream
{
public:
	Filestream();
    void add_donor_data(string id, string name, string mail, string password, string age, string gender, string blood_type,string sick, string medicin, string last_donation_date);
	void add_recipient_data(string id, string name, string mail, string password, string age, string gender, string blood_type, string Hospital, string doctorName);
    void add_to_Dindex_file(string id, string password);
    void add_to_Rindex_file(string id, string password);
	//void read_user_data(string id);
    void blood_donation(string id);
    void blood_request(string id);
	void donation_accept_refuse(string id,string decision);
	~Filestream();
};

