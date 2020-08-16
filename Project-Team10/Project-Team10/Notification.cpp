#include "Notification.h"
int countLines(ifstream& filein)
{
	string line;
	int n = 0;
	while (filein.good())
	{
		getline(filein, line);
		n++;
	}
	return n - 2;
}
void AdminNotif::loadListNotif()
{
	ifstream fin;
	fin.open("Notification/Notif_Admin.csv");
	if (!fin.is_open()) {
		cout << "Can't open Notif_Admin!!" << endl;
		return;
	}
	int n = countLines(fin);
	fin.close();
	fin.open("Notification/Notif_Admin.csv");
	string line;
	getline(fin, line);
	for (int i = 0; i < n; i++)
	{
		adnv.push_back(AdminNotif::loadAnNotif(fin));
	}
	fin.close();
}
AdminNotif AdminNotif::loadAnNotif(ifstream& fin)
{
	getline(fin, senderID,';');
	getline(fin, takerID, ';');
	getline(fin, Problem);
	return *this;
}
void AdminNotif::checkNotif(string adminID, string userID)
{
	int flag = 0;
	for (int i = 0; i < adnv.size(); i++)
	{
		if (adminID == adnv[i].getTakerID())
		{
			cout << "User " << adnv[i].getSenderID() << " sent this message to you: " << adnv[i].getProblem() << endl;
			flag = 1;
		}
		if (userID == adnv[i].getTakerID())
		{
			cout << "You have a notification from Admin\n" << adnv[i].getProblem() << endl;
			flag = 1;
		}
	}
	if(flag==0)
		cout << "No notification available" << endl;
}
UserNotif UserNotif::loadOneNotif(ifstream& fin)
{
	getline(fin, productID, ';');
	getline(fin, customerID, ';');
	getline(fin, sellerID, ';');
	fin >> typeProduct;
	fin.seekg(1, 1);
	getline(fin, productName, ';');
	fin >> quantity;
	fin.seekg(1, 1);
	fin >> price;
	fin.seekg(1, 1);
	fin >> totalPrice;
	fin.seekg(1, 1);
	fin >> status;
	return *this;
}
void UserNotif::print()
{
	cout << "Product ID: " << productID << endl;
	cout << "Product Name: " << productName << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Price: " << price << endl;
	cout << "Total: " << totalPrice << endl;
}
void UserNotif::printList()
{
	for (int i = 0; i < usnv.size(); i++) {
		usnv[i].print();
	}
	cout << "________________________________" << endl;
}
void UserNotif::loadListNotif()
{
	usnv.clear();
	ifstream fin;
	fin.open("Notification/Notif_User.csv");
	if (!fin.is_open()) {
		cout << "Can't open Notif_User!!" << endl;
		return;
	}
	int n = countLines(fin);
	fin.close();
	fin.open("Notification/Notif_User.csv");
	string line;
	getline(fin, line);
	for (int i = 0; i < n; i++)
	{
		usnv.push_back(UserNotif::loadOneNotif(fin));
		getline(fin, line);
	}
	fin.close();
}
void UserNotif::loadListNotifWithoutClear()
{
	ifstream fin;
	fin.open("Notification/Notif_User.csv");
	if (!fin.is_open()) {
		cout << "Can't open Notif_User!!" << endl;
		return;
	}
	int n = countLines(fin);
	fin.close();
	fin.open("Notification/Notif_User.csv");
	string line;
	getline(fin, line);
	for (int i = 0; i < n; i++)
	{
		usnv.push_back(UserNotif::loadOneNotif(fin));
		getline(fin, line);
	}
	fin.close();
}
void UserNotif::checkNotif(string customerID1, string sellerID1)
{
	int flag = 0;
	//cout << usnv.size() << endl;
	for (int i = 0; i < usnv.size(); i++)
	{
		if (customerID1 == usnv[i].getCustomerID() && usnv[i].getStatus() == 0)
		{
			cout << "Your order on the " << usnv[i].getProductName() << " is waiting to be qualified by the seller." << endl;
			cout << "Review your order's information below" << endl;
			cout << "Product ID: " << usnv[i].getProductID() << endl;
			cout << "Product Name: " << usnv[i].getProductName() << endl;
			cout << "Quantity: " << usnv[i].getQuantity() << endl;
			cout << "Price: " << usnv[i].getPrice() << endl;
			cout << "Total: " << usnv[i].getTotalPrice() << endl;
			flag = 1;
		}
		else if (customerID1 == usnv[i].getCustomerID() && usnv[i].getStatus() == 1)
		{ 
			cout << "Your order has been transported to shipping service" << endl;
			cout << "Review your order's information below" << endl;
			cout << "Product ID: " << usnv[i].getProductID() << endl;
			cout << "Product Name: " << usnv[i].getProductName() << endl;
			cout << "Quantity: " << usnv[i].getQuantity() << endl;
			cout << "Price: " << usnv[i].getPrice() << endl;
			cout << "Total: " << usnv[i].getTotalPrice() << endl;
			flag = 1;
		}
		if (sellerID1 == usnv[i].getSellerID() && usnv[i].getStatus() == 0)
		{
			cout << "Customer with ID: " << usnv[i].getCustomerID() << " have ordered the following product:" << endl;
			cout << "Product Name: " << usnv[i].getProductName() << endl;
			cout << "Quantity: " << usnv[i].getQuantity() << endl;
			cout << "Price: " << usnv[i].getPrice() << endl;
			cout << "Total: " << usnv[i].getTotalPrice() << endl;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "No notification available" << endl;
}
void UserNotif::saveOneOrder(ofstream& fout)
{
	fout << productID << ';';
	fout << customerID << ';';
	fout << sellerID << ';';
	fout << typeProduct << ';';
	fout << productName << ';';
	fout << quantity << ';';
	fout << price << ';';
	fout << totalPrice << ';';
	fout << status << endl;

}
void UserNotif::saveListOrder()
{
	remove("Notification/Notif_User.csv");
	ofstream fout("Notification/Notif_User.csv");
	fout << "Product ID;Customer ID;Seller ID;Type;Name;Quantity;Price;Total;Status" << endl;
	for (int i = 0; i < usnv.size(); i++)
	{
		usnv[i].saveOneOrder(fout);
	}
	fout.close();
}
void UserNotif::saveListOrder(int n, string customerID)
{
	remove("Notification/Notif_User.csv");
	ofstream fout("Notification/Notif_User.csv");
	fout << "Product ID;Customer ID;Seller ID;Type;Name;Quantity;Price;Total;Status" << endl;
	for (int i = 0; i < usnv.size(); i++)
	{
		if (n == i)
		{
			usnv[i].customerID = customerID;
			n++;
		}
		usnv[i].saveOneOrder(fout);
	}
	fout.close();
}