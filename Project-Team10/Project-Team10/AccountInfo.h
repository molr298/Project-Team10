#ifndef _ACCOUNTINFO_H
#define _ACCOUNTINFO_H

#include "Lib.h"
using namespace std;
class AccountInfo
{
private:
	string ID;
	string username;
	string fullname;
	string DoB;
	int phoneNumber;
	int gender;
	int status;	//0-customer	1-seller
	//vector<AccountInfo> listUser;
	vector<AccountInfo> listAdmin;
protected:
	vector<AccountInfo> listUser;
public:
	AccountInfo loadAnAccountInfo(ifstream&);
	void inputAccount();
	void saveAnAccountInfor(ofstream&);
	void displayAccountInfo();
	string getID() { return ID; }
	string getUsername() { return username; }
	string getFullname() { return fullname; }
	string getDoB() { return DoB; }
	int getPhoneNumber() { return phoneNumber; }
	int getGender() { return gender; }
	int getStatus() { return status; }
	void setStatus(int s) { status = s; }
	void loadListUser();
	void saveListUser();
	void registerAccount();
	/*AccountInfo findUser(const int&);*/		//find another user by ID
	AccountInfo* findUser(const string&);	//find another user by user name
	void displayListUser();
	void editInfo();
	void operator=(const AccountInfo& aci)
	{
		ID = aci.ID;
		username = aci.username;
		fullname = aci.fullname;
		DoB = aci.DoB;
		phoneNumber = aci.phoneNumber;
		gender = aci.gender;
	}
	vector <AccountInfo> getVecctor()
	{
		return listUser;
	}

	void removeAccountInfo(const string&);
};

#endif // !_ACCOUNTINFO_


