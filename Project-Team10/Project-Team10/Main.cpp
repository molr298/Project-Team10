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
		int choice = 0;
		cout << "________________________________________________" << endl;
		cout << "Enter your choice: ";	cin >> choice;
		switch (choice)
		{
		case 1:
		{
			menu.Login(accountLogin, listAcc, accInfo, username, password);
			break;
		}
		case 2:
		{
			menu.SignUp(accountLogin, AccountSignUp, listAcc, accInfo, username, password);
			break;
		}
		default:
			break;
		}
	}

	return 0;

}
