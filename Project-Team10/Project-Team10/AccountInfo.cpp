#include "AccountInfo.h"

AccountInfo AccountInfo::loadAnAccountInfo(ifstream& fin)
{
	fin >> ID;
	fin.ignore();
	getline(fin, username);
	getline(fin, fullname);
	getline(fin, DoB);
	fin >> phoneNumber;
	fin >> gender;
	fin >> status;
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
void AccountInfo::inputAccount()
{
	cout << "______________________________________" << endl;
	cout << "Enter ID: ";
	cin >> ID;
	cout << "Enter User name: ";
	cin >> username;
	cout << "Enter Full name: ";
	cin >> fullname;
	cout << "Enter Day of birth: ";
	cin >> DoB;
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


