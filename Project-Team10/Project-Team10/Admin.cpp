#include "Admin.h"
void Admin::loadListAdmin()
{
	listAdmin.clear();
	ifstream fin;
	fin.open("Data/Admin.txt");
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

void Admin::editInfo()
{
	this->editInfo();
}

void Admin::saveUser()
{
	remove("Data/Admin.txt");
	ofstream fout("Data/Admin.txt");
	fout << listUser.size() << endl;
	for (int i = 0; i < listUser.size(); i++)
		listUser[i].saveAnAccountInfor(fout);
	fout.close();
}

void Admin::removeUser(string IDRemove)
{
	//string search;
	//cout << "Enter ID or name to remove: ";
	//getline(cin, search);
	//AccountInfo::loadListUser();
	//for (int i = 0; i < listUser.size(); i++)
	//{
	//	if (listUser[i].getUsername() == IDRemove || listUser[i].getID() == IDRemove)
	//	{
	//		listUser.erase(listUser.begin() + i);
	//		break;
	//	}
	//}
	//AccountInfo::saveListUser();

	/*AccountInfo::removeAccountInfo(IDRemove);
	ListAccount::removeAccount(IDRemove);*/
}

void Admin::sendReport(string senderID1)
{
	string takerID1;
	string problem;
	cout << "Enter user's ID to send them Report: ";
	cin >> takerID1;
	AdminNotif::loadListNotif();
	cin.ignore();
	cout << "Describe Problem: ";
	getline(cin, problem);
	AdminNotif adn;
	adn.setSenderID(senderID1);
	adn.setTakerID(takerID1);
	adn.setProblem(problem);
	adn.setStatus(0);
	adnv.push_back(adn);
	AdminNotif::saveListNotif();
}

void Admin::acceptSeller(string admin)
{
	AdminNotif::loadListNotif();
	AccountInfo::loadListUser();
	vector<int> user;
	int v = 0;
	int flag = 0;
	for (int i = 0; i < adnv.size(); i++)
	{
		if (adnv[i].getTakerID() == "Ad5" && adnv[i].getStatus()=="0")
		{
			cout << "Number " << v + 1 << endl;
			cout << "User " << adnv[i].getSenderID() << " want to become a seller" << endl;
			for (int j = 0; j < listUser.size(); j++)
			{
				if (adnv[i].getSenderID() == listUser[j].getID() && listUser[j].getStatus() == 0)
				{
					listUser[j].displayAccountInfo();
					user.push_back(j);
					flag = 1;
				}
			}
			v++;
		}
	}
	if(flag==0)
	{
		cout << "No Seller's Registration now" << endl;
		return;
	}
	int choice;
	cout << "Choose users to grant Seller's priviledge or press 0 to apply all (-1 to cancel): ";
	cin >> choice;
	if (choice == -1)
	{
		cout << "Exiting..." << endl;
		return;
	}
	if (choice == 0)
	{
		for (int j = 0; j < user.size(); j++)
		{
			listUser[user[j]].setStatus(1);
		}
		for (int i = 0; i < adnv.size(); i++)
		{
			if (adnv[i].getTakerID() == "Ad5")
			{
				adnv[i].setStatus("1");
			}
		}
	}
	else
	{
		for (int i = 0; i < adnv.size(); i++)
		{
			if (i == user[choice])
			{
				listUser[i].setStatus(1);
				adnv[i].setStatus("1");
			}
		}

	}
	AdminNotif::saveListNotif();
	AccountInfo::saveListUser();
}