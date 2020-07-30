#include "Customer.h"

//void Customer::loadListUser()
//{
//	ifstream fin("Data/User.txt");
//	if (!fin.is_open()) {
//		cout << "Can't open User.txt!!" << endl;
//		return;
//	}
//	int nUser;
//	fin >> nUser;
//	for (int i = 0; i < nUser; i++) 
//		listUser.push_back(AccountInfo::loadAnAccountInfo(fin));
//	fin.close();
//}

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

//AccountInfo Customer::findUser(const int& ID)
//{
//	for (int i = 0; i < listUser.size(); i++)
//		if (listUser[i].getID() == ID)
//			return listUser[i];
//}
//
//AccountInfo Customer::findUser(const string& Username)
//{
//	for (int i = 0; i < listUser.size(); i++)
//		if (listUser[i].getUserName() ==Username)
//			return listUser[i];
//}

//AccountInfo Customer::findUser(const int& ID)
//{
//	for(int i=0;i<listUser.size();i++)
//		if(listUser[i].)
//}


