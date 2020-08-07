#include "Lib.h"
#include "AccountInfo.h"
#include "Admin.h"
#include"Customer.h"
#include "sha256.h"

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
	string getPassHass() { return passHash; }
	string getUsername() { return username; }
	string getID() { return ID; }
	void saveAccount(ofstream&);
	void loadListIDOfUser();
	string createNewID();
	void saveListIDOfUSer();
	Account createNewAccount();
};

class ListAccount: public Account {
private:
	vector<Account> listAccount;
public:
	void loadListAccount(string);
	int login(string, string);
	void saveListAccount(const int&	, string);
	void SignUp();
	virtual void removeAccount() final;
};