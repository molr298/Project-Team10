#include "Menu.h"
#include "AccountInfo.h"
#include "Admin.h"
#include "Notification.h"
#include "Product.h"
int main() {
	AccountInfo tmp;
	tmp.loadListUser();
	tmp.displayListUser();


	tmp.registerAccount();
	tmp.editInfo();


	Admin ad1;
	ad1.loadListAdmin();
	ad1.displayListAdmin();
	ad1.removeUser();

	AdminNotif ad;
	ad.loadListNotif();
	cout << "Ad1" << endl;
	ad.checkNotif("Ad1","");
	cout << "User with ID: 19127001" << endl;
	ad.checkNotif("", "19127001");
	tmp.editInfo();
	Product a;
	a.loadProductfile();

}