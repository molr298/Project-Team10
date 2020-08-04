#ifndef _ADMIN_H
#define _ADMIN_H

#include"Lib.h"
#include "AccountInfo.h"

class Admin: public AccountInfo
{
private:
	vector<AccountInfo> listAdmin;

public:
	void loadListAdmin();
	void displayListAdmin();
	void editInfo();
	void removeUser();
	void saveUser();
};
#endif // !_ADMIN_H


