#include "AccountInfo.h"
string inputDate() {
	int day, month, year;
	cout << endl;
	cout << "Day: ";	cin >> day;
	cout << "Month: ";	cin >> month;
	cout << "Year: ";	cin >> year;
	return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

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
void AccountInfo::saveAnAccountInfor(ofstream& fout)
{
	fout << ID << endl;
	fout << username << endl;
	fout << fullname << endl;
	fout << DoB << endl;
	fout << phoneNumber << endl;
	fout << gender << endl;
	fout << status << endl << endl;
}
void AccountInfo::inputAccount(const string& username, const string& ID)
{
	cout << "______________________________________" << endl;

	cout << "Enter Full name: ";
	getline(cin, fullname);
	cout << "Enter Day of birth: ";
	DoB = inputDate();
	cout << "Enter Phone number: ";
	cin >> phoneNumber;
	cout << "Enter your gender(MALE/FEMALE): ";
	string gender;
	cin.ignore();
	getline(cin, gender);
	for (int i = 0; i < gender.size(); i++)
		gender[i] = toupper(gender[i]);
	(gender == "MALE") ? this->gender = 0 : this->gender = 1;
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
	fin.open("Data/User.txt");
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
void AccountInfo::registerAccount(const string& username, const string& ID)
{
	AccountInfo aci;
	AccountInfo::loadListUser();
	aci.inputAccount(username, ID);
	listUser.push_back(aci);
	AccountInfo::saveListUser();
}
void AccountInfo::loadListAdmin()
{
	listAdmin.clear();
	ifstream fin;
	fin.open("Data/Admin.txt");
	if (!fin.is_open()) {
		cout << "Can't open Admin.txt!!" << endl;
		return;
	}
	int nAdmin;
	fin >> nAdmin;
	for (int i = 0; i < nAdmin; i++)
	{
		string line;
		getline(fin, line);
		listAdmin.push_back(AccountInfo::loadAnAccountInfo(fin));
	}
	fin.close();
}

void AccountInfo::saveListAdmin()
{
	ofstream fout("Data/Admin.txt");
	fout << listAdmin.size() << endl;
	for (int i = 0; i < listAdmin.size(); i++)
		listAdmin[i].saveAnAccountInfor(fout);
	fout.close();
	listAdmin.clear();
}

AccountInfo* AccountInfo::findAdmin(const string& find)
{
	loadListAdmin();
	for (int i = 0; i < listAdmin.size(); i++)
		if (listAdmin[i].getUsername() == find || listAdmin[i].getID() == find )
		{
			return &listAdmin[i];
		}
	return nullptr;
}


void AccountInfo::saveListUser()
{
	ofstream fout("Data/User.txt");
	fout << listUser.size() << endl;
	for (int i = 0; i < listUser.size(); i++)
		listUser[i].saveAnAccountInfor(fout);
	fout.close();
	listUser.clear();
}
//
//AccountInfo AccountInfo::findUser(const int& ID)
//{
//	for (int i = 0; i < listUser.size(); i++)
//		if (listUser[i].getID() == ID)
//			return listUser[i];
//}

AccountInfo* AccountInfo::findUser(const string& find)
{
	loadListUser();
	for (int i = 0; i < listUser.size(); i++)
		if (listUser[i].getUsername() == find || listUser[i].getID()==find)
		{
			return &listUser[i];
		}
	return nullptr;
}

void AccountInfo::displayListUser()
{
	for (int i = 0; i < listUser.size(); i++) {
		listUser[i].displayAccountInfo();
	}
	cout << "________________________________" << endl;
}

void AccountInfo::editInfo(int choice)
{
	switch (choice)
	{
	case 1:
	{
		cout << "Enter your full name: ";
		cin.ignore();
		getline(cin, this->fullname);
		break;
	}
	case 2:
	{
		cout << "Enter your phone number: ";
		cin >> phoneNumber;
		break;
	}
	case 3: {
		cout << "Enter your day of birth: ";
		this->DoB = inputDate();
		break;
	}
	case 4:
	{
		cout << "Enter your gender(MALE/FEMALE): ";
		string gender;
		cin.ignore();
		getline(cin, gender);
		for (int i = 0; i < gender.size(); i++)
			gender[i] = toupper(gender[i]);
		(gender == "MALE") ? this->gender = 0 : this->gender = 1;
		break;
	}
	case 0:
	{
		cin.ignore();
		return;
	}
	default:
		break;
	}
}


void AccountInfo::removeAccountInfo(const string& IDRemove)
{
	loadListUser();
	for (int i = 0; i < listUser.size(); i++)
		if (listUser[i].getID() == IDRemove)
			listUser.erase(listUser.begin() + i);
	saveListUser();
	listUser.clear();
}

void AccountInfo::setAccountInfo(AccountInfo newAccInfo)
{
	if (newAccInfo.username.substr(0, 7) == "197.000") {
		loadListAdmin();
		for (int i = 0; i < listAdmin.size(); i++) {
			if (listAdmin[i].ID == newAccInfo.ID)
				listAdmin[i] = newAccInfo;
		}
		saveListAdmin();
	}
	else {
		loadListUser();
		for (int i = 0; i < listUser.size(); i++) {
			if (listUser[i].ID == newAccInfo.ID)
				listUser[i] = newAccInfo;
		}
		saveListUser();
	}
		*this = newAccInfo;	
}

