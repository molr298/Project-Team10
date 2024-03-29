#ifndef _ACCOUNT_H
#define _ACCOUNT_H


#include "Lib.h"
#include "AccountInfo.h"
#include "sha256.h"

using namespace std;

class Account {
private:
	string username;
	string passHash;
	string ID;
	vector<string>listID;
public:
	Account loadAnAccount(ifstream&);
	string inputPassword();
	string HashPassword(string passWord);
	string getUsername() { return username; }
	string getID() { return ID; }

	bool checkUsername(const string& username);
	bool checkPassHash(const string& passHash);
	bool checkID(const string& ID);
	bool checkAccount(const Account& accountCheck, int mark);

	void saveAccount(ofstream&);
	void loadListIDOfUser();
	string createNewID();
	void saveListIDOfUSer();
	Account createNewAccount(string, string);
	void changePassword();
	void changeUsername(string);
	void deleteIDOfUser(string IDUser);
};

class ListAccount: public Account{
private:
	vector<Account> listAccount;
public:
	void loadListAccount(string);
	int login(string, string);
	void saveListAccount(string);
	void SignUp(Account&);
	void removeAccount(string);
	Account findAccount(string);

	void replaceAccount(Account&);
};

#endif // !_ACCOUNT_H