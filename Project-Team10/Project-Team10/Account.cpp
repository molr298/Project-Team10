#include "Account.h"

Account Account::loadAnAccount(ifstream& fin)
{
	fin.ignore();
	getline(fin, username);
	getline(fin, passHash);
	fin >> ID;
	return *this;
}

string Account::inputPassword()
{
	string passWord = "";
	char c = _getch();
	while (c != '\n' && c != '\r')
	{
		if (c == '\b')
		{
			int count = passWord.length();
			if (count > 0)
			{
				std::cout << "\b \b";
				passWord = passWord.substr(0, passWord.length() - 1);
			}
		}
		else
			if (c == 27)
			{
				return "";
			}
			else
			{
				std::cout << "*";
				passWord += c;
			}
		c = _getch();
	}
	std::cout << "\n";
	return passWord;
}

//string Account::HashPassword(string passWord)
//{
//	SHA256 sha256;
//	string hashPass = sha256(passWord);
//	return hashPass;
//}

void Account::saveAccount(ofstream& fout)
{
	fout << username << endl;
	fout << passHash << endl;
	fout << ID << endl << endl;
}

void ListAccount::loadListAccount(string filename)
{
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "Can't open " << filename << "!!" << endl;
		return;
	}
	int nAccount;
	fin >> nAccount;
	for (int i = 0; i < nAccount; i++) 
		listAccount.push_back(Account::loadAnAccount(fin));
	fin.close();
}

int ListAccount::login(string username, string password)
{
	string listFile[2] = { "Admin.txt", "User.txt" };
	//0-Failed	1-User	2-Admin
	//password = Account::HashPassword(password);
	if (username.substr(0, 7) == "197.000") {
		loadListAccount(listFile[0]);
		for (int i = 0; i < listAccount.size(); i++)
			if (password == listAccount[i].getPassHass() && username == listAccount[i].getUsername())
				return 2;
	}
	else {
		loadListAccount(listFile[1]);
		for (int i = 0; i < listAccount.size(); i++)
			if (password == listAccount[i].getPassHass() && username == listAccount[i].getUsername())
				return 1;
	}
	return 0;
}

void ListAccount::saveListAccount(const int& nAccount, string filename)
{
	ofstream fout(filename);
	if (!fout.is_open()) {
		cout << "Can't save Account!!" << endl;
		return;
	}
	fout << nAccount << endl;
	for (int i = 0; i < listAccount.size(); i++)
		listAccount[i].saveAccount(fout);
	fout.close();
}
