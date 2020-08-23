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
	out << "ID of Seller: " << obj.IDseller.c_str() << endl;
	out << "Product Name: " << obj.productName.c_str() << endl;
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
	fout << obj.IDseller << endl;
	fout << obj.productName << endl;
	fout << obj.price << endl;
	fout << obj.stock << endl;
	fout << obj.type ;
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
	if (ID == "" && IDseller == "" && productName == "") {
		cout << "Product does not exist" << endl;
		return;
	}
	cout << setw(4) << left << ID << "\t" << setw(12) << left << IDseller << "\t" << setw(20) << left << productName << "\t" << setw(10) << left << price << "\t" << setw(10) << left << stock << "\t" << setw(10) << left;
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
	for (int i = 0; i < nProduct; i++)
	{
		string line;
		getline(fin, line);
		prdv.push_back(Product::loadOneProduct(fin));
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
		prdv[i].saveOneProduct(fout);
	}
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

	cout << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(10) << left << "Type" << endl;
	for (int i = 0; i < prdv.size(); i++)
		prdv[i].display();
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
	prdv.push_back(prd);
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
			if (prdv[i].getID() == search || prdv[i].getProductName() == search)
			{
				cout << setw(4) << left << "Number" << "\t" << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(10) << left << "Type" << endl;
				cout << endl;
				cout << "1" << "\t";
				prdv[i].display();
				char ans;
				cout << endl << "Are you sure you want to delete this product ? " << endl << "YES(yes) (Y,y)" << endl << "NO(no) (N,n)" << endl;
				cin >> ans;
				switch (ans)
					{
				case 'YES': case 'Y': case 'yes': case 'y':
				{
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
			if (prdv[i].getID() == search || prdv[i].getProductName() == search)
			{
				prd = prdv[i];
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
			case 0 : default:
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
				prdv[idx] = prd;
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

bool Product::containProduct(const string search) {
	for (size_t i = 0; i < prdv.size(); i++) {
		if (prdv[i].getID() == search || prdv[i].getProductName() == search)
			return true;
	}
	return false;
}

Product Product::findProduct(const string& ID)
{
	if (containProduct(ID)) {
		for (size_t i = 0; i < prdv.size(); i++)
		{
			if (prdv[i].getID() == ID) {
				return prdv[i];
			}
		}
	}
	return Product();
}
void Product::saveNotifUser(string IDseller)
{
	UserNotif::loadListNotif();
	Product::loadListProduct();
	for (int i = 0; i < usnv.size(); i++)
	{
		for (int j = 0; j < prdv.size(); j++)
		{
			if (IDseller == prdv[j].getIDseller() && usnv[i].getProductName() == prdv[j].getProductName() && usnv[i].getProductID() == prdv[j].getID() && usnv[i].getStatus() == 0)
			{
				if (prdv[j].stock > usnv[i].getQuantity())
				{
					prdv[j].stock -= usnv[i].getQuantity();
				}
				else
				{
					cout << "Product " << prdv[j].productName << " doesn't have eough supplies for user " << usnv[i].getCustomerID() << endl;
					cout << "It lacks " << usnv[i].getQuantity() - prdv[j].stock << endl;
				}
				usnv[i].setStatus(1);
			}
		}
	}
	UserNotif::saveListOrder();
	Product::saveListProduct();
}
void Product::viewStoreOfSeller(string IDseller)
{
	loadListProduct();
	for (int i = 0; i < prdv.size(); i++) {
		if (prdv[i].IDseller == IDseller)
			prdv[i].display();
	}
}
void Product::setupCart(int quantity, Product p)
{
	UserNotif usn;
	usn.getProduct(p.ID,"", p.IDseller, p.productName, p.price, quantity, p.type);
	usnv.push_back(usn);
}

void Product::filterListProduct()
{
	loadListProduct();

	foodList.clear(); //1 
	fashionList.clear(); // 2
	technologicalList.clear(); //3
	housewareList.clear(); // 4
	otherList.clear(); // 5

	for (size_t i = 0; i < prdv.size(); i++)
	{
		if (prdv[i].getType() == 1) {
			foodList.push_back(prdv[i]);
		}
		else if(prdv[i].getType() == 2)
		{
			fashionList.push_back(prdv[i]);
		}
		else if (prdv[i].getType() == 3)
		{
			technologicalList.push_back(prdv[i]);
		}
		else if (prdv[i].getType() == 4)
		{
			housewareList.push_back(prdv[i]);
		}
		else
		{
			otherList.push_back(prdv[i]);
		}
	}
	displayFoodList();
	displayFashionList();
	displayTechnologicalList();
	displayHousewareList();
	displayOtherList();
}

void Product::displayFoodList() 
{
	if (foodList.empty()) cout << "There is no food product" << endl;
	else
	{
		cout << "Food product list" << endl;
		cout << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(10) << left << "Type" << endl;
		for (int i = 0; i < foodList.size(); i++)
			foodList[i].display();
		cout << "____________________________________" << endl;
	}
	
}
void Product::displayFashionList()
{
	if (fashionList.empty()) cout << "There is no fashion product" << endl;
	else
	{
		cout << "Fashion product list" << endl;
		cout << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(10) << left << "Type" << endl;
		for (int i = 0; i < fashionList.size(); i++)
			fashionList[i].display();
		cout << "____________________________________" << endl;
	}
	
}
void Product::displayTechnologicalList()
{
	if (technologicalList.empty()) cout << "There is no technological product" << endl;
	else
	{
		cout << "Technological product list" << endl;
		cout << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(10) << left << "Type" << endl;
		for (int i = 0; i < technologicalList.size(); i++)
			technologicalList[i].display();
		cout << "____________________________________" << endl;
	}
	
}
void Product::displayHousewareList()
{
	if (housewareList.empty()) cout << "There is no houseware product" << endl;
	else
	{
		cout << "Houseware product list" << endl;
		cout << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(10) << left << "Type" << endl;
		for (int i = 0; i < housewareList.size(); i++)
			housewareList[i].display();
		cout << "____________________________________" << endl;
	}
	
}
void Product::displayOtherList()
{
	if (otherList.empty()) cout << "There is no other product" << endl;
	else
	{
		cout << "Other product list" << endl;
		cout << setw(4) << left << "ID" << "\t" << setw(12) << left << "Seller's ID" << "\t" << setw(20) << left << "Product's name" << "\t" << setw(10) << left << "Price" << "\t" << setw(10) << left << "Stock" << "\t" << setw(10) << left << "Type" << endl;
		for (int i = 0; i < otherList.size(); i++)
			otherList[i].display();
		cout << "____________________________________" << endl;
	}
	
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


