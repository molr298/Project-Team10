#include "Menu.h"
#include "AccountInfo.h"
#include "Admin.h"
int main() {
	AccountInfo tmp;
	tmp.loadListUser();
	tmp.displayListUser();
	/*tmp.registerAccount();
	tmp.editInfo();*/
	Admin ad;
	ad.loadListAdmin();
	ad.displayListAdmin();
	ad.removeUser();
}