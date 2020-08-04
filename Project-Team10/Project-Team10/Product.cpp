#include "Product.h"
#include<vector>
#include<iostream>
#include<fstream>

using namespace std;
void Product::loadProductfile()
{
	ifstream fi;
	fi.open("Product/product.txt");
	if (!fi.is_open()) {
		cout << "Can't open product.txt!!" << endl;
		return;
	}
	int nPr;
	fi >> nPr;
	vector<Product>arr;
	Product tmp;
	tmp.loadProduct(fi, arr, nPr);
	fi.close();
	tmp.DisplayArrProduct(arr);
}

void Product::loadProduct(ifstream& f, vector<Product> &arr, int nPro)
{
	Product temp;
	for (int i = 0; i < nPro; i++) {
		f >> temp.ID;
		f >> temp.IDseller;
		f.ignore();
		getline(f,temp.productName);
		f >> temp.price;
		f >> temp.stock;
		f >> temp.type;
		arr.push_back(temp);
	}
}

void Product::saveProductfile()
{
	ofstream fo;
	Product tmp;
	fo.open("Product\product.txt");
	vector<Product>arr;
	fo << arr.size() << endl;
	tmp.saveProduct(fo, arr);
	fo.close();
}

void Product::saveProduct(ofstream& f, vector<Product> arr)
{
	for (int i = 0; i < arr.size(); i++) {
		f << arr[i].ID<<endl;
		f << arr[i].IDseller<<endl;
		f << arr[i].productName << endl;
		f << arr[i].price;
		f << arr[i].stock;
		f << arr[i].type;
	}
}

void Product::DisplayArrProduct(vector<Product> arr)
{
	cout << "Quantity: " << arr.size() << endl<<endl;
	for (int i = 0; i < arr.size(); i++) {
		arr[i].display();
		cout << endl;
	}

}

void Product::display()
{
	cout << "ID: " << ID << endl;
	cout << "Seller's ID: " << IDseller << endl;
	cout << "Product's name: " << productName << endl;
	cout << "Price: " << price << endl;
	cout << "Stock: " << stock << endl;
	cout << "Type: ";
	switch (type)
	{
	case 1:{
		cout << "Food" << endl;
		break;
	}
	case 2: {
		cout << "Fashion" << endl;
		break;
	}
	case 3: {
		cout << "Technological" << endl;
		break;
	}
	case 4: {
		cout << "Houseware" << endl;
		break;
	}
	case 5: {
		cout << "Other" << endl;
		break;
	}
	default:
		break;
	}

}
