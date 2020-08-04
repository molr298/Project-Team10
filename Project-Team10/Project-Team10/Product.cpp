#include "Product.h"
//
//int ID;
//string productName;
//double price;
//int stock;
//int type;

void Product::loadProduct(ifstream& fin, vector<Product>& arr, int& nPro)
{
	string str;
	Product tmp;
	fin >> str;
	nPro = atoi(str.c_str());
	for (int i = 0; i < nPro; i++)
	{
		fin >> tmp;
		arr.push_back(tmp);
	}
}

istream& operator>>(istream& in, Product& obj)
{
	cout << "ID "; in >> obj.ID;
	cout << "ProductName: "; in.ignore(1); getline(in, obj.productName);
	cout << "Price: "; in >> obj.price;
	cout << "Stock: "; in >> obj.stock;
	cout << "Type: "; in >> obj.type;
	return in;
}
ifstream& operator>> (ifstream& fin, Product& obj)
{
	string tmp;
	fin >> tmp;
	obj.ID = atoi(tmp.c_str());
	fin >> tmp;
	obj.productName = tmp;
	fin >> tmp;
	obj.price = atoi(tmp.c_str());
	fin >> tmp;
	obj.stock = atoi(tmp.c_str());
	fin >> tmp;
	obj.type = atoi(tmp.c_str());
	return fin;
}

