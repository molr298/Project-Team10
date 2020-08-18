//#include "Menu.h"
//
//void Menu::ShowTitle()
//{
//	cout << "            E-Ecommerce Program Offline         " << endl;
//	cout << "______________________EPO10_____________________" << endl;
//}
//
//void Menu::ShowMenu(AccountInfo& loginAccInfo, Account& loginAcc, ListAccount& listAcc, int loginResult)
//{
//	// login result: 0-failed 1-User 2-Admin
//	if (loginResult == 0) {
//		cout << "Error: SIGN IN FAILED - THIS ACCOUNT IS NOT EXIST" << endl;
//		return;
//	}
//	cout << "Hi ";
//	(loginAccInfo.getGender()) ? cout << "Ms" : cout << "Mr" << endl;
//	cout << loginAccInfo.getFullname() << endl;
//	if (loginResult == 1)
//		if (loginAccInfo.getStatus() == 0)
//			ShowMenuCustomer(loginAccInfo, loginAcc);
//		else ShowMenuSeller(loginAccInfo, loginAcc);
//	else ShowMenuAdmin(loginAccInfo, loginAcc, listAcc);
//}
//
//void Menu::ShowMenuAdmin(AccountInfo& adminInfo, Account& adminAcc, ListAccount& listAcc)
//{
//	string command[] =
//	{
//		"View profile",
//		"Search",
//		"Notification",
//		"Log out"
//	};
//	int nCommandPart = 4;
//
//	while (true) {
//		system("cls");
//		ShowTitle();
//		cout << "                      ADMIN                     " << endl;
//		for (int i = 0; i < nCommandPart; i++) {
//			cout << i + 1 << command[i] << endl;
//		}
//
//		cout << "0. Return" << endl;
//		cout << "________________________________________________" << endl;
//
//		int choice;
//		cout << "Input your choice: ";	cin >> choice;
//		switch (choice)
//		{
//			system("cls");
//			ShowTitle();
//		case 1:	//View profile
//		{
//			adminInfo.displayAccountInfo();
//		}
//		case 2:	//Find another user
//		{
//			string IDUser;
//			cout << "Enter ID of User: ";
//			getline(cin, IDUser);
//			
//			adminInfo.findUser(IDUser)->displayAccountInfo();
//			cout << "Is this account violated? (Y/N) ";
//			while (true)
//			{
//				char ch;
//				cin >> ch;
//				if (ch == 'y' || ch == 'Y')
//				{
//					adminInfo.removeAccountInfo(IDUser);
//					listAcc.removeAccount(IDUser);
//					
//				}
//				else if (ch == 'n' || ch == 'N')
//					return;
//				else
//					cout << "Bad choice, try again\n";
//			}
//		}
//		case 3:	//Notification
//		{
//
//		}
//		case 4:	//Log out 
//		{
//			cin.ignore();
//			return;
//		}
//		default:
//			break;
//		}
//	}
//}
//
//void Menu::ShowMenuCustomer(AccountInfo& customerInfo, Account& customerAcc)
//{
//	string command[] =
//	{
//		"View profile", //Can edit info, change password
//		"Search",	//search another user, product
//		"Shopping",	
//		"Notification",
//		"Cart",	//View cart, User decide to buy or not
//		"History",	//View history, rate product? rate seller?
//		"Log out"
//	};
//	int nCommandPart = 7;
//
//	while (true) {
//		system("cls");
//		ShowTitle();
//		cout << "                      ADMIN                     " << endl;
//		for (int i = 0; i < nCommandPart; i++) {
//			cout << i + 1 << command[i] << endl;
//		}
//
//		cout << "0. Return" << endl;
//		cout << "________________________________________________" << endl;
//
//		int choice;
//		cout << "Input your choice: ";	cin >> choice;
//		switch (choice)
//		{
//			system("cls");
//			ShowTitle();
//		case 1:	//View profile, edit
//		{
//			customerInfo.displayAccountInfo();
//		}
//		case 2:	//Find another user
//		{
//			string IDUser;
//			cout << "Enter ID of User: ";
//			getline(cin, IDUser);
//
//			customerInfo.findUser(IDUser)->displayAccountInfo();
//
//		}
//		case 3:	//Shopping
//		{
//
//		}
//		case 4:	//Notification
//		{
//
//		}
//		case 5:	//Cart
//		{
//			return;
//		}
//		case 6: //View history \rate product? rate seller?
//		{
//
//		}
//		case 7://Log out 
//		{
//			cin.ignore();
//			return;
//		}
//		default:
//			break;
//		}
//	}
//}
//
//void Menu::ShowMenuSeller(AccountInfo& sellerInfo, Account& sellerAcc)
//{
//	string command[] =
//	{
//		"View profile", //Can edit info
//		"Search",	//search another user, product
//		"Shopping",
//		"Store",	//store of seller
//		"Notification",
//		"Cart",
//		"History", //View shopping history, selling history, selling static \rate other seller? rate customer? rate product?
//		"Log out"
//	};
//	int nCommandPart = 8;
//
//	while (true) {
//		system("cls");
//		ShowTitle();
//		cout << "                      ADMIN                     " << endl;
//		for (int i = 0; i < nCommandPart; i++) {
//			cout << i + 1 << command[i] << endl;
//		}
//
//		cout << "0. Return" << endl;
//		cout << "________________________________________________" << endl;
//
//		int choice;
//		cout << "Input your choice: ";	cin >> choice;
//		switch (choice)
//		{
//			system("cls");
//			ShowTitle();
//		case 1:	//View profile
//		{
//			sellerInfo.displayAccountInfo();
//		}
//		case 2:	//Find another user
//		{
//			string IDUser;
//			cout << "Enter ID of User: ";
//			getline(cin, IDUser);
//
//			sellerInfo.findUser(IDUser)->displayAccountInfo();
//		}
//		case 3:	//Shopping
//		{
//
//		}
//		case 4:	//Store of seller
//		{
//
//		}
//		case 5:	//Notification
//		{
//
//		}
//		case 6:	//Cart
//		{
//			return;
//		}
//		case 7: //History
//		{
//
//		}
//		case 8://Log out 
//		{
//			cin.ignore();
//			return;
//		}
//		default:
//			break;
//		}
//	}
//}
//
//void Menu::ShowMenuEditInfo(AccountInfo& accInfo, Account& Acc)
//{
//	cout << "_____________________________________" << endl;
//	cout << "1. Edit your info" << endl;
//	cout << "2. Change password" << endl;
//	cout << "0. Return" << endl;
//	cout << "_____________________________________" << endl;
//	cout << "Enter choice: ";
//	int choice = 0;
//	cin >> choice;
//	system("cls");
//	if (choice == 1) {
//		ShowTitle();
//		accInfo.displayAccountInfo();
//		accInfo.editInfo();
//		system("cls");
//		accInfo.displayAccountInfo();
//		cout << "Edit your information success" << endl;
//	}
//	else if (choice == 2) {
//		Acc.changePassword();
//		cout << "Change password success" << endl;
//	}
//	else if (choice == 0) {
//		cin.ignore();
//		return;
//	}
//}
//
//
//
//
