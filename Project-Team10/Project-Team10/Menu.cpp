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
			ShowMenuNotification(adminInfo);
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
			Customer cusShopping;
			UserNotif usn;

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
			ShowMenuShopping(customerInfo, cusShopping, usn);
			break;
		}
		case 4:	//Notification
		{
			ShowMenuNotification(customerInfo);
			break;
		}
		case 5: //View history \rate product? rate seller?
		{
			ShowMenuHistory(customerInfo);
			break;
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
	Customer cusShopping;
	UserNotif usn;
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

			ShowMenuShopping(sellerInfo, cusShopping, usn);
			break;
		}
		case 4:	// edit product
		{
			Product storeOfSeller;
			storeOfSeller.viewStoreOfSeller(sellerInfo.getID());
			storeOfSeller.editProduct();
			break;
		}
		case 5:	//Notification
		{
			ShowMenuNotification(sellerInfo);
			break;
		}
		case 6: //History
		{
			ShowMenuHistory(sellerInfo);
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
	while (true)
	{
	string IDUser;
	cout << "Enter ID of User: ";
	cin.ignore();
	getline(cin, IDUser);
	if (IDUser == "") {
		return;
	}
	if (userInfo.getID() == IDUser) {
		cout << "Please choose ""Store"" feature to view your Store or ""View profile"" to view your information" << endl;
		return;
	}

		AccountInfo* anotherUser;
		anotherUser = userInfo.findUser(IDUser);
		anotherUser->displayListUser();
		cout << "1. Report this user" << endl;
		(anotherUser->getStatus() == 1) ? cout << "2. View store of seller" << endl : cout << "";
		cout << "0. Return" << endl;
		cout << "_____________________________________" << endl;
		int choice = 0;
		cout << "Enter your choice: ";	cin >> choice;
		Customer cus;
		if (choice == 1) {
			ShowTitle();
			cus.sendReport(userInfo.getID());
		}
		else if (choice == 2 && anotherUser->getStatus() == 1) {

			Product storeOfSeller;
			storeOfSeller.viewStoreOfSeller(anotherUser->getID());
		//	_getch();
		}
		else if (choice == 0)
		{
			cin.ignore();
			return;
		}
		else return;
	}
}

void Menu::ShowMenuShopping(AccountInfo& accInfo, Customer& cusShopping, UserNotif& usn)
{

	while (true) {
		ShowTitle();
		cout << "1. Search product" << endl;
		cout << "2. Filter by type" << endl;
		cout << "3. View cart" << endl;
		cout << "0. Return" << endl;
		int choice = 0;
		cout << "_____________________________________" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			ShowTitle();

			bool flag = cusShopping.listSearchProduct();
			cusShopping.buyStuff(usn, accInfo.getID(), flag);
			system("pause");

			break;
		}
		case 2:
		{
			ShowTitle();
			bool flag = cusShopping.listFilterProduct();
			cusShopping.buyStuff(usn, accInfo.getID(), flag);
			system("pause");
			break;
		}
		case 3:
		{
			ShowTitle();
			cusShopping.viewCart(0);
			cout << "1. Modify cart" << endl;
			cout << "2. Confirm cart" << endl;
			cout << "0. Return" << endl;
			cout << "Option: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				cusShopping.setOrder(accInfo.getID());
				break;
			}
			case 2:
			{
				cusShopping.confirmCart(accInfo.getID());
				break;
			}
			case 0:
			{
				//cusShopping.setShip(1);
				break;
			}
			default:
				break;
			}
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
}

