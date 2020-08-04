#include "Admin.h"
void Admin::loadListAdmin()
{
	listAdmin.clear();
	ifstream fin;
	fin.open("C:/Users/MyPC/source/repos/Project-Team10/Project-Team10/Data/Admin.txt");
	if (!fin.is_open()) {
		cout << "Can't open User.txt!!" << endl;
		return;
	}
	int nUser;
	fin >> nUser;
	for (int i = 0; i < nUser; i++)
	{
		string line;
		getline(fin, line);
		listAdmin.push_back(AccountInfo::loadAnAccountInfo(fin));
	}
	fin.close();
}
void Admin::displayListAdmin()
{
	for (int i = 0; i < listAdmin.size(); i++) {
		listAdmin[i].displayAccountInfo();
	}
	cout << "________________________________" << endl;
}

void Admin::saveUser()
{
	remove("C:/Users/MyPC/source/repos/Project-Team10/Project-Team10/Data/User.txt");
	ofstream fout("C:/Users/MyPC/source/repos/Project-Team10/Project-Team10/Data/User.txt");
	fout << listUser.size() << endl;
	for (int i = 0; i < listUser.size(); i++)
		listUser[i].saveAnAccountInfor(fout);
	fout.close();
}

void Admin::removeUser()
{
	string search;
	cout << "Enter ID or name to remove: ";
	getline(cin, search);
	AccountInfo::loadListUser();
	for (int i = 0; i < listUser.size(); i++)
	{
		if (listUser[i].getUsername() == search || listUser[i].getID() == search)
		{
			listUser.erase(listUser.begin() + i);
			break;
		}
	}
	AccountInfo::saveListUser();
}
