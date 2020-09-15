#include "Customer.h"

int ship = 0;

void Customer::buyStuff(UserNotif usn, string customerID, bool flag)
{
	vector<Product> temp;
	if (flag == 0)
	{
		cout << "Items not found" << endl;
		return;
	}
	int choice;
	while (true)
	{
		cout << setw(4) << left << "Number" << "\t" << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(20) << left << "Type\t" << setw(20) << left << "Rating " << endl;
		for (int i = 0; i < filterProduct.size(); i++)
		{
			cout << endl;
			cout << i + 1 << "\t";
			filterProduct[i].display();
			cout << "__________________________________________________________________________________________________________________________________" << endl;
		}
		cout << "Make your choice: ";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		int n;
		system("cls");
		if (filterProduct[choice - 1].getIDseller() == customerID) {
			cout << "You are selling this product" << endl;
			return;
		}
		cout << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(20) << left << "Type\t" << setw(20) << left << "Rating " << endl;
		filterProduct[choice - 1].display();
		cout << "Description: " << filterProduct[choice - 1].getDescr() << endl;
		Comment commentOfProduct(filterProduct[choice - 1].getID(), filterProduct[choice - 1].getIDseller());
		commentOfProduct.displayComment(filterProduct[choice - 1].getID(), filterProduct[choice - 1].getIDseller());
		cout << "___________________________________________________________________" << endl;

		cout << "How many do you buy ?: ";
		cin >> n;
		cout << endl << "Are you sure you want to purchase ? " << endl << "YES(yes) (Y,y)" << endl << "NO(no) (N,n)" << endl;
		char ans;
		cin >> ans;
		switch (ans)
		{
		case 'YES': case 'Y': case 'yes': case 'y':
		{
			temp = filterProduct;
			temp[choice - 1].setQuantity(n);
			ordv.push_back(temp[choice - 1]);
			Customer::viewCart(ship);
			cout << "Your cart has been updated" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 'NO': case 'N': case 'no': case 'n':
		{
			cout << "Returning..." << endl;
			break;
		}
		}
	}
}
void Customer::confirmCart(string customerID)
{
	int n = usnv.size();
	UserNotif::loadListNotif();
	cout << endl << "Are you sure you want to purchase ? " << endl << "YES(yes) (Y,y)" << endl << "NO(no) (N,n)" << endl;
	char ans;
	cin >> ans;
	switch (ans)
	{
	case 'YES': case 'Y': case 'yes': case 'y':
	{
		for (int i = 0; i < ordv.size(); i++)
		{
			Product::setupCart(ordv[i].getStock(), ordv[i]);
		}
		remove("Notification/Notif_User.csv");
		ofstream fout("Notification/Notif_User.csv");
		fout << "Product ID;Customer ID;Seller ID;Type;Name;Quantity;Price;Total;Status" << endl;
		for (int i = 0; i < usnv.size(); i++)
		{
			if (n == i)
			{
				usnv[i].setCustomerID(customerID);
				n++;
			}
			usnv[i].saveOneOrder(fout);
		}
		fout.close();

		cout << "Your cart has been confirmed" << endl;
		break;
	}
	case 'NO': case 'N': case 'no': case 'n':
	{
		cout << "Your cart has been renewed" << endl;
		break;
	}
	}
	ordv.clear();
}

void Customer::viewCart(int ship1)
{
	if (ordv.size() == 0)
	{
		cout << "No items are currently on the list" << endl;
		return;
	}
	double total = 0;
	cout << "Review your shopping list" << endl;
	cout << setw(4) << left << "Number" << "\t" << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(20) << left << "Type\t" << setw(20) << left << "Rating " << endl;
	for (int i = 0; i < ordv.size(); i++)
	{
		total += ordv[i].getPrice() * ordv[i].getStock();
		cout << i + 1 << "       ";
		ordv[i].display();
		cout << "__________________________________________________________________________________________________________________________________" << endl;
	}
	if (ship == 0)
	{
		cout << "Ship Fee: 15000 VND" << endl;
		cout << "Total: " << total + 15000 << " VND" << endl;
	}
	else
	{
		cout << "Free Ship" << endl;
		cout << "Total: " << total << " VND" << endl;
	}
}

void Customer::sendReport(string senderID1)
{
	string takerID1;
	string problem;
	AdminNotif::loadListNotif();
	int type;
	string command[] = {
		"1. For App Bug",
		"2. For User Report",
		"3. For Items",
		"4. For others"
	};
	for (int i = 0; i < 4; i++)
		cout << command[i] << endl;
	cout << "Choose Problem Type: " << endl;
	cin >> type;
	if (type == 1)
	{
		takerID1 = "Ad1";
	}
	if (type == 2)
	{
		takerID1 = "Ad2";
	}
	if (type == 3)
	{
		takerID1 = "Ad3";
	}
	if (type == 4)
	{
		takerID1 = "Ad4";
	}
	cin.ignore();
	cout << "Describe Problem: ";
	getline(cin, problem);
	AdminNotif adn;
	adn.setSenderID(senderID1);
	adn.setTakerID(takerID1);
	adn.setProblem(problem);
	adn.setStatus("0");
	AdminNotif::adnv.push_back(adn);
	AdminNotif::saveListNotif();
}

void Customer::requestToBeSeller(string senderID)
{
	AdminNotif::loadListNotif();
	string request = "User " + senderID + " want to become a seller";
	AdminNotif adminReceiveRequest;
	adminReceiveRequest.setSenderID(senderID);
	adminReceiveRequest.setTakerID("Ad5");
	adminReceiveRequest.setProblem(request);
	adminReceiveRequest.setStatus("0");
	AdminNotif::adnv.push_back(adminReceiveRequest);
	AdminNotif::saveListNotif();
}


void Customer::setOrder(string customerID)
{
	int choice;

	while (true)
	{
		system("cls");
		Customer::viewCart(ship);
		cout << "1. Remove order" << endl;
		cout << "2. Change order's quantity" << endl;
		cout << "3. Apply voucher" << endl;
		cout << "0. Return" << endl;
		cout << "Option: ";
		int option;
		cin >> option;
		int num;
		if (option == 0)
		{
			return;
		}
		if (option == 1)
		{
			cout << "Choose one order to remove: ";
			cin >> num;
			ordv.erase(ordv.begin() + num - 1);
			cout << "This order has been remove" << endl;

		}
		if (option == 2)
		{
			int quantity;
			cout << "Choose one order to continue: ";
			cin >> num;
			cout << "Quantity: ";
			cin >> quantity;
			ordv[num - 1].setQuantity(quantity);
		}
		if (option == 3)
		{
			Customer::setVoucher();
			system("pause");
		}
	}
}
Customer Customer::readOneVoucher(ifstream& fin)
{
	getline(fin, code, ';');
	fin >> percent;
	fin.seekg(1, 1);
	getline(fin, type, ';');
	getline(fin, description, '\n');
	return *this;
}
int countLines1(ifstream& filein)
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
void Customer::loadListVoucher()
{
	vouv.clear();
	ifstream fin("Voucher/Sale_Code.csv");
	if (!fin.is_open()) {
		cout << "Can't open Notif_User!!" << endl;
		return;
	}
	int n = countLines1(fin);
	fin.close();
	fin.open("Voucher/Sale_Code.csv");
	string line;
	getline(fin, line);
	for (int i = 0; i < n; i++)
	{
		vouv.push_back(Customer::readOneVoucher(fin));
		//getline(fin, line);
	}
	fin.close();
}
void Customer::print()
{
	for (int i = 0; i < vouv.size(); i++)
	{
		cout << vouv[i].getCode() << endl;
		cout << vouv[i].getPer() << endl;
		cout << vouv[i].getType() << endl;
		cout << vouv[i].getDescrip() << endl;
	}
}
void Customer::setVoucher()
{
	Customer::loadListVoucher();
	//Customer::print();
	string voucher;
	cin.ignore();
	cout << "Enter your voucher here: ";
	getline(cin, voucher);
	if (voucher == "SHIPFREE")
	{
		cout << "You have applied free ship code" << endl;
		ship = 1;
		return;
	}
	for (int i = 0; i < vouv.size(); i++)
	{
		if (vouv[i].getCode() == voucher)
		{
			if (vouv[i].getType() == "ALL")
			{
				for (int j = 0; j < ordv.size(); j++)
				{
					ordv[j].setPrice(ordv[j].getPrice() - (ordv[j].getPrice() * vouv[i].getPer() / 100));
					cout << ordv[j].getPrice() << endl;
				}
				cout << endl << vouv[i].getDescrip() << endl;
				_getch();
				return;
			}
			else if (vouv[i].getType() == "1")
			{
				for (int j = 0; j < ordv.size(); j++)
				{
					if (ordv[j].getType() == 1)
					{
						ordv[j].setPrice(ordv[j].getPrice() * ((100 - vouv[i].getPer()) / 100));
					}
				}
				cout << endl << vouv[i].getDescrip() << endl;
				_getch();
				return;
			}
			else if (vouv[i].getType() == "2")
			{
				for (int j = 0; j < ordv.size(); j++)
				{
					if (ordv[j].getType() == 2)
					{
						ordv[j].setPrice(ordv[j].getPrice() * ((100 - vouv[i].getPer()) / 100));
					}
				}
				cout << endl << vouv[i].getDescrip() << endl;
				_getch();
				return;
			}
			else if (vouv[i].getType() == "3")
			{
				for (int j = 0; j < ordv.size(); j++)
				{
					if (ordv[j].getType() == 3)
					{
						ordv[j].setPrice(ordv[j].getPrice() * ((100 - vouv[i].getPer()) / 100));
					}
				}
				cout << endl << vouv[i].getDescrip() << endl;
				_getch();
				return;
			}
			else if (vouv[i].getType() == "4")
			{
				for (int j = 0; j < ordv.size(); j++)
				{
					if (ordv[j].getType() == 4)
					{
						ordv[j].setPrice(ordv[j].getPrice() * ((100 - vouv[i].getPer()) / 100));
					}
				}
				cout << endl << vouv[i].getDescrip() << endl;
				_getch();
				return;
			}
			else if (vouv[i].getType() == "5")
			{
				for (int j = 0; j < ordv.size(); j++)
				{
					if (ordv[j].getType() == 5)
					{
						ordv[j].setPrice(ordv[j].getPrice() * ((100 - vouv[i].getPer()) / 100));
					}
				}
				cout << endl << vouv[i].getDescrip() << endl;
				_getch();
				return;
			}
		}
	}
}