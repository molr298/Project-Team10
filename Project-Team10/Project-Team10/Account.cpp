#include "Account.h"
void ListAccount::loadListAdminAccount()
{
	AccountInfo* aci;
	aci = new Admin;
	ifstream fin("Data/Admin.txt");
	if (!fin.is_open()) {
		cout << "Can't open Admin.txt!!" << endl;
		return;
	}
	int adminNum;
	fin >> adminNum;
	for (int i = 0; i < adminNum; i++)
	{
		aci->loadAnAccountInfo(fin);
		listAccountAdmin.push_back(aci);
	}
	fin.close();
}
void ListAccount::loadListUserAccount()
{
	AccountInfo* aci;
	ifstream fin("Data/User.txt");
	if (!fin.is_open()) {
		cout << "Can't open User.txt!!" << endl;
		return;
	}
	fin >> userNum;
	fin.close();
	aci = new Customer;
	for (int i = 0; i < userNum; i++)
	{
		
		aci->loadAnAccountInfo(fin);
		listAccountUser.push_back(aci);
		
	}
	fin.close();
	for (int i = 0; i < userNum; i++)
	{
		listAccountUser[i]->displayAccountInfo();

	}
	delete aci;
}
void ListAccount::registerUserAccount()
{
	cout << "Welcome to user area, enter your personal information to get started !" << endl;
	AccountInfo* aci;
	aci = new Customer;
	aci->inputAccount();
	listAccountUser.push_back(aci);
	userNum++;
	ofstream fout("Data/User.txt");
	if (!fout.is_open()) {
		cout << "Can't write user information!!" << endl;
		return;
	}
	for (int i = 0; i < userNum; i++)
	{
		listAccountUser[i]->saveAnAccountInfor(fout);
	}
	delete aci;
}
