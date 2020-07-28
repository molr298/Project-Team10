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
	bool gender;
protected:
	//
public:
	AccountInfo loadAnAccountInfo(ifstream&);
	void saveAnAccountInfor(ofstream&);
	void displayAccountInfo();
};

#endif // !_ACCOUNTINFO_H


