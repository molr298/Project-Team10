#ifndef _NOTIFICATION_H
#define _NOTIFICATION_H

#include <iostream>
#include<vector>
#include"Lib.h"
#include "AccountInfo.h"
#include "Account.h"
using namespace std;
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
	void setSenderID(string senderID) { this->senderID = senderID; }
	void setTakerID(string takerID) { this->takerID = takerID; }
};

class AdminNotif : public Notif
{
private: 
	string status;
	string Problem;

//protected:
//	vector<AdminNotif> adnv;
public:
	vector<AdminNotif> adnv;
	string getProblem() { return Problem; }
	string getStatus() { return status; }
	void loadListNotif();
	AdminNotif loadAnNotif(ifstream& fin);
	void checkNotif(string adminID, string userID);
	void saveOneReport(ofstream& fout);
	void setStatus(string status) { this->status = status; }
	void setProblem(string Problem) { this->Problem = Problem; }
	void saveListNotif();
};

class UserNotif
{
private:
	string productID;
	string customerID;
	string sellerID;
	string productName;
	double price;
	int quantity;
	double totalPrice;
	int typeProduct;
	int status;

	vector<UserNotif> history;
protected:
	vector<UserNotif> usnv;
public:
	void getProduct(string productID, string customerID, string sellerID, string productName, double price, int quantity, int typeProduct)
	{
		this->productID = productID;
		this->customerID = customerID;
		this->sellerID = sellerID;
		this->productName = productName;
		this->price = price;
		this->quantity = quantity;
		this->totalPrice = price * quantity;
		this->typeProduct = typeProduct;
		this->status = 0;
	}
	string getProductID() { return productID; }
	string getCustomerID() { return customerID; }
	string getSellerID(){ return sellerID; }
	string getProductName(){ return productName; }
	double getPrice(){ return price; }
	int getQuantity(){ return quantity; }
	double getTotalPrice(){ return totalPrice; }
	int getType(){ return typeProduct; }
	int getStatus() { return status; }
	void setQuantity(int n) { quantity += n; }
	void setTotal(int n) { totalPrice += n; }

	void loadListNotif();
	UserNotif loadOneNotif(ifstream& fin);
	bool checkNotif(string customerID, string sellerID); //string userID, status
	void print();
	void printList();
	void saveOneOrder(ofstream& fout);
	void saveListOrder();
	void saveListOrder(int n, string productID);
	void setStatus(int n) { status = n; }
	void loadListNotifWithoutClear();
	void setCustomerID(string ID) { customerID = ID; }

	void displayShoppingHistory(string userID);
	void displayHistoryDetail(int choice, string& IDProduct, string& IDSeller);
	void removeNotif(UserNotif);
	bool operator ==(UserNotif);

	void miniDisplayNotif(string, int);
};

#endif // !_NOTIFICATION_H