void Menu::ShowMenuBuyStuff(AccountInfo& accInfo, Product buy)	//use this when you choose a product
{
	ShowTitle();
	cout << "1. Buy now" << endl;
	cout << "2. " << endl;
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
	if (accInfo.getStatus() == 2 ) 	//admin
	{
		AdminNotif admin;
		admin.checkNotif(accInfo.getID(), "");
		if (accInfo.getID() == "Ad5") {
			Admin sellerRegistation;
			sellerRegistation.acceptSeller();
		}
	}
	else 	//user
	{
		if (accInfo.getStatus() == 1) //seller
		{
			UserNotif sellerNotif;

			if (sellerNotif.checkNotif("", accInfo.getID())) {
				cout << "Accept?(Y/N): ";
				bool ans;
				Seller notif;
				while (true)
				{
					char ch;
					cin >> ch;
					if (ch == 'y' || ch == 'Y')
					{
						ans = true;
						break;
					}
					else if (ch == 'n' || ch == 'N') {
						ans = false;
						break;
					}
					else
						cout << "Bad choice, try again\n";
				}
				notif.approveCart(ans, accInfo.getID());
			}
		}
		else //customer
		{
			UserNotif customerNotif;
			customerNotif.checkNotif(accInfo.getID(), "");
		}
	}
}

void Menu::ShowMenuHistory(AccountInfo& accInfo)//View shopping history, selling history, selling static \rate other seller? rate customer? rate product?
{
	while (true)
	{

		ShowTitle();
		cout << "1. View shopping history" << endl;
		if (accInfo.getStatus() == 0) {	//customer
			cout << "0. Return" << endl;
		}
		else {	//seller
			cout << "2. Selling statistic" << endl;
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
				UserNotif shoppingHistory;
				shoppingHistory.displayShoppingHistory(accInfo.getID());
				break;
			}
			case 2:
			{
				Seller viewSeller;
				viewSeller.saleStatistic(accInfo.getID());
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
				UserNotif shoppingHistory;
				shoppingHistory.displayShoppingHistory(accInfo.getID());
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
		system("pause");
	}
}

void Menu::Login(Account accountLogin, ListAccount listAcc, AccountInfo accInfo, string username, string password)
{
	int loginResult = 0;
	cin.ignore();
	do
	{
		ShowTitle();
		cout << "                      LOGIN                     " << endl << endl;
		cout << "\t Username >> ";
		getline(cin, username);
		if (username == "")
			break;
		cout << "\t Password >> ";
		password = accountLogin.inputPassword();

		loginResult = listAcc.login(username, password);	//admin = 2; user = 1;
//		Sleep(50);
		if (loginResult == 0)
		{
			cout << "Wrong username or password\nDo you want to try again?(Y/N) ";
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
		}
		else {

			accountLogin = listAcc.findAccount(username);
			if (loginResult == 2) {
				accInfo = *accInfo.findAdmin(username);
				ShowMenuAdmin(accInfo, accountLogin, listAcc);
			}
			else {
				accInfo = *accInfo.findUser(username);
				if (accInfo.getStatus() == 0) {
					ShowMenuCustomer(accInfo, accountLogin);
				}
				else
					ShowMenuSeller(accInfo, accountLogin);

			}
		}
	} while (loginResult == 0);
}

void Menu::SignUp(Account accountLogin, Account AccountSignUp, ListAccount listAcc, AccountInfo accInfo, string username, string password)
{
	ShowTitle();
	cout << "                     SIGN UP                    " << endl << endl;

	string retypePassword;
	cout << "\t Username >> ";
	cin.ignore();
	getline(cin, username);
	if (username == "")
		return;
	do {
		cout << "\t Password >> ";
		password = AccountSignUp.inputPassword();
		cout << "\t Retype password >> ";

		retypePassword = AccountSignUp.inputPassword();
		if (password != retypePassword) {
			cout << "Retype password and new password is not match\nPress any key to try again";
			_getch();
			ShowTitle();
			cout << "                     SIGN UP                    " << endl << endl;
			cout << "\t Username >> " << username << endl;
		}
	} while (password != retypePassword);

	AccountSignUp.createNewAccount(username, password);
	listAcc.SignUp(AccountSignUp);
	ShowTitle();
	cout << "                     SIGN UP                    " << endl << endl;
	cout << "--------------Input your infomation-------------" << endl;
	accInfo.registerAccount(AccountSignUp.getUsername(), AccountSignUp.getID());

	listAcc.login(username, password);
	accInfo = *accInfo.findUser(username);
	ShowMenuCustomer(accInfo, accountLogin);
}




