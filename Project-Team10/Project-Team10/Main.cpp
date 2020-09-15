#include "Menu.h"
#include "AccountInfo.h"
#include "Admin.h"
#include "Notification.h"
#include "Product.h"
#include "Customer.h"
#include "Seller.h"
int main() {

	srand(time(NULL));

	Account accountLogin;
	Account AccountSignUp;
	ListAccount listAcc;
	AccountInfo accInfo;
	string username;
	string password;
	Menu menu;
	while (true)
	{
		menu.ShowTitle();
		cout << endl << "\t\t 1. LOGIN" << endl;
		cout << "\t\t 2. SIGN UP" << endl;
		cout << "\t\t 0. END PROGRAM" << endl;
		string choice;
		cout << "________________________________________________" << endl;
		cout << "Enter your choice: ";	cin >> choice;
		if (choice == "1")
			menu.Login(accountLogin, listAcc, accInfo, username, password);
		else if (choice == "2")
			menu.SignUp(accountLogin, AccountSignUp, listAcc, accInfo, username, password);
		else if(choice == "0")
			return -1;
	}

	return 0;

}
