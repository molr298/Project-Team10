#include "Customer.h"


void Customer::buyStuff(UserNotif usn, string customerID)
{
	filterProduct.clear();
	Product::loadListProduct();
	UserNotif::loadListNotif();
	string search;
	vector<Product> temp;
	int n1 = usnv.size();
	cin.ignore();
	cout << "Enter ID or name to search: ";
	getline(cin, search);
	int flag = 0;
	for (int i = 0; i < prdv.size(); i++)
	{
		if (prdv[i].getID() == search || prdv[i].getProductName() == search) /////////Hàm tìm keyword sẽ review sau https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
		{
			flag = 1;
			filterProduct.push_back(prdv[i]);
		}
	}
	if (flag == 0)
	{
		cout << "Items not found" << endl;
		return;
	}
	int choice;
	cout << setw(4) << left << "Number" << "\t" << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(10) << left << "Type" << endl;
	while (true)
	{
		for (int i = 0; i < filterProduct.size(); i++)
		{
			cout << endl;
			cout << i + 1 << "\t";
			filterProduct[i].display();
			cout << "_________________________________________________________________________________________________" << endl;
		}
		cout << "Make your choice: ";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		int n;
		cout << "You choose this product" << endl;
		system("cls");
		filterProduct[choice - 1].display();
		
		cout << "How many do you buy ?: ";
		cin >> n;
		temp = filterProduct;
		temp[choice - 1].setQuantity(n);
		ordv.push_back(temp[choice - 1]);
		system("cls");
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
}

void Customer::viewHistory()
{
	if (ordv.size() == 0)
	{
		cout << "No items are currently on the list" << endl;
		return;
	}
	cout << "Review your shopping list" << endl;
	for (int i = 0; i < ordv.size(); i++)
	{
		cout << "Product " << i + 1 << endl;
		ordv[i].display();
		cout << "____________________________________" << endl;
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
	adn.setStatus(0);
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
	adminReceiveRequest.setStatus(0);
	AdminNotif::adnv.push_back(adminReceiveRequest);
	AdminNotif::saveListNotif();
}

void Customer::HistoryShopping(string customerID)
{

}
