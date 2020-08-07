#include "Product.h"
//
//int ID;
//string productName;
//double price;
//int stock;
//int type;


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

void Product::addProduct(vector<Product>& arr) {
	Product a;
	cout << "Product needs adding: " << endl;
	cin >> a;
	arr.push_back(a);
}

void Product::loadListProduct()
{
	prdv.clear();
	ifstream fin;
	fin.open("Product/Product.txt");
	if (!fin.is_open()) {
		cout << "Can't open Product.txt!!" << endl;
		return;
	}
	int nProdcut;
	fin >> nProdcut;
	for (int i = 0; i < nProdcut; i++)
	{
		string line;
		getline(fin, line);
		prdv.push_back(Product::loadOneProduct(fin));
	}
	fin.close();
}

void Product::saveListProduct()
{
	ofstream fout("Product/Product.txt");
	if (!fout.is_open()) {
		cout << "Can't write user information!!" << endl;
		return;
	}
	fout << prdv.size() << endl;
	for (int i = 0; i < prdv.size(); i++)
		prdv[i].saveOneProduct(fout);
	fout.close();
}

Product Product::loadOneProduct(ifstream& fin)
{
	getline(fin, ID);
	getline(fin, IDseller);
	getline(fin, productName);
	fin >> price;
	fin >> stock;
	fin >> type;
	fin.ignore();
	return*this;
}
void Product::saveOneProduct(ofstream& fout)
{
	fout << ID << endl;
	fout << IDseller << endl;
	fout << productName << endl;
	fout << price << endl;
	fout << stock << endl;
	fout << type << endl << endl;
}

void Product::displayListProduct()
{
	for (int i = 0; i < prdv.size(); i++) 
	{
		prdv[i].display();
		cout << endl;
	}
}

void Product::inputProduct()
{
	cout << "Enter Product's ID: ";
	getline(cin, ID);
	cout << "Enter seller's ID: "; /////////////////////////// Review later
	getline(cin, IDseller);
	cout << "Enter Product's Name: ";
	getline(cin, productName);
	cout << "Enter price: ";
	cin >> price;
	cout << "Enter stock: ";
	cin >> stock;
	cout << "Enter type: ";
	cin >> type;
}

void Product::addProduct()
{
	Product prd;
	Product::loadListProduct();
	prd.inputProduct();
	prdv.push_back(prd);
	Product::saveListProduct();
}

void Product::removeProduct()
{
	string search;
	cout << "Enter ID or name of the Product to remove: ";
	getline(cin, search);
	Product::loadListProduct();
	for (int i = 0; i < prdv.size(); i++)
	{
		if (prdv[i].getID() == search || prdv[i].getProductName() == search)
		{
			prdv.erase(prdv.begin() + i);
			break;
		}
	}
	Product::saveListProduct();
}

void Product::editProductInfo()
{
	int n = 1;
	while (n != 0)
	{
		cout << "Edit your product for the store";
		cout << "Enter 1 for the ID" << endl;
		cout << "Enter 2 for the ID of the seller" << endl;
		cout << "Enter 3 for the Name" << endl;
		cout << "Enter 4 for the price" << endl;
		cout << "Enter 5 for the stock" << endl;
		cout << "Enter 6 for the type" << endl;
		cin >> n;
		switch (n)
		{
		case 1: {
			cout << "New ID: ";
			cin >> ID;
			break;
		}
		case 2: {
			cout << "New ID Seller: ";
			cin >> IDseller;
			break;
		}
		case 3: {
			cout << "New Product Name: ";
			cin >> productName;
			break;
		}
		case 4: {
			cout << "New Price: ";
			cin >> price;
			break;
		}
		case 5: {
			cout << "New Stock: ";
			cin >> stock;
			break;
		}
		case 6: {
			cout << "New Type: ";
			cin >> type;
			break;
		}
		default:
			break;
		}
	}
}
void Product::editProduct()
{
	Product prd;
	Product::loadListProduct();
	string search;
	cout << "Enter ID or name to edit: ";
	getline(cin, search);
	int n = 1;
	while (n != 0)
	{
		cout << "Edit your product for the store";
		cout << "Enter 1 for the ID" << endl;
		cout << "Enter 2 for the ID of the seller" << endl;
		cout << "Enter 3 for the Name" << endl;
		cout << "Enter 4 for the price" << endl;
		cout << "Enter 5 for the stock" << endl;
		cout << "Enter 6 for the type" << endl;
		cin >> n;
		switch (n)
		{
		case 1: {
			cout << "New ID: ";
			cin >> ID;
			break;
		}
		case 2: {
			cout << "New ID Seller: ";
			cin >> IDseller;
			break;
		}
		case 3: {
			cout << "New Product Name: ";
			cin >> productName;
			break;
		}
		case 4: {
			cout << "New Price: ";
			cin >> price;
			break;
		}
		case 5: {
			cout << "New Stock: ";
			cin >> stock;
			break;
		}
		case 6: {
			cout << "New Type: ";
			cin >> type;
			break;
		}
		default:
			break;
		}
	}
	for (int i = 0; i < prdv.size(); i++)
	{
		if (prdv[i].getID() == search || prdv[i].getProductName() == search)
		{
			prdv.erase(prdv.begin() + i);
			break;
		}
	}
	prdv.push_back(prd);
	Product::saveListProduct();
}
//Product Prodcut::findUser(const string& keyword)
//{
//	for (int i = 0; i < listUser.size(); i++)
//		if (listUser[i].getID() == keyword || listUser[i].getUsername() == keyword)
//			return listUser[i];
//}
//
//
//void Customer::displayListUser()
//{
//	for (int i = 0; i < listUser.size(); i++) {
//		listUser[i].displayAccountInfo();
//	}
//	cout << "________________________________" << endl;
//}