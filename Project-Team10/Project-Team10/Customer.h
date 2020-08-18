#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include"Lib.h"
#include "AccountInfo.h"
#include "Product.h"
#include "Notification.h"
class Customer: public AccountInfo, public Product, public AdminNotif
{
private:
	vector<Product> Cart;
public:

	void buyStuff(UserNotif usn, string ID);
	void viewHistory();
	void confirmCart(string customerID);
	void sendReport(string senderID1);
};

#endif // !_CUSTOMER_H

