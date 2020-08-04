#pragma once
#include "Admin.h"
class Notif
{
private:
	int notifType;
protected:
	string senderID;
	string takerID;
public:
	string getSenderID() { return senderID; }
	string getTakerID() { return takerID; }
};
class AdminNotif : public Notif, public Admin, public AccountInfo
{
private: 
	int issueType;
	string Problem;

protected:
	vector<AdminNotif> adnv;
public:
	string getProblem() { return Problem; }
	void loadListNotif();
	AdminNotif loadAnNotif(ifstream& fin);
	void checkNotif(string adminID, string userID);
	void displayNotif();
	void displayListNotif();
};