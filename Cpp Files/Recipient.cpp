#include "Recipient.h"
#include "Blood.h"
#include <fstream>
#include <iterator>
#include <map>
#include <vector>
#include <string>

Recipient::Recipient() 
{

}

Recipient::Recipient(string id, string name, string mail, string password, string age, string gender, string blood_type, string Hospital, string doctorName) : User(id, name, mail, password, age, gender, blood_type)
{

	this->Hospital = Hospital;
	this->doctorName = doctorName;
	f.add_recipient_data(id, name, mail, password, age, gender, blood_type, Hospital, doctorName);
    f.add_to_Dindex_file(id, password);

}


void Recipient::recipientRequest(string blood, string quantity)
{
	Blood bloodRequest;
    bloodRequest.bagsWithdraw(blood, quantity);
}






