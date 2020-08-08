#pragma once
#ifndef _Product_H
#define _Product_H

#include "Lib.h"

#include<vector>

class Product
{
private:
	string ID;
	string IDseller; // ?
	string productName;
	double price;
	int stock;
	int type; //1. Food; 2. Fashion; 3. Technological; 4. Houseware; 5. Other
protected:
	vector<Product> prdv;
	vector<Product> ordv;
public:
	Product() { ID = IDseller = productName = ""; price = 0; stock = 0; };
	friend istream& operator>>(istream&, Product&);
	friend ifstream& operator>> (ifstream&, Product&);
	friend ostream& operator<<(ostream&, Product&);
	friend ofstream& operator<<(ofstream&, Product&);
	Product& operator= (const Product & src);
	void loadProductfile();//doc file product.txt
	void loadProduct(ifstream& f, vector<Product> &arr, int nPro);//doc vao mang
	void saveProductfile();//luu file vaof product.txt
	void saveProduct(ofstream& f, vector<Product> arr);//luu mang vao file
	void display();
	void DisplayArrProduct(vector<Product> arr);
	void addProduct(vector<Product>& arr);
	//void removeProduct(vector<Product>& arr);


	string getID() { return ID; }
	string getIDseller() { return IDseller; }
	string getProductName() { return productName; }
	double getPrice() { return price; }
	int getStock() { return stock; }
	int getType() { return type; }

	void loadListProduct();
	void saveListProduct();
	Product loadOneProduct(ifstream& fin);
	void saveOneProduct(ofstream& fout);
	void displayListProduct();
	void inputProduct();
	void addProduct();
	void removeProduct();
	void editProduct();
	bool findProduct(const string);
};

#endif // !_PRODUCT_H