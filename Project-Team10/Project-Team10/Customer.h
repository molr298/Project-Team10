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
	string code;
	int percent;
	string type;
	string description;
	vector<Customer> vouv;
public:
	Customer()
	{
		code = "";
		percent = 0;
		type = "";
		description = "";
	}
	string getCode() { return code; }
	int getPer() { return percent; }
	string getType() { return type; }
	string getDescrip() { return description; }
	void buyStuff(UserNotif usn, string ID, bool flag);
	void viewHistory();
	void confirmCart(string customerID);
	void sendReport(string senderID1);
	void setOrder(string customerID);
	void setVoucher();
	Customer readOneVoucher(ifstream& fin);
	void loadListVoucher();
	void print();
	void requestToBeSeller(string senderID);

	void HistoryShopping(string customerID);
};

#endif // !_CUSTOMER_H
