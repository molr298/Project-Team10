#include "Account.h"
//void ListAccount::loadListAdminAccount()
//{
//	AccountInfo aci;
//	ifstream fin("Data/Admin.txt");
//	if (!fin.is_open()) {
//		cout << "Can't open Admin.txt!!" << endl;
//		return;
//	}
//	int adminNum;
//	fin >> adminNum;
//	for (int i = 0; i < adminNum; i++)
//	{
//		aci = loadAnAccountInfo(fin);
//		listAccountAdmin.push_back(aci);
//	}
//	fin.close();
//}
//void ListAccount::loadListUserAccount()
//{
//	AccountInfo* aci;
//	ifstream fin("Data/User.txt");
//	if (!fin.is_open()) {
//		cout << "Can't open User.txt!!" << endl;
//		return;
//	}
//	fin >> userNum;
//	fin.close();
//	aci = new Customer;
//	for (int i = 0; i < userNum; i++)
//	{
//		
//		aci->loadAnAccountInfo(fin);
//		listAccountUser.push_back(aci);
//		
//	}
//	fin.close();
//	for (int i = 0; i < userNum; i++)
//	{
//		listAccountUser[i]->displayAccountInfo();
//
//	}
//	delete aci;
//}
//void ListAccount::registerUserAccount()
//{
//	cout << "Welcome to user area, enter your personal information to get started !" << endl;
//	AccountInfo* aci;
//	aci = new Customer;
//	aci->inputAccount();
//	listAccountUser.push_back(aci);
//	userNum++;
//	ofstream fout("Data/User.txt");
//	if (!fout.is_open()) {
//		cout << "Can't write user information!!" << endl;
//		return;
//	}
//	for (int i = 0; i < userNum; i++)
//	{
//		listAccountUser[i]->saveAnAccountInfor(fout);
//	}
//	delete aci;
//}


//Account Account::loadAnAccount(ifstream& fin)
//{
//	fin.ignore();
//	getline(fin, username);
//	getline(fin, passHash);
//	fin >> ID;
//	return *this;
//}
//
//string Account::inputPassword()
//{
//	string passWord = "";
//	char c = _getch();
//	while (c != '\n' && c != '\r')
//	{
//		if (c == '\b')
//		{
//			int count = passWord.length();
//			if (count > 0)
//			{
//				std::cout << "\b \b";
//				passWord = passWord.substr(0, passWord.length() - 1);
//			}
//		}
//		else
//			if (c == 27)
//			{
//				return "";
//			}
//			else
//			{
//				std::cout << "*";
//				passWord += c;
//			}
//		c = _getch();
//	}
//	std::cout << "\n";
//	return passWord;
//}
//
//string Account::HashPassword(string passWord)
//{
//	SHA256 sha256;
//	string hashPass = sha256(passWord);
//	return hashPass;
//}
//
//void ListAccount::loadListAccount(string filename, int type)
//{
//	ifstream fin(filename);
//	if (!fin.is_open()) {
//		cout << "Can't open " << filename << "!!" << endl;
//		return;
//	}
//	int nAccount;
//	fin >> nAccount;
//	for (int i = 0; i < nAccount; i++) 
//		listAccount.push_back(Account::loadAnAccount(fin));
//	fin.close();
//}

//int ListAccount::login(string username, string password)
//{
//	string listFile[2] = { "Admin.txt", "User.txt" };
//	//0-Failed	1-User	2-Admin
//	password = Account::HashPassword(password);
//	
//
//}
