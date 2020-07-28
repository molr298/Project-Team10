#include "AccountInfo.h"

AccountInfo AccountInfo::loadAnAccountInfo(ifstream& fin)
{
	fin >> ID;
	fin.ignore();
	getline(fin, username);
	getline(fin, fullname);
	getline(fin, DoB);
	getline(fin, address);
	fin >> phoneNumber;
	fin >> gender;
	return *this;
}

void AccountInfo::saveAnAccountInfor(ofstream& fout)
{
	fout << ID << endl;
	fout << username << endl;
	fout << fullname << endl;
	fout << DoB << endl;
	fout << address << endl;
	fout << phoneNumber << endl;
	fout << gender << endl << endl;
}

void AccountInfo::displayAccountInfo()
{
	cout << "--------------------------------------" << endl;
	cout << "ID: " << ID << endl;
	cout << "Full name: " << fullname << endl;
	cout << "Day of birth: " << DoB << endl;
	cout << "Address: " << address << endl;
	cout << "Phone number: " << phoneNumber << endl;
	cout << "Gender: "; (gender = 0) ? cout << "MALE" : cout << "FEMALE";
}

