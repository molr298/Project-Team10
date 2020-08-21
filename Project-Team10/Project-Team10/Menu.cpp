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
		"Search",	//ban
		"Notification", //view report, accept 
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
			ShowTitle();
		switch (choice)
		{
		case 1:	//View profile
		{
			adminInfo.displayAccountInfo();
			ShowMenuEdit(adminInfo, adminAcc);
			break;
		}
		case 2:	//Find another user
		{
			string IDUser;
			cout << "Enter ID of User: ";
			cin.ignore();
			getline(cin, IDUser);
			
			AccountInfo findUser;
			findUser.findUser(IDUser)->displayAccountInfo();
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
		"Search",	//search another user
		"Shopping",	//search product, filter, cart
		"Notification",
		"History",	//View history, rate product? rate seller?
		"Log out"
	};
	int nCommandPart = 6;

	while (true) {
		ShowTitle();
		cout << "                    CUSTOMER                    " << endl;
		for (int i = 0; i < nCommandPart; i++) {
			cout << i + 1 << ". " << command[i] << endl;
		}

		cout << "________________________________________________" << endl;

		int choice;
		cout << "Input your choice: ";	cin >> choice;
			ShowTitle();
		switch (choice)
		{
		case 1:	//View profile, edit
		{
			customerInfo.displayAccountInfo();
			ShowMenuEdit(customerInfo, customerAcc);
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
		case 5: //View history \rate product? rate seller?
		{
			return;
		}
		case 6://Log out 
		{
			cin.ignore();
			return;
		}
		default:
			break;
		}
		system("pause");

	}
}

void Menu::ShowMenuSeller(AccountInfo& sellerInfo, Account& sellerAcc)
{
	string command[] =
	{
		"View profile", //Can edit info
		"Search",	//search another user, product
		"Shopping",	//search product, filter, cart
		"Store",	//store of seller
		"Notification",
		"History", //View shopping history, selling history, selling static \rate other seller? rate customer? rate product?
		"Log out"
	};
	int nCommandPart = 7;

	while (true) {
		ShowTitle();
		cout << "                      SELLER                    " << endl;
		for (int i = 0; i < nCommandPart; i++) {
			cout << i + 1 << ". " << command[i] << endl;
		}

		cout << "________________________________________________" << endl;

		int choice;
		cout << "Input your choice: ";	cin >> choice;
			ShowTitle();
		switch (choice)
		{
		case 1:	//View profile
		{
			sellerInfo.displayAccountInfo();
			ShowMenuEdit(sellerInfo, sellerAcc);
			break;
		}
		case 2:	//Find another user
		{
			ShowMenuUserFindUser(sellerInfo);
			break;
		}
		case 3:	//Shopping
		{
			break;
		}
		case 4:	//Store of seller
		{
			break;
		}
		case 5:	//Notification
		{
			break;
		}
		case 6: //History
		{
			break;
		}
		case 7://Log out 
		{
			cin.ignore();
			return;
		}
		default:
			break;
		}
		system("pause");
	}
}

void Menu::ShowMenuEditInfo(AccountInfo& accInfo)
{
	while (true)
	{

	ShowTitle();
	accInfo.displayAccountInfo();
	cout << "1. Edit your full name" << endl;
	cout << "2. Edit your user name" << endl;
	cout << "3. Edit your phone number" << endl;
	cout << "4. Edit your day of birth" << endl;
	cout << "5. Edit your gender" << endl;
	cout << "0. Return" << endl;
	cout << "_____________________________________" << endl;

	int choice = 0;
	cout << "Enter your choice: "; cin >> choice;
	accInfo.editInfo(choice);
	if (choice == 0)
		return;
	accInfo.setAccountInfo(accInfo);
	}
}

void Menu::ShowMenuEdit(AccountInfo& accInfo, Account& Acc)
{
	cout << "_____________________________________" << endl;
	cout << "1. Edit your info" << endl;
	cout << "2. Change password" << endl;
//	(accInfo.getStatus() == 1) ? cout << "3. Send request sale authorization"  : ;
	if (accInfo.getStatus() == 0)
		cout << "3. Send request sale authorization" << endl;
	cout << "0. Return" << endl;
	cout << "_____________________________________" << endl;
	cout << "Enter choice: ";
	int choice = 0;
	cin >> choice;
	if (choice == 1) {
		ShowMenuEditInfo(accInfo);
		if (accInfo.getUsername() != Acc.getUsername()) {
			Acc.changeUsername(accInfo.getUsername());
		}
		ShowTitle();
		accInfo.displayAccountInfo();
		cout << "Edit your information success" << endl;
		cout << "Press any key to return..." << endl;
	}
	else if (choice == 2) {
		Acc.changePassword();
		cout << "Change password success" << endl;
	}
	else if (choice == 3 && accInfo.getStatus() == 0) {
		Customer CusRequest;
		CusRequest.requestToBeSeller(accInfo.getID());
		cout << "Your request have sent. Please wait for the consent of the admin..." << endl;
	}
	else if (choice == 0) {
	//	cin.ignore();
		return;
	}
}

void Menu::ShowMenuUserFindUser(AccountInfo userInfo)
{
	string IDUser;
	cout << "Enter ID of User: ";
	cin.ignore();
	getline(cin, IDUser);
	if (IDUser == "") {
		return;
	}
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

void Menu::ShowMenuShopping(AccountInfo& accInfo)
{
	ShowTitle();
	cout << "1. Search product" << endl;
	cout << "2. Filter by type" << endl;
	cout << "0. Return" << endl;
	int choice = 0;
	cout << "_____________________________________" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		//
		break;
	}
	case 2:
	{
		//
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

void Menu::ShowMenuBuyStuff(AccountInfo& accInfo)	//use this when you choose a product
{
	ShowTitle();
	cout << "1. Buy now" << endl;
	cout << "2. Add to temporary cart" << endl;
	cout << "0. Return" << endl;
	int choice = 0;
	cout << "_____________________________________" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		//code here
		break;
	}
	case 2:
	{
		//code here
		break;
	}
	case 0:
	{
	//	cin.ignore();
		return;
	}
	default:
		break;
	}
}

void Menu::ShowMenuNotification(AccountInfo& accInfo)
{
	ShowTitle();
	if (accInfo.getUsername().substr(0, 7) == "197.000") 	//admin
	{
		//code here
	}
	else 	//user
	{
		//code here
	}
}

void Menu::ShowMenuHistory(AccountInfo& accInfo)//View shopping history, selling history, selling static \rate other seller? rate customer? rate product?
{
	ShowTitle();
	cout << "1. View shopping history" << endl;
	if (accInfo.getStatus() == 0) {	//customer
		cout << "0. Return" << endl;
	}
	else {	//seller
		cout << "2. Selling history" << endl;
		cout << "3. Selling static" << endl;
		cout << "0. Return" << endl;
	}

	int choice = 0;
	cout << "_____________________________________" << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	switch (accInfo.getStatus())
	{
	case 1: //seller
	{
		switch (choice)
		{
		case 1:
		{
			//code here
			break;
		}
		case 2:
		{
			//code here
			break;
		}
		case 3:
		{
			//code here
			break;
		}
		case 0:
		{
			return;
		}
		default:
			break;
		}
	}
	case 0: //customer
	{
		switch (choice)
		{
		case 1:
		{
			//code here
			break;
		}
		case 0:
		{
			return;
		}
		default:
			break;
		}
	}
	default:
		break;
	}
}




