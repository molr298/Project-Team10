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
	cout << "Here is your Sale Statistic" << endl;
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
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = i + 1; j < temp.size(); j++)
		{
			if (temp[i].getProductID() == temp[j].getProductID() && temp[i].getProductName() == temp[j].getProductName())
			{
				temp[i].setQuantity(temp[j].getQuantity());
				temp[i].setTotal(temp[j].getTotalPrice());
				temp.erase(temp.begin() + j);
			}
		}
	}
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
			bestStock = i;
			
		}
		if (leastStock >= temp[i].getQuantity())
		{
			leastStock = i;
		}
	}
	cout << temp[0].getTotalPrice() << endl;
	cout << setw(4) << left << "Product ID" << "\t" << setw(20) << left << "Product's Name" << "\t" << setw(10) << "Total" << endl;
	for (int i = 0; i < temp.size(); i++)
	{
		cout << setw(15) << left << temp[i].getProductID() << "\t" << setw(20) << left << temp[i].getProductName() << "\t" << setw(10) << temp[i].getTotalPrice() << endl;
	}
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
			temp[i].print();
		}
		cout << "Peak: " << peak << endl;
		cout << "Lowest: " << lowestTotal << endl;
		cout << "Total: " << total << endl;
		cout << "Most Buying Product Quantity: " << endl;
		//temp[mostQuantity].print();
		cout << "Least Buying Product Quantity: " << endl;
		//temp[leastQuantity].print();
		break;
	}
	case 'NO': case 'N':case 'n': case 'no':
	{

		break;
	}

	}
}