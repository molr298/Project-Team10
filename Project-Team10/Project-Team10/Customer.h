#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include"Lib.h"
#include "AccountInfo.h"
#include "Product.h"
class Customer: public AccountInfo, public Product
{
private:
	
public:

	void buyStuff();
	void viewCart();
};

#endif // !_CUSTOMER_H

