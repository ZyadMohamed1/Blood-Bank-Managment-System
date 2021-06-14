#include "Filestream.h"

Filestream::Filestream()
{
}

void Filestream::add_to_Dindex_file(string id,string password)
{
	ofstream index;
    index.open("Dindex", ios::app);
    index << id <<" "<<password <<endl;
}

void Filestream::add_donor_data(string id, string name, string mail, string password, string age, string gender, string blood_type,string sick,string medicin, string last_donation_date)
{
    string type = "Donor";

	ofstream Ufile;
    Ufile.open(id);
    Ufile<<type<<endl
        << id <<endl
        << name << endl
        << sick<<"-"<<
         medicin<<endl
        << blood_type << endl
        << password << endl
        << age << endl
        << gender << endl
        << mail << endl
        << last_donation_date<<endl;
    Ufile.close();
}

void Filestream::add_recipient_data(string id, string name, string mail, string password, string age, string gender, string blood_type, string Hospital, string doctorName)
{
    string type = "Recipient";

	ofstream Ufile;
    Ufile.open(id);
    Ufile<<type<<endl
          <<id<<endl
         << name << endl
         << password << endl
        << blood_type << endl
        << age << endl
        << gender << endl
        << mail << endl
        <<Hospital<<endl
       <<doctorName<<endl;
	Ufile.close();
}


void Filestream::blood_donation(string id)
{
    ofstream donation;
    donation.open("donationRequests", ios::app);
    donation << id << endl;

}

void Filestream::blood_request(string id){
    ofstream request;
    request.open("RecipientRequests", ios::app);
    request << id << endl;
}

void Filestream::donation_accept_refuse(string id,string decision)
{
    ofstream UserFile;
    UserFile.open(id);
    UserFile << decision << endl;
}

Filestream::~Filestream()
{
}
