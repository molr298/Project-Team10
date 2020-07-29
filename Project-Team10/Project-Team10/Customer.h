#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include"Lib.h"
#include "AccountInfo.h"
class Customer: public AccountInfo
{
private:
	bool status = 0;
	vector<AccountInfo> listUser;
public:
	void loadListUser();
	void saveListUser();
	AccountInfo findUser(const int&);		//find another user by ID
	AccountInfo findUser(const string&);	//find another user by user name
};

#endif // !_CUSTOMER_H

