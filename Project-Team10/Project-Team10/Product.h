#pragma once
#ifndef _Product_H
#define _Product_H

#include "Lib.h"
#include<vector>

class Product
{
private:
	int ID;
	int IDseller;
	string productName;
	double price;
	int stock;
	int type; //1. Food; 2. Fashion; 3. Technological; 4. Houseware; 5. Other
public:
	friend istream& operator>>(istream&, Product&);
	friend ifstream& operator>> (ifstream&, Product&);
	void loadProductfile();//doc file product.txt
	void loadProduct(ifstream& f, vector<Product> &arr, int nPro);//doc vao mang
	void saveProductfile();//luu file vaof product.txt
	void saveProduct(ofstream& f, vector<Product> arr);//luu mang vao file
	void display();
	void DisplayArrProduct(vector<Product> arr);
	void addProduct(vector<Product>& arr);
	void removeProduct(vector<Product>& arr, int id);
};

#endif // !_PRODUCT_H