#ifndef _Product_H
#define _Product_H

#include "Lib.h"

#include<vector>

#include "Notification.h"
class Product : public UserNotif
{
private:
	string ID;
	string IDseller; // ?
	string productName;
	double price;
	int stock;
	int type; //1. Food; 2. Fashion; 3. Technological; 4. Houseware; 5. Other
	string descript;
protected:
	vector<Product*> prdv;
	vector<Product*> ordv;
	vector<Product*> filterProduct;

public:
	Product() { ID = IDseller = productName = ""; price = 0; stock = 0; };
	friend istream& operator>>(istream&, Product&);
	friend ifstream& operator>> (ifstream&, Product&);
	friend ostream& operator<<(ostream&, Product&);
	friend ofstream& operator<<(ofstream&, Product&);
	Product& operator= (const Product& src);
	void loadProductfile();//doc file product.txt
	void loadProduct(ifstream& f, vector<Product>& arr, int nPro);//doc vao mang
	void saveProductfile();//luu file vaof product.txt
	void saveProduct(ofstream& f, vector<Product> arr);//luu mang vao file
	void display();
	void DisplayArrProduct(vector<Product> arr);
	void addProduct(vector<Product>& arr);
	void setPrice(double n) { price = n; }


	string getID() { return ID; }
	string getIDseller() { return IDseller; }
	string getProductName() { return productName; }
	double getPrice() { return price; }
	int getStock() { return stock; }
	int getType() { return type; }
	string getDescr() { return descript; }
	void setQuantity(int n) { stock = n; }
	void loadListProduct();
	void saveListProduct();

	Product& loadOneProduct(ifstream& fin);
	void saveOneProduct(ofstream& fout);
	void displayListProduct();
	void inputProduct();
	void addProduct(Product);
	void removeProduct(string);
	void editProduct();

	void deleteAllProductOfSeller(string IDSeller);
	string generateRandomIDProduct(string IDSeller);
	Product inputNewProduct(string);
	bool containProduct(const string);
	void setupCart(int quantity, Product p);
	void saveNotifUser(string IDseller);
	//void displayFoodList();
	//void displayFashionList();
	//void displayTechnologicalList();
	//void displayHousewareList();
	//void displayOtherList();

	bool listSearchProduct();
	bool listFilterProduct();
	void viewStoreOfSeller(string IDseller);

	void prdvClear();
	void ordvClear();
	void filterProductClear();
};

class Rate {
private:
	string IDSeller;
	string IDProduct;
	double ratePoint;
	int Rating;

	vector<Rate> listRating;
public:
	Rate();
	Rate(string, string);
	void loadListRating();
	void saveListRating();

	bool checkExistRating(string IDProduct, string IDSeller);
	void addNewRating(string IDProduct, string IDSeller);
	void displayRatingOfProduct(string IDProduct, string productName, string IDSeller);
	void updateRating(int addPoint, string IDProduct, string IDSeller);
	void deleteAProductRating(string IDSeller, string IDProduct);
	void deleteAllOfSeller(string IDSeller);
	void miniDisplay(string IDSeller, string IDProduct);
};


class Comment {
private:
	string IDSeller;
	string IDProduct;
	string IDCustomer;
	string comment;

	vector<Comment> listComment;
public:
	Comment();
	Comment(string IDSeller);
	Comment(string IDProduct, string IDSeller);
	Comment(string IDProduct, string IDSeller, string newComment, string IDCustomer);
	void loadListComment(string, string);
	void saveListComment(string IDProduct, string IDSeller);

	void createNewFileComment(string, string);
	void addNewComment(string IDProduct, string IDSeller, string newComment, string IDCustomer);
	void displayComment(string IDProduct, string IDSeller);
	void deleteAllCommentFileOfSeller();
	void deleteACommentFile();
};
#endif // !_PRODUCT_H