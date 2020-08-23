#include "Menu.h"
#include "AccountInfo.h"
#include "Admin.h"
#include "Notification.h"
#include "Product.h"
#include "Customer.h"
#include "Seller.h"

int main() {


	//Admin ad1;
	//ad1.sendReport("Ad1");
	//ad1.acceptSeller("Ad4");
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
	UserNotif usn;
	Customer csm;

	//usn.loadListNotif();
	////////csm.addProduct();
	//////csm.removeProduct(); //Add choice to confirm
	//usn.printList();
	//csm.buyStuff(usn, "19127009");
	////csm.buyStuff(usn, "19127009");
	//csm.setOrder("19127009");
	//csm.confirmCart("19127009");


	Seller sl;
	//sl.sendReport("19127002");
	bool isApproveCart = true; //false
	sl.approveCart(isApproveCart,"19127002");

//	sl.saleStatistic("19127002");

	//Seller sl;
	//sl.sendReport("19127002");
	//bool isApproveCart = true; //false
	//sl.approveCart(isApproveCart,"19127006");

	//sl.saleStatistic("19127002");

	/*UserNotif usn;
	usn.loadListNotif();
	usn.checkNotif("19127003", "");
	usn.checkNotif("", "19127002");
	usn.checkNotif("19127001", "");
	usn.checkNotif("", "19127004");*/

	Seller L;
	Product obj;
	obj.inputProduct();
	L.addProduct(obj);

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
