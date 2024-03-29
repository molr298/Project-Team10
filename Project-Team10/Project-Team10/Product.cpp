﻿#include "Product.h"
#include <stdio.h>
#define PUSH_BEST_PAIR_FOR_TRAVERSAL(x,y,z,t) n_best_pairs_for_traversals[x].push_back(nth_best_parse(x, y, z, e->leading_traversals[x]->active_edge->n_best_parses[y].viterbi_prob * e->leading_traversals[x]->passive_edge->n_best_parses[z].viterbi_prob * t))
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
	out << "ID: " << obj.ID.c_str() << endl;
	out << "ID of Seller: " << obj.IDseller.c_str() << endl;
	out << "Product Name: " << obj.productName.c_str() << endl;
	out << "Price: " << obj.price << endl;
	out << "Stock: " << obj.stock << endl;
	out << "Type: ";
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
	fout << obj.IDseller << endl;
	fout << obj.productName << endl;
	fout << obj.price << endl;
	fout << obj.stock << endl;
	fout << obj.type;
	return fout;
}
Product& Product::operator= (const Product& src) {
	ID = src.ID;
	IDseller = src.IDseller;
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

void Product::loadProduct(ifstream& f, vector<Product>& arr, int nPro)
{
	Product temp;
	for (int i = 0; i < nPro; i++) {
		f >> temp.ID;
		f >> temp.IDseller;
		f.ignore();
		getline(f, temp.productName);
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
		f << arr[i].ID << endl;
		f << arr[i].IDseller << endl;
		f << arr[i].productName << endl;
		f << arr[i].price;
		f << arr[i].stock;
		f << arr[i].type;
	}
}

void Product::DisplayArrProduct(vector<Product> arr)
{
	cout << "Quantity: " << arr.size() << endl << endl;
	for (int i = 0; i < arr.size(); i++) {
		arr[i].display();
		cout << endl;
	}

}

void Product::display()
{
	if (ID == "" && IDseller == "" && productName == "") {
		cout << "Product does not exist" << endl;
		return;
	}
	cout << setw(4) << left << ID << "\t" << setw(12) << left << IDseller << "\t" << setw(20) << left << productName << "\t" << setw(10) << left << price << "\t" << setw(10) << left << stock << "\t" << setw(20) << left;
	switch (type)
	{
	case 1: {
		cout << "Food";
		break;
	}
	case 2: {
		cout << "Fashion";
		break;
	}
	case 3: {
		cout << "Technological";
		break;
	}
	case 4: {
		cout << "Houseware";
		break;
	}
	case 5: {
		cout << "Other";
		break;
	}
	default:
		break;
	}
	Rate rating;
	rating.loadListRating();
	rating.miniDisplay(IDseller, ID);
	cout << endl;
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
	Product* p = nullptr;
	
	for (int i = 0; i < nProduct; i++)
	{
//		string line;
		//getline(fin, line);
		p = new Product;
		p->loadOneProduct(fin);
		prdv.push_back(p);
	}

	fin.close();
}

void Product::saveListProduct()
{
	remove("Product/Product.txt");
	ofstream fout("Product/Product.txt");
	if (!fout.is_open()) {
		cout << "Can't write user information!!" << endl;
		return;
	}
	fout << prdv.size() << endl;
	for (int i = 0; i < prdv.size(); i++)
	{
		prdv[i]->saveOneProduct(fout);
	}
	fout.close();
	prdv.clear();
}

Product& Product::loadOneProduct(ifstream& fin)
{
	getline(fin, ID);
	getline(fin, IDseller);
	getline(fin, productName);
	getline(fin, descript);
	fin >> price;
	fin >> stock;
	fin >> type;
	fin.ignore();

	return *this;
}

void Product::saveOneProduct(ofstream& fout)
{
	fout << ID << endl;
	fout << IDseller << endl;
	fout << productName << endl;
	fout << descript << endl;
	fout << price << endl;
	fout << stock << endl;
	fout << type << endl;
}

void Product::displayListProduct()
{

	cout << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(10) << left << "Type\t" << setw(7) << left << "Rating " << endl;
	for (int i = 0; i < prdv.size(); i++)
		prdv[i]->display();
	cout << "____________________________________" << endl;
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

void Product::addProduct(Product prd)
{
	Product::loadListProduct();
	Product* pAdd = nullptr;
	pAdd = new Product;
	pAdd = &prd;
	prdv.push_back(pAdd);
	Product::saveListProduct();
}

void Product::removeProduct(string search)
{
	//cout << "Enter ID or name of the Product to remove: ";
	//getline(cin, search);
	loadListProduct();

	if (containProduct(search)) {
		for (int i = 0; i < prdv.size(); i++)
		{
			if (prdv[i]->getID() == search || prdv[i]->getProductName() == search)
			{
				cout << setw(4) << left << "Number" << "\t" << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(10) << left << "Type\t" << setw(7) << left << "Rating " << endl;
				cout << endl;
				cout << "1" << "\t";
				prdv[i]->display();
				char ans;
				cout << endl << "Are you sure you want to delete this product ? " << endl << "YES(yes) (Y,y)" << endl << "NO(no) (N,n)" << endl;
				cin >> ans;
				switch (ans)
				{
				case 'YES': case 'Y': case 'yes': case 'y':
				{
					delete prdv[i];
					prdv.erase(prdv.begin() + i);
					cout << "Product has been delete" << endl;
					break;
				}
				case 'NO': case 'N':case 'n': case 'no':
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


void Product::editProduct()
{
	int idx = 0;
	Product prd;
	Product::loadListProduct();
	string search;
	cout << "Enter ID or name to edit: ";
	cin.ignore();
	getline(cin, search);
	if (search == "")
		return;
	if (containProduct(search))
	{
		for (int i = 0; i < prdv.size(); i++)
		{
			if (prdv[i]->getID() == search || prdv[i]->getProductName() == search)
			{
				prd = *prdv[i];
				idx = i;
				break;
			}
		}

		int n = 1;
		while (n != 0)
		{
			system("cls");
			prd.display();
			cout << "Edit your product for the store" << endl;

			cout << "1. Name" << endl;
			cout << "2. Price" << endl;
			cout << "3. Stock" << endl;
			cout << "4. Type" << endl;
			cout << "0. Back" << endl;
			cin >> n;
			switch (n)
			{
			case 1: {
				cin.ignore();
				cout << "New Product Name: ";
				getline(cin, prd.productName);
				break;
			}
			case 2: {
				cout << "New Price: ";
				cin >> prd.price;
				break;
			}
			case 3: {
				cout << "New Stock: ";
				cin >> prd.stock;
				break;
			}
			case 4: {
				cout << "New Type: " << endl;
				cout << "1. Food" << endl;
				cout << "2. Fashion" << endl;
				cout << "3. Technological" << endl;
				cout << "4. Houseware" << endl;
				cout << "5. Other" << endl;
				cin >> prd.type;
				break;
			}
			case 0: default:
				break;
			}
		}
		cout << endl << "Are you sure you want to edit this product ? " << endl << "YES(yes) (Y,y)" << endl << "NO(no) (N,n)" << endl;
		char ans;
		cin >> ans;
		switch (ans)
		{
		case 'YES': case 'Y': case 'yes': case 'y':
		{
			prdv[idx] = &prd;
			cout << "Product has been edited" << endl;
			break;
		}
		case 'NO': case 'N': case 'no': case 'n':
		{
			cout << "Can't edit product" << endl;
			break;
		}
		}
		Product::saveListProduct();
	}
	else cout << "Not found product" << endl;
	system("pause");
}

void Product::deleteAllProductOfSeller(string IDSeller)
{
	loadListProduct();
	for (int i = 0; i < prdv.size(); i++) {
		if (prdv[i]->getIDseller() == IDSeller) {
			delete prdv[i];
			prdv.erase(prdv.begin() + i);
			i--;
		}
	}
	saveListProduct();
}


bool isDuplicate(string IDProduct, vector<string> listID) {
	for (int i = 0; i < listID.size(); i++)
		if (listID[i] == IDProduct)
			return true;
	return false;
}

void loadListIDProduct(vector<string>& listID, vector<string>& listSeller) {
	ifstream fin("Product/productID.txt");
	if (!fin.is_open()) {
		cout << "Can't generate ID of Product..." << endl;
		return;
	}
	int number_of_product_ID;
	fin >> number_of_product_ID;
	fin.ignore();
	string ID;
	string seller;
	for (int i = 0; i < number_of_product_ID; i++) {
		getline(fin, ID, '-');
		listID.push_back(ID);
		getline(fin, seller);
		listSeller.push_back(seller);
	}
	fin.close();
}

void saveListIDProduct(vector<string>& listID, vector<string>& listSeller) {
	ofstream fout("Product/productID.txt");
	if (!fout.is_open()) {
		cout << "Can't save ID of product..." << endl;
		return;
	}
	fout << listID.size() << endl;
	for (int i = 0; i < listID.size(); i++)
		fout << listID[i] << "-" << listSeller[i] << endl;
	fout.close();
}
string Product::generateRandomIDProduct(string IDSeller)
{
	vector <string> listID;
	vector <string> listSeller;
	loadListIDProduct(listID, listSeller);
	do {
	ID = to_string(rand() % 900 + 100);
	char last_char;
	last_char = rand() % 25 + 65;
	ID += last_char;
	} while (isDuplicate(ID, listID));

	listID.push_back(ID);
	listSeller.push_back(IDSeller);
	saveListIDProduct(listID, listSeller);

	return ID;
}

Product Product::inputNewProduct(string IDSeller)
{
	Product newProduct;
	newProduct.ID = generateRandomIDProduct(IDSeller);	//1
	//IDSEller 2
	cin.ignore();
	cout << "\tName: ";			getline(cin, newProduct.productName);	//3
	cout << "\tPrice (VND): ";	cin >> newProduct.price;//4
	cout << "\tStock: ";		cin >> newProduct.stock;//5
	cout << "\tType (1. Food; 2. Fashion; 3. Technological; 4. Houseware; 5. Other): ";//6
	cin >> newProduct.type;
	cin.ignore();
	cout << "\tDescription: ";	getline(cin, newProduct.descript);//7

	newProduct.IDseller = IDSeller;
	Rate newRate;
	Comment newCommentFile(newProduct.ID, IDSeller);
	newRate.addNewRating(newProduct.ID, IDSeller);
	newCommentFile.createNewFileComment(newProduct.ID, IDSeller);
	return newProduct;
}

bool Product::containProduct(const string search) {
	for (size_t i = 0; i < prdv.size(); i++) {
		if (prdv[i]->getID() == search || prdv[i]->getProductName() == search)
			return true;
	}
	return false;
}

//Product Product::findProduct(const string& ID)
//{
//	if (containProduct(ID)) {
//		for (size_t i = 0; i < prdv.size(); i++)
//		{
//			if (prdv[i]->getID() == ID) {
//				return prdv[i];
//			}
//		}
//	}
//	return Product();
//}
void Product::saveNotifUser(string IDseller)
{
	UserNotif::loadListNotif();
	Product::loadListProduct();
	for (int i = 0; i < usnv.size(); i++)
	{
		for (int j = 0; j < prdv.size(); j++)
		{
			if (IDseller == prdv[j]->getIDseller() && usnv[i].getProductName() == prdv[j]->getProductName() && usnv[i].getProductID() == prdv[j]->getID() && usnv[i].getStatus() == 0)
			{
				if (prdv[j]->stock > usnv[i].getQuantity())
				{
					prdv[j]->stock -= usnv[i].getQuantity();
				}
				else
				{
					cout << "Product " << prdv[j]->productName << " doesn't have eough supplies for user " << usnv[i].getCustomerID() << endl;
					cout << "It lacks " << usnv[i].getQuantity() - prdv[j]->stock << endl;
				}
				usnv[i].setStatus(1);
			}
		}
	}
	UserNotif::saveListOrder();
	Product::saveListProduct();
	usnv.clear();
	prdv.clear();
}
bool Product::listSearchProduct()
{
	filterProduct.clear();
	Product::loadListProduct();
	UserNotif::loadListNotif();
	string search;
//	vector<Product> temp;
	int n1 = usnv.size();
	cin.ignore();
	cout << "Enter ID or name to search: ";
	getline(cin, search);
	for (int i = 0; i < search.size(); i++) {
		search[i] = toupper(search[i]);
	}
	bool flag = 0;
	for (int i = 0; i < prdv.size(); i++)
	{
		int found = -1;
		string tmp = prdv[i]->getProductName();
		for (int i = 0; i < tmp.size(); i++)
			tmp[i] = toupper(tmp[i]);

		found = tmp.find(search);
		if (prdv[i]->getID() == search || prdv[i]->getProductName() == search || found != -1) /////////Hàm tìm keyword sẽ review sau https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
		{
			flag = 1;
			filterProduct.push_back(prdv[i]);
		}
	}
	return flag;
}
bool Product::listFilterProduct()
{
	filterProduct.clear();
	Product::loadListProduct();
	UserNotif::loadListNotif();
	int search;
//	vector<Product> temp;
	int n1 = usnv.size();
	cout << "1. Food" << endl;
	cout << "2. Fashion" << endl;
	cout << "3. Technological" << endl;
	cout << "4. Houseware" << endl;
	cout << "5. Other" << endl;
	cout << "Choose type of product:"; //1. Food; 2. Fashion; 3. Technological; 4. Houseware; 5. Other
	cin >> search;
	bool flag = 0;
	for (int i = 0; i < prdv.size(); i++)
	{
	//	cout << "TYPEEEE: " << prdv[i]->getType() << endl;
		if (prdv[i]->getType() == search) /////////Hàm tìm keyword sẽ review sau https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
		{
			flag = 1;
			filterProduct.push_back(prdv[i]);
		}
	}
	return flag;
}
void Product::viewStoreOfSeller(string IDseller)
{
	loadListProduct();
	cout << setw(4) << left << "ID" << "\t" << setw(15) << left << "ID's Seller" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(15) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(20) << left << "Type" << "\t" << setw(20) << left << "Rate" << endl;
	for (int i = 0; i < prdv.size(); i++) {
		if (prdv[i]->IDseller == IDseller)
			prdv[i]->display();
	}
}
void Product::prdvClear()
{
	for (int i = 0; i < prdv.size()-1; i++)
		delete prdv[i];
}
void Product::ordvClear()
{
	/*for (int i = 0; i < prdv.size(); i++)
		delete ordv[i];*/
}
void Product::filterProductClear()
{
	for (int i = 0; i < prdv.size(); i++)
		delete filterProduct[i];
}
void Product::setupCart(int quantity, Product p)
{
	UserNotif usn;
	usn.getProduct(p.ID, "", p.IDseller, p.productName, p.price, quantity, p.type);
	usnv.push_back(usn);
}



Rate::Rate()
{
	IDSeller = "";
	IDProduct = "";
	ratePoint = 0;
	Rating = 0;
}

Rate::Rate(string IDProduct, string IDSeller)
{
	ratePoint = 0;
	Rating = 0;
	this->IDProduct = IDProduct;
	this->IDSeller = IDSeller;
}

void Rate::loadListRating()
{
	listRating.clear();
	ifstream fin(RATE_PATH);
	if (!fin.is_open()) {
		cout << "Can't load rating of product..." << endl;
		return;
	}
	Rate load1;
	int nRating;
	fin >> nRating;
	for (int i = 0; i < nRating; i++) {
		fin.ignore();
		getline(fin, load1.IDProduct);
		getline(fin, load1.IDSeller);
		fin >> load1.ratePoint;
		fin >> load1.Rating;
		listRating.push_back(load1);
	}
	fin.close();
}

void Rate::saveListRating()
{
	ofstream fout(RATE_PATH);
	if (!fout.is_open()) {
		cout << "Can't save rating..." << endl;
		return;
	}
	fout << listRating.size() << endl;
	for (int i = 0; i < listRating.size(); i++) {
		fout << listRating[i].IDProduct << endl;
		fout << listRating[i].IDSeller << endl;
		fout << listRating[i].ratePoint << endl;
		fout << listRating[i].Rating << endl;
	}
	fout.close();
	listRating.clear();
}

bool Rate::checkExistRating(string IDProduct, string IDSeller)
{
	loadListRating();
	for (int i = 0; i < listRating.size(); i++)
		if (listRating[i].IDProduct == IDProduct && listRating[i].IDSeller == IDSeller)
			return true;
	return false;
}

void Rate::addNewRating(string IDProduct, string IDSeller)
{
	Rate newRating(IDProduct, IDSeller);
	loadListRating();
	listRating.push_back(newRating);
	saveListRating();
}

void Rate::displayRatingOfProduct(string IDProduct, string productName, string IDSeller)
{
	loadListRating();

	for (int i = 0; i < listRating.size(); i++)
		if (listRating[i].IDProduct == IDProduct && listRating[i].IDSeller == IDSeller) {
			cout << "ID Product: " << this->IDProduct << endl;
			cout << productName << endl;
			cout << "ID of seller: " << IDSeller << endl;
			cout << ratePoint << "*/5*" << endl;
			cout << Rating << "Ratings" << endl;
		}
}

void Rate::updateRating(int addPoint, string IDProduct, string IDSeller)
{
	loadListRating();
	for (int i = 0; i < listRating.size(); i++)
		if (listRating[i].IDProduct == IDProduct && listRating[i].IDSeller == IDSeller) {
			listRating[i].Rating++;
			listRating[i].ratePoint = (listRating[i].ratePoint + 1.0 * addPoint) / listRating[i].Rating;
			break;
		}
	saveListRating();
}

void Rate::deleteAProductRating(string IDSeller, string IDProduct)
{
	loadListRating();
	for (int i = 0; i < listRating.size(); i++)
		if (listRating[i].IDProduct == IDProduct && listRating[i].IDSeller == IDSeller) {
			listRating.erase(listRating.begin() + i);
			break;
		}
	saveListRating();
}

void Rate::deleteAllOfSeller(string IDSeller)
{
	loadListRating();
	for (int i = 0; i < listRating.size(); i++)
		if (listRating[i].IDSeller == IDSeller)
			listRating.erase(listRating.begin() + i);
	saveListRating();
}

void Rate::miniDisplay(string IDSeller, string IDProduct)
{
	for (int i = 0; i < listRating.size(); i++)
		if (listRating[i].IDProduct == IDProduct && listRating[i].IDSeller == IDSeller)
			cout << left << listRating[i].ratePoint << setw(3) << left << "/5*   " << listRating[i].Rating << " Ratings";
	return;
}

Comment::Comment()
{
	this->IDProduct = "";
	this->IDSeller = "";
	IDCustomer = "";
	comment = "";
}

Comment::Comment(string IDSeller)
{
	this->IDProduct = "";
	this->IDSeller = IDSeller;
	IDCustomer = "";
	comment = "";
}

Comment::Comment(string IDProduct, string IDSeller)
{
	this->IDProduct = IDProduct;
	this->IDSeller = IDSeller;
	IDCustomer = "";
	comment = "";
}

Comment::Comment(string IDProduct, string IDSeller, string newComment, string IDCustomer)
{
	this->IDProduct = IDProduct;
	this->IDSeller = IDSeller;
	this->comment = newComment;
	this->IDCustomer = IDCustomer;
}

void Comment::loadListComment(string IDPRoduct, string IDSeller)
{
	listComment.clear();
	ifstream fin(COMMENT_PATH + IDPRoduct + "-" + IDSeller + ".txt");	//Product/Comment/101T-19127001.txt	
	if (!fin.is_open()) {
		cout << "Can't load comment of this product" << endl;
		return;
	}
	int nComment;
	fin >> nComment;
	fin.ignore();
	Comment load1(IDPRoduct, IDSeller);
	for (int i = 0; i < nComment; i++) {
		getline(fin, load1.IDCustomer, '-');	//IDCustomer-Comment
		getline(fin, load1.comment);
		listComment.push_back(load1);
	}
	fin.close();
}

void Comment::saveListComment(string IDProduct, string IDSeller)
{
	ofstream fout(COMMENT_PATH + IDProduct + "-" + IDSeller + ".txt");
	if (!fout.is_open()) {
		cout << "Can't load comment of this product" << endl;
		return;
	}
	fout << listComment.size() << endl;
	for (int i = 0; i < listComment.size(); i++) {
		fout << listComment[i].IDCustomer << "-" << listComment[i].comment << endl;
	}
	fout.close();
	listComment.clear();
}

void Comment::createNewFileComment(string IDPRoduct, string IDSeller)
{
	ofstream fout(COMMENT_PATH + IDProduct + "-" + IDSeller + ".txt");
	if (!fout.is_open()) {
		cout << "Can't load comment of this product" << endl;
		return;
	}
	fout << 0;
	fout.close();
}

void Comment::addNewComment(string IDProduct, string IDSeller, string newComment, string IDCustomer)
{
	loadListComment(IDProduct, IDSeller);
	Comment addNew(IDProduct, IDSeller, newComment, IDCustomer);
	listComment.push_back(addNew);
	saveListComment(IDProduct, IDSeller);
}

void Comment::displayComment(string IDProduct, string IDSeller)
{
	loadListComment(IDProduct, IDSeller);
	if (listComment.size() > 1)
		cout << listComment.size() << " Comments" << endl;
	else
		cout << listComment.size() << " Comment" << endl;
	for (int i = 0; i < listComment.size(); i++)
		cout << "#" << listComment[i].IDCustomer << ": " << listComment[i].comment << endl;
}

void Comment::deleteAllCommentFileOfSeller()
{
	vector<string> listProductID;
	vector<string> listSeller;
	loadListIDProduct(listProductID, listSeller);
	for (int i = 0; i < listProductID.size(); i++) {
		if (this->IDSeller == listSeller[i]) {
			string fileDel = listProductID[i] + "-" + listSeller[i] + ".txt";

			remove(fileDel.c_str());
			listProductID.erase(listProductID.begin() + i);
			listSeller.erase(listSeller.begin() + i);
			i--;
		}
	}
	saveListIDProduct(listProductID, listSeller);
}

void Comment::deleteACommentFile()
{
	vector<string> listProductID;
	vector<string> listSeller;
	loadListIDProduct(listProductID, listSeller);
	for (int i = 0; i < listProductID.size(); i++) {
		if (this->IDSeller == listSeller[i] && this->IDProduct == listProductID[i]) {
			string fileDel = listProductID[i] + "-" + listSeller[i] + ".txt";

			remove(fileDel.c_str());
			listProductID.erase(listProductID.begin() + i);
			listSeller.erase(listSeller.begin() + i);
			i--;
		}
	}
	saveListIDProduct(listProductID, listSeller);
}
