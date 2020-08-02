#ifndef _ADMIN_H
#define _ADMIN_H

#include"Lib.h"
#include "AccountInfo.h"

class Admin: public AccountInfo
{
private:
	vector<AccountInfo> listAdmin;
	vector<AccountInfo> listUser1;
public:
	void loadListAdmin();
	void displayListAdmin();
	void editInfo();
	void removeUser();
	void saveUser();
	void removeUserAlt();
};
#endif // !_ADMIN_H


