#include "Lib.h"
#include "AccountInfo.h"
#include "Admin.h"
#include"Customer.h"
#include "sha256.h"
//class ListAccount
//{
//private:
//	int adminNum;
//	int userNum;
//	vector<AccountInfo> listAccountAdmin;
//	vector<AccountInfo> listAccountUser;
//
//public:
//	void loadListUserAccount();
//	void loadListAdminAccount();
//	void registerUserAccount();
//};

class Account {
private:
	string username;
	string passHash;
	string ID;
public:
	Account loadAnAccount(ifstream&);
	string inputPassword();
	/*string HashPassword(string passWord);*/
	string getPassHass() { return passHash; }
	string getUsername() { return username; }
	void saveAccount(ofstream&);
};

class ListAccount: public Account {
private:
	vector<Account> listAccount;
public:
	void loadListAccount(string);
	int login(string, string);
	void saveListAccount(const int&	, string);
};