#ifndef _ACCOUNTINFO_H
#define _ACCOUNTINFO_H

#include "Lib.h"

class AccountInfo
{
private:
	int ID;
	string username;
	string fullname;
	string DoB;
	string address;
	int phoneNumber;
	int gender;
protected:
	//
public:
	AccountInfo loadAnAccountInfo(ifstream&);
	void saveAnAccountInfor(ofstream&);
	void displayAccountInfo();
	int getID() { return ID; }
	string getUsername() { return username; }
	string getFullname() { return fullname; }
	string getDoB() { return DoB; }
	string getAddress() { return address; }
	int getPhoneNumber() { return phoneNumber; }
	int getGender() { return gender; }
};

#endif // !_ACCOUNTINFO_H


