#include "AccountInfo.h"

AccountInfo AccountInfo::loadAnAccountInfo(ifstream& fin)
{
	getline(fin, ID);
	getline(fin, username);
	getline(fin, fullname);
	getline(fin, DoB);
	fin >> phoneNumber;
	fin >> gender;
	fin >> status;
	fin.ignore();
	return *this;
}

void AccountInfo::saveAnAccountInfor(fstream& fout)
{
	fout << ID << endl;
	fout << username << endl;
	fout << fullname << endl;
	fout << DoB << endl;
	fout << phoneNumber << endl;
	fout << gender << endl;
	fout << status << endl << endl;
}
void AccountInfo::inputAccount()
{
	cout << "______________________________________" << endl;
	cout << "Enter ID: ";
	getline(cin, ID);
	cout << "Enter User name: ";
	getline(cin, username);
	cout << "Enter Full name: ";
	getline(cin, fullname);
	cout << "Enter Day of birth: ";
	getline(cin, DoB);
	cout << "Enter Phone number: ";
	cin >> phoneNumber;
}
void AccountInfo::displayAccountInfo()
{
	cout << "______________________________________" << endl;
	cout << "ID: " << ID << endl;
	cout << "User name: " << username << endl;
	cout << "Full name: " << fullname << endl;
	cout << "Day of birth: " << DoB << endl;
	cout << "Phone number: " << phoneNumber << endl;
	cout << "Gender: "; (gender == 0) ? cout << "MALE" << endl : cout << "FEMALE" << endl;
	if (status == 0)		cout << "CUSTOMER" << endl;
	else if (status == 1)	cout << "SELLER" << endl;
	else if (status == 2)	cout << "ADMIN" << endl;
}
void AccountInfo::loadListUser()
{
	listUser.clear();
	ifstream fin;
	fin.open("C:/Users/MyPC/source/repos/Project-Team10/Project-Team10/Data/User.txt");
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
		listUser.push_back(AccountInfo::loadAnAccountInfo(fin));
	}
	fin.close();
}
void AccountInfo::registerAccount()
{
	AccountInfo aci;
	AccountInfo::loadListUser();
	aci.inputAccount();
	listUser.push_back(aci);
	AccountInfo::saveListUser();
}
void AccountInfo::saveListUser()
{
	remove("C:/Users/MyPC/source/repos/Project-Team10/Project-Team10/Data/User.txt");
	fstream fout("C:/Users/MyPC/source/repos/Project-Team10/Project-Team10/Data/User.txt",ios::out);
	/*if (!fout.is_open()) {
		cout << "Can't write user information!!" << endl;
		return;
	}*/
	
	fout << listUser.size() << endl;
	for (int i = 0; i < listUser.size(); i++)
		listUser[i].saveAnAccountInfor(fout);
	fout.close();
}
//
//AccountInfo AccountInfo::findUser(const int& ID)
//{
//	for (int i = 0; i < listUser.size(); i++)
//		if (listUser[i].getID() == ID)
//			return listUser[i];
//}

AccountInfo AccountInfo::findUser(const string& Username)
{
	for (int i = 0; i < listUser.size(); i++)
		if (listUser[i].getUsername() == Username)
			return listUser[i];
}

void AccountInfo::displayListUser()
{
	for (int i = 0; i < listUser.size(); i++) {
		listUser[i].displayAccountInfo();
	}
	cout << "________________________________" << endl;
}

void AccountInfo::editInfo()
{
	string search;
	cout << "Enter ID or name to edit: ";
	getline(cin, search);
	AccountInfo::loadListUser();
	AccountInfo aci;
	aci.inputAccount();
	for (int i = 0; i < listUser.size(); i++) 
	{
		if (listUser[i].getUsername() == search || listUser[i].getID() == search)
		{
			listUser[i] = aci;
		}
	}
	AccountInfo::saveListUser();
}

