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
	bool gender;
	int status;
protected:
	//
public:
	AccountInfo loadAnAccountInfo(ifstream&);
	void saveAnAccountInfor(ofstream&);
	void displayAccountInfo();
	int getID();
	string getUserName();
};

#endif // !_ACCOUNTINFO_H


