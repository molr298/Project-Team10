#include "Menu.h"

void Menu::ShowTitle()
{
	system("cls");
	cout << "            E-Ecommerce Program Offline         " << endl;
	cout << "______________________EPO10_____________________" << endl;
}

void Menu::ShowMenu(AccountInfo& loginAccInfo, Account& loginAcc, ListAccount& listAcc, int loginResult)
{
	// login result: 0-failed 1-User 2-Admin
	if (loginResult == 0) {
		cout << "Error: SIGN IN FAILED - THIS ACCOUNT IS NOT EXIST" << endl;
		return;
	}
	cout << "Hi ";
	(loginAccInfo.getGender()) ? cout << "Ms" : cout << "Mr" << endl;
	cout << loginAccInfo.getFullname() << endl;
	if (loginResult == 1)
		if (loginAccInfo.getStatus() == 0)
			ShowMenuCustomer(loginAccInfo, loginAcc);
		else ShowMenuSeller(loginAccInfo, loginAcc);
	else ShowMenuAdmin(loginAccInfo, loginAcc, listAcc);
}

void Menu::ShowMenuAdmin(AccountInfo& adminInfo, Account& adminAcc, ListAccount& listAcc)
{
	string command[] =
	{
		"View profile",
		"Search",
		"Notification",
		"Log out"
	};
	int nCommandPart = 4;

	while (true) {
		ShowTitle();
		cout << "                      ADMIN                     " << endl;
		for (int i = 0; i < nCommandPart; i++) {
			cout << i + 1 <<". " << command[i] << endl;
		}
		cout << "________________________________________________" << endl;

		int choice;
		cout << "Input your choice: ";	cin >> choice;
		switch (choice)
		{
			ShowTitle();
		case 1:	//View profile
		{
			adminInfo.displayAccountInfo();
			break;
		}
		case 2:	//Find another user
		{
			string IDUser;
			cout << "Enter ID of User: ";
			cin.ignore();
			getline(cin, IDUser);
			
			adminInfo.findUser(IDUser)->displayAccountInfo();
			cout << "Is this account violated? (Y/N) ";
			while (true)
			{
				char ch;
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					adminInfo.removeAccountInfo(IDUser);
					listAcc.removeAccount(IDUser);

				}
				else if (ch == 'n' || ch == 'N')
					break;
				else
					cout << "Bad choice, try again\n";
			}
			break;
		}
		case 3:	//Notification
		{
			break;
		}
		case 4:	//Log out 
		{
			cin.ignore();
			return;
		}
		default:
			break;
		}
		_getch();
	}
}

void Menu::ShowMenuCustomer(AccountInfo& customerInfo, Account& customerAcc)
{
	string command[] =
	{
		"View profile", //Can edit info, change password
		"Search",	//search another user, product
		"Shopping",	
		"Notification",
		"Cart",	//View cart, User decide to buy or not
		"History",	//View history, rate product? rate seller?
		"Log out"
	};
	int nCommandPart = 7;

	while (true) {
		ShowTitle();
		cout << "                      ADMIN                     " << endl;
		for (int i = 0; i < nCommandPart; i++) {
			cout << i + 1 << command[i] << endl;
		}

		cout << "0. Return" << endl;
		cout << "________________________________________________" << endl;

		int choice;
		cout << "Input your choice: ";	cin >> choice;
		switch (choice)
		{
			ShowTitle();
		case 1:	//View profile, edit
		{
			customerInfo.displayAccountInfo();
			break;
		}
		case 2:	//Find another user
		{
			ShowMenuUserFindUser(customerInfo);
			break;
		}
		case 3:	//Shopping
		{
			return;
		}
		case 4:	//Notification
		{
			return;
		}
		case 5:	//Cart
		{
			return;
		}
		case 6: //View history \rate product? rate seller?
		{
			return;
		}
		case 7://Log out 
		{
			cin.ignore();
			return;
		}
		default:
			break;
		}
		_getch();

	}
}

void Menu::ShowMenuSeller(AccountInfo& sellerInfo, Account& sellerAcc)
{
	string command[] =
	{
		"View profile", //Can edit info
		"Search",	//search another user, product
		"Shopping",
		"Store",	//store of seller
		"Notification",
		"Cart",
		"History", //View shopping history, selling history, selling static \rate other seller? rate customer? rate product?
		"Log out"
	};
	int nCommandPart = 8;

	while (true) {
		ShowTitle();
		cout << "                      ADMIN                     " << endl;
		for (int i = 0; i < nCommandPart; i++) {
			cout << i + 1 << command[i] << endl;
		}

		cout << "0. Return" << endl;
		cout << "________________________________________________" << endl;

		int choice;
		cout << "Input your choice: ";	cin >> choice;
		switch (choice)
		{
			ShowTitle();
		case 1:	//View profile
		{
			sellerInfo.displayAccountInfo();
		}
		case 2:	//Find another user
		{
			ShowMenuUserFindUser(sellerInfo);
		}
		case 3:	//Shopping
		{

		}
		case 4:	//Store of seller
		{

		}
		case 5:	//Notification
		{

		}
		case 6:	//Cart
		{
			return;
		}
		case 7: //History
		{

		}
		case 8://Log out 
		{
			cin.ignore();
			return;
		}
		default:
			break;
		}
	}
}

void Menu::ShowMenuEditInfo(AccountInfo& accInfo)
{
	cout << "1. Edit your full name" << endl;
	cout << "2. Edit your phone number" << endl;
	cout << "3. Edit your day of birth" << endl;
	cout << "4. Edit your gender" << endl;
	cout << "0. Return" << endl;
	cout << "_____________________________________" << endl;

	int choice = 0;
	cout << "Enter your choice: "; cin >> choice;
	accInfo.editInfo(choice);
}

void Menu::ShowMenuEdit(AccountInfo& accInfo, Account& Acc)
{
	cout << "_____________________________________" << endl;
	cout << "1. Edit your info" << endl;
	cout << "2. Change password" << endl;
	cout << "0. Return" << endl;
	cout << "_____________________________________" << endl;
	cout << "Enter choice: ";
	int choice = 0;
	cin >> choice;
	if (choice == 1) {
		ShowTitle();
		accInfo.displayAccountInfo();
		ShowMenuEditInfo(accInfo);
		ShowTitle();
		accInfo.displayAccountInfo();
		cout << "Edit your information success" << endl;
	}
	else if (choice == 2) {
		Acc.changePassword();
		cout << "Change password success" << endl;
	}
	else if (choice == 0) {
		cin.ignore();
		return;
	}
}

void Menu::ShowMenuUserFindUser(AccountInfo& userInfo)
{
	string IDUser;
	cout << "Enter ID of User: ";
	getline(cin, IDUser);
	userInfo.findUser(IDUser)->displayAccountInfo();
	cout << "1. Report this user" << endl;
	cout << "0. Return" << endl;
	cout << "_____________________________________" << endl;
	int choice = 0;
	cout << "Enter your choice: ";	cin >> choice;
	Customer cus;
	switch (choice)
	{
	case 1:
	{
		ShowTitle();
		cus.sendReport(userInfo.getID());
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




