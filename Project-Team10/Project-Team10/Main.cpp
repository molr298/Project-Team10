#include "Menu.h"
#include "AccountInfo.h"
#include "Admin.h"
#include "Notification.h"
#include "Product.h"
#include "Customer.h"
#include "Seller.h"

int main() {
	/*AccountInfo tmp;
	tmp.loadListUser();
	tmp.displayListUser();
	tmp.registerAccount();
	tmp.editInfo();*/

	Admin ad1;
	//ad1.sendReport("Ad1");
	ad1.acceptSeller("Ad4");
	/*Admin ad1;
	ad1.loadListAdmin();
	ad1.displayListAdmin();
	ad1.removeUser();*/

	/*AdminNotif ad;
	ad.loadListNotif();
	cout << "Ad1" << endl;
	ad.checkNotif("Ad1","");
	cout << "User with ID: 19127001" << endl;
	ad.checkNotif("", "19127001");*/


	/*Product a;
	a.loadListProduct();
	a.displayListProduct();
	a.removeProduct();
	a.editProduct();
	a.displayListProduct();*/
	//UserNotif usn;
	//Customer csm;
	//usn.loadListNotif();
	//////csm.addProduct();
	////csm.removeProduct(); //Add choice to confirm
	//usn.printList();
	//csm.buyStuff(usn, "19127009");
	//csm.buyStuff(usn, "19127009");
	//csm.confirmCart("19127009");


//	Seller sl;
//	sl.sendReport("19127002");
	//bool isApproveCart = true; //false
	//sl.approveCart(isApproveCart,"19127006");

//	sl.saleStatistic("19127002");
	/*UserNotif usn;
	usn.loadListNotif();
	usn.checkNotif("19127003", "");
	usn.checkNotif("", "19127002");
	usn.checkNotif("19127001", "");
	usn.checkNotif("", "19127004");*/

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

			menu.ShowTitle();
			cout << "                      LOGIN                     " << endl << endl;
			cout << "\t Username >> ";
			cin.ignore();
			getline(cin, username);
			if (username == "")
				return 0;
			cout << "\t Password >> ";
			password = accountLogin.inputPassword();
			int loginResult = listAcc.login(username, password);	//admin = 2; user = 1;
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
						return 0;
					else
						cout << "Bad choice, try again\n";
				}
			}
			else {

				accountLogin = listAcc.findAccount(username);
				if (loginResult == 2) {
					accInfo = *accInfo.findAdmin(username);
					menu.ShowMenuAdmin(accInfo, accountLogin, listAcc);
				}
				else {
					accInfo = *accInfo.findUser(username);
					if (accInfo.getStatus() == 0) {
						menu.ShowMenuCustomer(accInfo, accountLogin);
					}
					else
						menu.ShowMenuSeller(accInfo, accountLogin);

				}
			}

			break;
		}
		case 2:
		{
			menu.ShowTitle();
			cout << "                     SIGN UP                    " << endl << endl;

			string retypePassword;
			cout << "\t Username >> ";
			cin.ignore();
			getline(cin, username);
			do {
				cout << "\t Password >> ";
				password = AccountSignUp.inputPassword();
				cout << "\t Retype password >> ";

				retypePassword = AccountSignUp.inputPassword();
				if (password != retypePassword) {
					cout << "Retype password and new password is not match\nPress any key to try again";
					_getch();
					menu.ShowTitle();
					cout << "                     SIGN UP                    " << endl << endl;
					cout << "\t Username >> " << username << endl;
				}
			} while (password != retypePassword);

			AccountSignUp.createNewAccount(username, password);
			listAcc.SignUp(AccountSignUp);
			menu.ShowTitle();
			cout << "                     SIGN UP                    " << endl << endl;
			cout << "--------------Input your infomation-------------" << endl;
			accInfo.registerAccount(AccountSignUp.getUsername(), AccountSignUp.getID());

			listAcc.login(username, password);
			accInfo = *accInfo.findUser(username);
			menu.ShowMenuCustomer(accInfo, accountLogin);

			break;
		}
		default:
			break;
		}
	}
	return 0;

}
