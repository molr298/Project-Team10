#ifndef _MENU_H
#define _MENU_H


#include "Account.h"
#include "AccountInfo.h"
#include "Admin.h"
#include "Customer.h"
#include "Seller.h"
#include "Notification.h"
#include "Product.h"

class Menu {
public:
	void ShowTitle();

	void ShowMenu(AccountInfo&, Account&, ListAccount&, int);
	void ShowMenuAdmin(AccountInfo&, Account&, ListAccount&);
	void ShowMenuCustomer(AccountInfo&, Account&);
	void ShowMenuSeller(AccountInfo&, Account&);

	void ShowMenuEditInfo(AccountInfo&);
	void ShowMenuEdit(AccountInfo&, Account&);

	void ShowMenuUserFindUser(AccountInfo);

	void ShowMenuShopping(AccountInfo&);	//Thêm bất cứ biến gì vào parameters nếu cần
	void ShowMenuBuyStuff(AccountInfo&);
	void ShowMenuNotification(AccountInfo&);
	void ShowMenuHistory(AccountInfo&);


//	void Login();

};


#endif // !_MENU_H
