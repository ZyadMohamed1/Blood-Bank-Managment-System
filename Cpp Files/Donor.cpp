#include "Donor.h"


using namespace std;
Donor::Donor()
{

}
Donor::Donor(string id, string name, string mail, string password, string age, string gender, string blood_type,string sick,string medicin, string last_donation_date) : User(id, name, mail, password, age, gender, blood_type)
{
    this->sick=sick;
    this->medicin=medicin;
	this->last_donation_date = last_donation_date;
    f.add_donor_data(id, name, mail, password, age, gender, blood_type,sick,medicin, last_donation_date);
    f.add_to_Dindex_file(id, password);

}




