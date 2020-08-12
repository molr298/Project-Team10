#include "Menu.h"
#include "AccountInfo.h"
#include "Admin.h"
#include "Notification.h"
#include "Product.h"
#include "Customer.h"
int main() {
	/*AccountInfo tmp;
	tmp.loadListUser();
	tmp.displayListUser();
	tmp.registerAccount();
	tmp.editInfo();*/


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
	
	Customer csm;
	////csm.addProduct();
	//csm.removeProduct(); //Add choice to confirm
	csm.buyStuff("19127009");
	Product prd;
	prd.saveNotifUser("19127002"); // ID seller to identify specific product

	/*UserNotif usn;
	usn.loadListNotif();
	usn.checkNotif("19127003", "");
	usn.checkNotif("", "19127002");
	usn.checkNotif("19127001", "");
	usn.checkNotif("", "19127004");*/

	

	return 0;
}
