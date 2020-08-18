#ifndef _ADMIN_H
#define _ADMIN_H

#include"Lib.h"
#include "AccountInfo.h"
#include "Account.h"

class Admin: public AccountInfo/*, public ListAccount*/
{
private:
	vector<AccountInfo> listAdmin;

public:
	void loadListAdmin();
	void displayListAdmin();
	void editInfo();
	void removeUser(string);
	void saveUser();
};
#endif // !_ADMIN_H


