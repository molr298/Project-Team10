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
void AdminNotif::saveListNotif()
{
	remove("Notification/Notif_Admin.csv");
	ofstream fout("Notification/Notif_Admin.csv");
	fout << "Sender ID;Taker ID;Problems;Status" << endl;
	for (int i = 0; i < adnv.size(); i++)
	{
		adnv[i].saveOneReport(fout);
	}
	fout.close();
}
void AdminNotif::replyAReport(string IDUser, string IDAdmin)
{
	string message = "";
	if (IDAdmin != "Ad5") {
		cout << "Message send to user: ";
		cin.ignore();
		getline(cin, message);
	}
	else {
		
	}
}
void AdminNotif::loadListNotif()
{
	adnv.clear();
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
	getline(fin, Problem, ';');
	getline(fin, status);
	return *this;
}
bool AdminNotif::checkNotif(string adminID, string userID)
{
	int count = 0;
	loadListNotif();
	bool flag = 0;
	for (int i = 0; i < adnv.size(); i++)
	{
		if (adminID == adnv[i].getTakerID() && adnv[i].getStatus() == "0")
		{
			cout << ++count << ". User " << adnv[i].getSenderID() << " sent this message to you: " << adnv[i].getProblem() << endl;
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
	return flag;
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
	cout << setw(15) << left << productID << "\t" << setw(20) << left << productName << "\t" << setw(10) << left << price << "\t" << setw(10) << left << quantity << "\t" << setw(10) << left << typeProduct << "\t" << setw(10) << totalPrice << endl;
}
void UserNotif::printList()
{
	cout << setw(15) << left << "Product ID" << "\t" << setw(20) << left << "Product's Name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Quantity" << "\t" << setw(10) << left << "Type" << "\t" << setw(10) << "Total" << endl;
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
void UserNotif::displayShoppingHistory(string userID)
{
	int count = 0;
	loadListNotif();
	history.clear();
	for (int i = 0; i < usnv.size(); i++) {
		if (userID == usnv[i].getCustomerID() && usnv[i].getStatus() != 0) {
			count++;
			cout << count << ". Your order: " << usnv[i].getProductName() << " - " << usnv[i].getProductID() << endl;
			history.push_back(usnv[i]);
		}
	}
}

int UserNotif::displayHistoryDetail(int choice, string& IDProduct, string& IDSeller)
{

	cout << "Product ID: " << history[choice - 1].productID << endl;
	cout << "Name : " << history[choice - 1].productName << endl;
	cout << "Type: ";	//1. Food; 2. Fashion; 3. Technological; 4. Houseware; 5. Other
	if (history[choice - 1].typeProduct == 1)	cout << "Food" << endl;
	else 	if (history[choice - 1].typeProduct == 2)	cout << "Fashion" << endl;
	else 	if (history[choice - 1].typeProduct == 3)	cout << "Technological" << endl;
	else	if (history[choice - 1].typeProduct == 4)	cout << "Housware" << endl;
	else cout << "Other" << endl;
	cout << "Seller ID: " << history[choice - 1].sellerID << endl;
	cout << "Unit price: " << history[choice - 1].price << endl;
	cout << "Quantity: " << history[choice - 1].quantity << endl;
	cout << "Total: " << history[choice - 1].totalPrice << endl;
	IDProduct = history[choice - 1].productID;
	IDSeller = history[choice - 1].sellerID;
	
	return history[choice - 1].getStatus();
}




void UserNotif::removeNotif(UserNotif notifRemove)
{
	loadListNotif();
	for (int i = 0; i < usnv.size(); i++) {
		if (usnv[i] == notifRemove)
			usnv.erase(usnv.begin() + i);
	}

}
bool UserNotif::operator==(UserNotif compareNotif)
{
	if (this->productID == compareNotif.productID &&
		this->customerID == compareNotif.customerID &&
		this->sellerID == compareNotif.sellerID &&
		this->productName == compareNotif.productName &&
		this->price == compareNotif.price &&
		this->quantity == compareNotif.quantity &&
		this->totalPrice == compareNotif.totalPrice &&
		this->typeProduct == compareNotif.typeProduct &&
		this->status == compareNotif.status) 
		return true;
	return false;
}

void UserNotif::miniDisplayNotif(string IDUser, int status)
{
	int count = 0;
	loadListNotif();
	if (status == 0)
		for (int i = 0; i < usnv.size(); i++) {
			if (IDUser == usnv[i].getCustomerID()){
				count++;
				if (usnv[i].getStatus() == 0) 
					cout << count << ". Your order #" << usnv[i].getProductID() << " - " << usnv[i].getProductName() << " is waiting to be qualified by the seller." << endl;
				else if(usnv[i].getStatus() == 1)
					cout << count << ". Your order #" << usnv[i].getProductID() << " - " << usnv[i].getProductName() << " has been transported to shipping service" << endl;
				else {
					cout << count << ". Your order #" << usnv[i].getProductID() << " - " << usnv[i].getProductName() << " was cancelled by seller" << endl;
				}
			}
		}
	else 
		for (int i = 0; i < usnv.size(); i++) 
			if (IDUser == usnv[i].getSellerID() && usnv[i].getStatus() == 0) {
				count++;
				cout << count << ". You have an order from #" << usnv[i].getCustomerID() << endl;
			}
	if (count == 0) {
		cout << "No notification available" << endl;
		return;
	}
}

bool UserNotif::checkNotif(string customerID1, string sellerID1)
{
	bool flag = 0;
	//cout << usnv.size() << endl;
	loadListNotif();
	int count = 0;
	cout << "________________________________________________________________________________________________________________" << endl;

	for (int i = 0; i < usnv.size(); i++)
	{
		if (customerID1 == usnv[i].getCustomerID() && usnv[i].getStatus() == 0)
		{
			cout << ++count << ". Your order on the " << usnv[i].getProductName() << " is waiting to be qualified by the seller." << endl;
			cout << "Review your order's information below" << endl;
			cout << "Product ID: " << usnv[i].getProductID() << endl;
			cout << "Product Name: " << usnv[i].getProductName() << endl;
			cout << "Quantity: " << usnv[i].getQuantity() << endl;
			cout << "Price: " << usnv[i].getPrice() << endl;
			cout << "Total: " << usnv[i].getTotalPrice() << endl;

			flag = 1;
			cout << "______________________________________________________________________________" << endl;

		}

		else if (customerID1 == usnv[i].getCustomerID() && usnv[i].getStatus() == 1)
		{ 
			cout << ++count << ". Your order has been transported to shipping service" << endl;
			cout << "Review your order's information below" << endl;
			cout << "Product ID: " << usnv[i].getProductID() << endl;
			cout << "Product Name: " << usnv[i].getProductName() << endl;
			cout << "Quantity: " << usnv[i].getQuantity() << endl;
			cout << "Price: " << usnv[i].getPrice() << endl;
			cout << "Total: " << usnv[i].getTotalPrice() << endl;
			flag = 1;
			cout << "______________________________________________________________________________" << endl;
		}
		else if (sellerID1 == usnv[i].getSellerID() && usnv[i].getStatus() == 2) {
			cout << ++count << ". #" << usnv[i].getCustomerID() << " - has received the order" << endl;
			cout << "Product ID: " << usnv[i].getProductID() << endl;
			cout << "Product Name: " << usnv[i].getProductName() << endl;
			cout << "Quantity: " << usnv[i].getQuantity() << endl;
			cout << "Price: " << usnv[i].getPrice() << endl;
			cout << "Total: " << usnv[i].getTotalPrice() << endl;
			flag = 1;
			cout << "______________________________________________________________________________" << endl;

		}
		if (sellerID1 == usnv[i].getSellerID() && usnv[i].getStatus() == 0)
		{
			cout << ++count << ". Customer with ID: " << usnv[i].getCustomerID() << " have ordered the following product:" << endl;
			cout << "Product Name: " << usnv[i].getProductName() << endl;
			cout << "Quantity: " << usnv[i].getQuantity() << endl;
			cout << "Price: " << usnv[i].getPrice() << endl;
			cout << "Total: " << usnv[i].getTotalPrice() << endl;
			flag = 1;
			cout << "______________________________________________________________________________" << endl;
		}
	}
	if (flag == 0)
		cout << "No notification available" << endl;
	return flag;
}
void UserNotif::confirmReceived(bool answer, int choice)
{
	if (answer) {
		loadListNotif();
		for (int i = 0; i < usnv.size(); i++) {
			if (usnv[i] == history[choice - 1]) {
				usnv[i].setStatus(2);
				history[choice - 1].setStatus(2);
			}
		}
		saveListOrder();
	}
	return;
}
void AdminNotif::saveOneReport(ofstream& fout)
{
	fout << senderID << ';';
	fout << takerID << ';';
	fout << Problem << ';';
	fout << status << endl;
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
	