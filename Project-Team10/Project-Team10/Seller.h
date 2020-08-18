#pragma once
#include "Customer.h"
class Seller: public Customer
{
public:
	void approveCart(bool approveOrder, string IDseller);
	void saleStatistic(string IDseller);
};

