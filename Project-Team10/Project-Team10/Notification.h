#pragma once
#include "Admin.h"

class Notif
{
private:
	int notifType;
protected:
	string senderID;
	string takerID;
public:
	string getSenderID() { return senderID; }
	string getTakerID() { return takerID; }
};
class AdminNotif : public Notif
{
private: 
	int issueType;
	string Problem;

protected:
	vector<AdminNotif> adnv;
public:
	string getProblem() { return Problem; }
	void loadListNotif();
	AdminNotif loadAnNotif(ifstream& fin);
	void checkNotif(string adminID, string userID);
};
class UserNotif
{
private:
	string customerID;
	string sellerID;
	string productName;
	double price;
	int quantity;
	double totalPrice;
	int typeProduct;
	int status;
protected:
	vector<UserNotif> usnv;
public:
	void getProduct(string customerID, string sellerID, string productName, double price, int quantity, int typeProduct)
	{
		this->customerID = customerID;
		this->sellerID = sellerID;
		this->productName = productName;
		this->price = price;
		this->quantity = quantity;
		this->totalPrice = price * quantity;
		this->typeProduct = typeProduct;
		this->status = 0;
	}
	string getCustomerID() { return customerID; }
	string getSellerID(){ return sellerID; }
	string getProductName(){ return productName; }
	double getPrice(){ return price; }
	int getQuantity(){ return quantity; }
	double getTotalPrice(){ return totalPrice; }
	int getType(){ return typeProduct; }
	int getStatus() { return status; }
	void loadListNotif();
	UserNotif loadOneNotif(ifstream& fin);
	void checkNotif(string customerID, string sellerID);
	void print();
	void printList();
	void saveOneOrder(ofstream& fout);
	void saveListOrder();
};
