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

string Account::HashPassword(string passWord)
{
	SHA256 sha256;
	string hashPass = sha256(passWord);
	return hashPass;
}

void Account::saveAccount(ofstream& fout)
{
	fout << username << endl;
	fout << passHash << endl;
	fout << ID << endl << endl;
}

void Account::loadListIDOfUser()
{
	ifstream fin("Account/UserID.txt");
	if (!fin.is_open())
	{
		cout << "Can't load list ID of user!!" << endl;
		return;
	}
	int nID = 0;
	string ID;
	fin >> nID;
	fin.ignore();
	for(int i=0;i<nID;i++) {
		getline(fin, ID);
		listID.push_back(ID);
	}

}

string Account::createNewID()
{
 string newID;
	loadListIDOfUser();
	newID = to_string(stoi(listID[listID.size() - 1]) + 1);
	listID.push_back(newID);
	saveListIDOfUSer();
	listID.clear();
	return newID;
}

void Account::saveListIDOfUSer()
{
	ofstream fout("Account/UserID.txt");
	if (!fout.is_open()) {
		cout << "Can't save list ID of user!!" << endl;
		return;
	}
	fout << listID.size() << endl;
	for (int i = 0; i < listID.size(); i++)
		fout << listID[i];
	fout.close();
}

Account Account::createNewAccount()
{
	string password, username, retypePassword;
	string ID;
		cout << "Username:";
		cin.ignore();
		getline(cin, username);
	do {
		cout << "Password: ";
		password = inputPassword();
		cout << "Retype password: ";
		string retypePassword;
		retypePassword = inputPassword();
		if (password != retypePassword) {
			cout << "Retype password and new password is not match\nPress any key to try again";
			system("cls");
			cout << "Username:" << username << endl;
		}
	} while (password != retypePassword);
	
	this->ID = createNewID();
	this->username = username;
	this->passHash = HashPassword(password);
	return *this;
}

void Account::changePassword()
{
	system("cls");
	string passOld, passNew, passRetype;
	passNew = "";
	passOld = "";
	passRetype = "";
	do {
		cout << "Current password: ";
		cin.ignore();
		passOld = inputPassword();
		passOld = HashPassword(passOld);
		if (passOld != this->getPassHass()) {
			cout << "Retype password and new password is not match\n" << endl;
			cout << "Do you want to try again?(Y/N) ";
			while (true)
			{
				char ch;
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					cin.ignore();
					break;
				}
				else if (ch == 'n' || ch == 'N')
					return;
				else
					cout << "Bad choice, try again\n";
			}
			system("cls");
		}
	} while (passOld != this->passHash); //check right password
	do {
		cout << "New password: ";
		passNew = inputPassword();

		cout << "Re-type your new password: ";
		passRetype = inputPassword();
		if (passNew != passRetype) {
			cout << "Retype password and new password is not match\n";
			cout << "Do you want to try again?(Y/N) ";
			while (true)
			{
				char ch;
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					cin.ignore();
					break;
				}
				else if (ch == 'n' || ch == 'N')
					return;
				else
					cout << "Bad choice, try again\n";
			}
			system("cls");
			cout << "Current password: ";
			for (int i = 0; i < passOld.size(); i++)
				cout << "*";
			cout << endl;
		}
	} while (passNew != passRetype);
	passNew = HashPassword(passNew);
	this->passHash = passNew;

	ListAccount listAcc;
	listAcc.setAccount(*this);
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
	for (int i = 0; i < nAccount; i++) {
		
		listAccount.push_back(Account::loadAnAccount(fin));
	}
	fin.close();
}

int ListAccount::login(string username, string password)
{
	string listFile[2] = { "Admin.txt", "User.txt" };
	//0-Failed	1-User	2-Admin
	password = Account::HashPassword(password);
	if (username.substr(0, 7) == "197.000") {
		loadListAccount(ACCOUNT_PATH + listFile[0]);
		for (int i = 0; i < listAccount.size(); i++) {
			if (password == listAccount[i].getPassHass() && username == listAccount[i].getUsername()) {
				listAccount.clear();
				return 2;
			}
			else {
				listAccount.clear();
				return 0;
			}
		}
	}
	else {
		loadListAccount(ACCOUNT_PATH + listFile[1]);
		for (int i = 0; i < listAccount.size(); i++)
			if (password == listAccount[i].getPassHass() && username == listAccount[i].getUsername()) {
				listAccount.clear();
				return 1;
			}
			else {
				listAccount.clear();

				return 0;
			}
	}
	listAccount.clear();
}

void ListAccount::saveListAccount(string filename)
{
	ofstream fout(filename);
	if (!fout.is_open()) {
		cout << "Can't save Account!!" << endl;
		return;
	}
	fout << listAccount.size() << endl;
	for (int i = 0; i < listAccount.size(); i++)
		listAccount[i].saveAccount(fout);
	fout.close();
	listAccount.clear();
}

void ListAccount::SignUp()
{
	Account newAccount;
	newAccount.createNewAccount();
	loadListAccount("Account/User.txt");
	listAccount.push_back(newAccount);
	saveListAccount("Account/User.txt");
	listAccount.clear();
}

void ListAccount::removeAccount(string removeID) {
	//string removeID = "";
	//cout << "Input ID of user to remove: ";
	//cin.ignore();
	//getline(cin, removeID);
	loadListAccount("Account/User.txt");

	for (int i = 0; i < listAccount.size(); i++)
		if (removeID == listAccount[i].getID())
			listAccount.erase(listAccount.begin() + i);

	saveListAccount("Account/User.txt");
	listAccount.clear();
}

Account ListAccount::findAccount(string username)
{
	Account result;
	string filename = "Admin.txt";
	loadListAccount(ACCOUNT_PATH + filename);
	for (int i = 0; i < listAccount.size(); i++) {
		if (listAccount[i].getUsername() == username) {
			result = listAccount[i];
			break;
		}

	}
	listAccount.clear();
	return result;
}

void ListAccount::setAccount(Account& newAccount)
{
	if (newAccount.getUsername().substr(0, 7) == "197.000") {
		loadListAccount("Account/Admin.txt");
		for (int i = 0; i < listAccount.size(); i++) {
			if (listAccount[i].getID() == newAccount.getID())
				listAccount[i] = newAccount;
		}
			saveListAccount("Account/Admin.txt");
	}
	else {
		loadListAccount("Account/User.txt");
		for (int i = 0; i < listAccount.size(); i++) {
			if (listAccount[i].getID() == newAccount.getID())
				listAccount[i] = newAccount;
		}
		saveListAccount("Account/User.txt");
	}
}


