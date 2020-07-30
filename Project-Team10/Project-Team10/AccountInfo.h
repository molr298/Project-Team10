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
	int phoneNumber;
	int gender;
	int status;
protected:
	//
public:
	void loadAnAccountInfo(ifstream&);
	void inputAccount();
	void saveAnAccountInfor(ofstream&);
	void displayAccountInfo();
	int getID() { return ID; }
	string getUsername() { return username; }
	string getFullname() { return fullname; }
	string getDoB() { return DoB; }
	int getPhoneNumber() { return phoneNumber; }
	int getGender() { return gender; }

};

#endif // !_ACCOUNTINFO_H


