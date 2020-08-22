#include "Seller.h"
void Seller::approveCart(bool approveOrder, string IDseller)
{
	if (approveOrder)
	{
		Product prd;
		prd.saveNotifUser(IDseller);
	}
	else return;
}
void Seller::saleStatistic(string IDseller)
{
	UserNotif::loadListNotif();
	vector<UserNotif> temp;
	int p = 0;
	double total = 0;
	for (int i = 0; i < usnv.size(); i++)
	{
		if (usnv[i].getSellerID() == IDseller && usnv[i].getStatus() == 1)
		{
			total += usnv[i].getTotalPrice();
			temp.push_back(usnv[i]);
		}
	}

	int flag = 0;
	
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = i + 1; j < temp.size(); j++)
		{
			if (temp[i].getProductID() == temp[j].getProductID() && temp[i].getProductName() == temp[j].getProductName())
			{
				flag = 1;
				temp[i].setQuantity(temp[j].getQuantity());
				temp[i].setTotal(temp[j].getTotalPrice());
				temp.erase(temp.begin() + j);
			}
		}
	}
	if (flag == 0) {
		cout << "No sale statistic..." << endl;
		return;
	}
	cout << "Here is your Sale Statistic" << endl;
	double lowestTotal = temp[0].getTotalPrice();
	double peak = temp[0].getTotalPrice();
	int bestStock = temp[0].getQuantity();
	int leastStock = temp[0].getQuantity();
	vector<UserNotif> mostQuantity;
	vector<UserNotif> leastQuantity;
	for (int i = 0; i < temp.size(); i++)
	{
		if (peak <= temp[i].getTotalPrice())
		{
			peak = temp[i].getTotalPrice();
		}
		if (lowestTotal > temp[i].getTotalPrice())
		{
			lowestTotal = temp[i].getTotalPrice();
		}
		if (bestStock <= temp[i].getQuantity())
		{
			bestStock = temp[i].getQuantity();
		}
		if (leastStock >= temp[i].getQuantity())
		{
			leastStock = temp[i].getQuantity();
		}

	}
	cout << temp[0].getTotalPrice() << endl;
	cout << setw(4) << left << "Product ID" << "\t" << setw(20) << left << "Product's Name" << "\t" << setw(10) << "Total" << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << setw(15) << left << temp[i].getProductID() << "\t" << setw(20) << left << temp[i].getProductName() << "\t" << setw(10) << temp[i].getTotalPrice() << endl;
		cout << "______________________________________________________" << endl;
	}
	cout << "Peak: " << peak << endl;
	cout << "Lowest: " << lowestTotal << endl;
	cout << "Total: " << total << endl << endl;
	char ans;
	cout << endl << "View more information ? " << endl << "YES(yes) (Y,y)" << endl << "NO(no) (N,n) to return" << endl;
	cin >> ans;
	switch (ans)
	{
	case 'YES': case 'Y': case 'yes': case 'y':
	{
		cout << setw(4) << left << "Product ID" << "\t" << setw(20) << left << "Product's Name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Quantity" << "\t" << setw(10) << left << "Type" << "\t" << setw(10) << "Total" << endl;
		for (int i = 0; i < temp.size(); i++)
		{
			cout << endl;
			temp[i].print();
			cout << "_____________________________________________________________________________________________" << endl;
		}

		cout << "Total: " << total << endl << endl;
		cout << "Most Buying Product Quantity: " << endl;
		cout << setw(4) << left << "Product ID" << "\t" << setw(20) << left << "Product's Name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Quantity" << "\t" << setw(10) << left << "Type" << "\t" << setw(10) << "Total" << endl;
		for (int i = 0; i < temp.size(); i++)
		{
			if (bestStock == temp[i].getQuantity())
			{
				cout << endl;
				temp[i].print();
				cout << "_____________________________________________________________________________________________" << endl;
			}
		}
		cout << endl;
		cout << "Least Buying Product Quantity: " << endl;
		cout << setw(4) << left << "Product ID" << "\t" << setw(20) << left << "Product's Name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Quantity" << "\t" << setw(10) << left << "Type" << "\t" << setw(10) << "Total" << endl;
		for (int i = 0; i < temp.size(); i++)
		{
			if (leastStock == temp[i].getQuantity())
			{
				cout << endl;
				temp[i].print();
				cout << "_____________________________________________________________________________________________" << endl;
			}
		}
		
		cout << "\nBest sale: " << endl;
		cout << setw(4) << left << "Product ID" << "\t" << setw(20) << left << "Product's Name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Quantity" << "\t" << setw(10) << left << "Type" << "\t" << setw(10) << "Total" << endl;
		for (int i = 0; i < temp.size(); i++)
		{
			if (peak == temp[i].getTotalPrice())
			{
				cout << endl;
				temp[i].print();
				cout << "_____________________________________________________________________________________________" << endl;
			}
		}

		cout << "\nLeast sale: " << endl;
		cout << setw(4) << left << "Product ID" << "\t" << setw(20) << left << "Product's Name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Quantity" << "\t" << setw(10) << left << "Type" << "\t" << setw(10) << "Total" << endl;
		for (int i = 0; i < temp.size(); i++)
		{
			if (lowestTotal == temp[i].getTotalPrice())
			{
				cout << endl;
				temp[i].print();
				cout << "_____________________________________________________________________________________________" << endl;
			}
		}

		break;
	}
	case 'NO': case 'N':case 'n': case 'no':
	{

		break;
	}

	}
}
void Seller ::sendReport(string senderID1)
{
	string takerID1;
	string problem;
	AdminNotif::loadListNotif();
	int type;
	cout << "Choose Problem Type, 1 for App Bug, 2 for User Report, 3 for Items" << endl;
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

//void removeProduct();
//void changePrice();