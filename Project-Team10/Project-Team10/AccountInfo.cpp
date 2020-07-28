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

