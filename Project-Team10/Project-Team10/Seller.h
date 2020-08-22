#pragma once
#include "Customer.h"
class Seller: public Customer, public AdminNotif, public AccountInfo
{
	vector<Product> list; // danh sách sp trong cửa hàng
public:
	void approveCart(bool approveOrder, string IDseller);
	void saleStatistic(string IDseller);
	void sendReport(string senderID1);
	void addProduct(const Product&);
	void removeProduct(const string&); 
	void changePrice(Product obj);
};

