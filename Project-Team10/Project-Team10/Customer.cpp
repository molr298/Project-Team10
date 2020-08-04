#include "Customer.h"

void Customer::loadListUser()
{
	ifstream fin;
	fin.open("Data/User.txt");
	if (!fin.is_open()) {
		cout << "Can't open User.txt!!" << endl;
		return;
	}
	int nUser;
	fin >> nUser;
	for (int i = 0; i < nUser; i++) 
		listUser.push_back(AccountInfo::loadAnAccountInfo(fin));
	fin.close();
}

void Customer::saveListUser()
{
	ofstream fout("Data/User.txt");
	if (!fout.is_open()) {
		cout << "Can't write user information!!" << endl;
		return;
	}
	fout << listUser.size();
	for (int i = 0; i < listUser.size(); i++)
		listUser[i].saveAnAccountInfor(fout);
	fout.close();
}

AccountInfo Customer::findUser(const string& keyword)
{
	for (int i = 0; i < listUser.size(); i++)
		if (listUser[i].getID() == keyword || listUser[i].getUsername() == keyword)
			return listUser[i];
}


void Customer::displayListUser()
{
	for (int i = 0; i < listUser.size(); i++) {
		listUser[i].displayAccountInfo();
	}
		cout << "________________________________" << endl;
}



