#pragma once
#include "Customer.h"
class Seller: public Customer, public AdminNotif, public AccountInfo
{
public:
	void approveCart(bool approveOrder, string IDseller);
	void saleStatistic(string IDseller);
	void sendReport(string senderID1);
};

