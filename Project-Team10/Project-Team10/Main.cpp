#include "Menu.h"
#include "AccountInfo.h"
#include "Admin.h"
#include "Notification.h"
int main() {
	/*AccountInfo tmp;
	tmp.loadListUser();
	tmp.displayListUser();*/


	/*tmp.registerAccount();
	tmp.editInfo();*/


	/*Admin ad;
	ad.loadListAdmin();
	ad.displayListAdmin();
	ad.removeUser();*/

	AdminNotif ad;
	ad.loadListNotif();
	cout << "Ad1" << endl;
	ad.checkNotif("Ad1","");
	cout << "User with ID: 19127001" << endl;
	ad.checkNotif("", "19127001");
}