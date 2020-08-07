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
	string str;
	getline(fin, obj.ID);
	getline(fin, obj.productName);
	getline(fin, str);
	obj.price = atof(str.c_str());
	getline(fin, str);
	obj.stock = atoi(str.c_str());
	getline(fin, str);
	obj.type = atoi(str.c_str());

	return fin;
}
ostream& operator<<(ostream& out, Product& obj) {
	out << "ID: "<< obj.ID.c_str() << endl;
	out << "ProductName: " << obj.productName.c_str() << endl;
	out << "Price: " << obj.price << endl;
	out << "Stock: " << obj.stock << endl;
	out << "Type: " ;
	switch (obj.type)
	{
	case 1: {
		out << "Food" << endl;
		break;
	}
	case 2: {
		out << "Fashion" << endl;
		break;
	}
	case 3: {
		out << "Technological" << endl;
		break;
	}
	case 4: {
		out << "Houseware" << endl;
		break;
	}
	case 5: {
		out << "Other" << endl;
		break;
	}
	default:
		break;
	}
	return out;
}
ofstream& operator<<(ofstream& fout, Product& obj) {
	fout << obj.ID << endl;
	fout << obj.productName << endl;
	fout << obj.price << endl;
	fout << obj.stock << endl;
	fout << obj.type ;
	return fout;
}
Product& Product::operator= (const Product& src) {
	ID = src.ID;
	productName = src.productName;
	price = src.price;
	stock = src.stock;
	type = src.type;
	return*this;
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
	

	int nProduct;
	fin >> nProduct;
	fin.ignore();
	
	for (int i = 0; i < nProduct; i++)
	{
		Product tmp;
		fin >> tmp;
		prdv.push_back(tmp);
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
		fout << prdv[i] << endl;
	fout.close();
}

Product Product::loadOneProduct(ifstream& fin)
{
	string tmp;
	fin >> tmp;
	ID = atoi(tmp.c_str());
	getline(fin, tmp);
	productName = tmp;
	fin >> tmp;
	price = atoi(tmp.c_str());
	fin >> tmp;
	stock = atoi(tmp.c_str());
	fin >> tmp;
	type = atoi(tmp.c_str());
	return *this;
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
		cout << prdv[i] << endl << "____________________________________" << endl;;
}

void Product::inputProduct()
{
	cout << "ID: ";
	getline(cin, ID);
	cout << "Seller's ID: "; /////////////////////////// Review later
	getline(cin, IDseller);
	cout << "Name: ";
	getline(cin, productName);
	cout << "Price: ";
	cin >> price;
	cout << "Sock: ";
	cin >> stock;
	cout << "Type: ";
	cin >> type;
}

void Product::addProduct()
{
	Product prd;
	Product::loadListProduct();
	cin >> prd;
	prdv.push_back(prd);
	Product::saveListProduct();
}

void Product::removeProduct()
{
	string search ;
	cout << "Enter ID or name of the Product to remove: ";
	getline(cin, search);
	loadListProduct();
	if (findProduct(search)) {
	for (int i = 0; i < prdv.size(); i++)
		{
			if (prdv[i].getID() == search || prdv[i].getProductName() == search)
			{
				cout << prdv[i];
				char ans;
				cout << endl << "Are you sure you want to delete this product ? " << endl << "YES (Y)" << endl << "NO (N)" << endl;
				cin >> ans;
				switch (ans)
					{
				case 'YES': case 'Y':
				{
					prdv.erase(prdv.begin() + i);
					cout << "Product has been delete" << endl;
					break;
				}
				case 'NO': case 'N':default:
				{
					cout << "Can't delete product" << endl;
					break;
				}
					}
				
			}
		}
	}
	else {
		cout << "Not found product" << endl;
		return;
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
	int idx = 0;
	Product prd;
	Product::loadListProduct();
	string search;
	cout << "Enter ID or name to edit: ";
	getline(cin, search);
	if (findProduct(search)) {
		for (int i = 0; i < prdv.size(); i++)
		{
			if (prdv[i].getID() == search || prdv[i].getProductName() == search)
			{
				prd = prdv[i];
				idx = i;
				//cout << prdv[i];
				//prdv.erase(prdv.begin() + i);
				break;
			}
		}

		int n = 1;
		while (n != 0)
		{
			system("cls");
			cout << prd << endl;
			cout << "Edit your product for the store" << endl;
			cout << "1. ID" << endl;
			cout << "2. ID of the seller" << endl;
			cout << "3. Name" << endl;
			cout << "4. Price" << endl;
			cout << "5. Stock" << endl;
			cout << "6. Type" << endl;
			cout << "0. Back" << endl;
			cin >> n;
			switch (n)
			{
			case 1: {
				cin.ignore();
				cout << "New ID: ";
				getline(cin, ID);
				break;
			}
			case 2: {
				cin.ignore();
				cout << "New ID Seller: ";
				getline(cin, IDseller);
				break;
			}
			case 3: {
				cin.ignore();
				cout << "New Product Name: ";
				getline(cin, prd.productName);
				break;
			}
			case 4: {
				cout << "New Price: ";
				cin >> prd.price;
				break;
			}
			case 5: {
				cout << "New Stock: ";
				cin >> prd.stock;
				break;
			}
			case 6: {
				system("cls");
				cout << "New Type: " << endl;
				cout << "1. Food" << endl;
				cout << "2. Fashion" << endl;
				cout << "3. Technological" << endl;
				cout << "4. Houseware" << endl;
				cout << "5. Other" << endl;
				//cout << "0. Back" << endl;
				cin >> prd.type;
				break;
			}
			case 0 : default:
				break;
			}
		}
		cout << endl << "Are you sure you want to edit this product ? " << endl << "YES (Y)" << endl << "NO (N)" << endl;
		char ans;
		cin >> ans;
		switch (ans)
		{
			case 'YES': case 'Y':
			{
				prdv[idx] = prd;
				cout << "Product has been edited" << endl;
				break;
			}
			case 'NO': case 'N':default:
			{
				cout << "Can't edit product" << endl;
				break;
			}
		}
		saveListProduct();
	}
	else cout << "Not found product" << endl;
	system("pause");
}

bool Product::findProduct(const string search) {
	for (size_t i = 0; i < prdv.size(); i++) {
		if (prdv[i].getID() == search || prdv[i].getProductName() == search)
			return true;
	}
	return false;
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

