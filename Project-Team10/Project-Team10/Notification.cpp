#include "Notification.h"
int countLines(ifstream& filein)
{
	string line;
	int n = 0;
	while (filein.good())
	{
		getline(filein, line);
		n++;
	}
	return n - 1;
}
void AdminNotif::loadListNotif()
{
	ifstream fin;
	fin.open("C:/Users/MyPC/source/repos/Project-Team10/Project-Team10/Notification/Notif_Admin.csv");
	if (!fin.is_open()) {
		cout << "Can't open Notif_Admin!!" << endl;
		return;
	}
	string line;
	getline(fin, line);
	for (int i = 0; i < 4; i++)
	{
		adnv.push_back(AdminNotif::loadAnNotif(fin));
	}
	fin.close();
}
AdminNotif AdminNotif::loadAnNotif(ifstream& fin)
{

	getline(fin, senderID,';');
	getline(fin, takerID, ';');
	getline(fin, Problem);
	return *this;
}
void AdminNotif::checkNotif(string adminID, string userID)
{
	int flag = 0;
	for (int i = 0; i < adnv.size(); i++)
	{
		if (adminID == adnv[i].getTakerID())
		{
			cout << "User " << adnv[i].getSenderID() << " sent this message to you: " << adnv[i].getProblem() << endl;
			flag = 1;
		}
		if (userID == adnv[i].getTakerID())
		{
			cout << "You have a notification from Admin\n" << adnv[i].getProblem() << endl;
			flag = 1;
		}
	}
	if(flag==0)
		cout << "No notification available" << endl;
}
void AdminNotif::displayNotif()
{
	cout << "Sender ID: " << senderID << endl;
	cout << "Sender ID: " << takerID << endl;
	cout << "Sender ID: " << Problem << endl;
}
void AdminNotif::displayListNotif()
{
	for (int i = 0; i < adnv.size(); i++)
	{
		adnv[i].displayNotif();
	}
	cout << "________________________________" << endl;
}