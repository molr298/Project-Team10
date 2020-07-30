#ifndef _ADMIN_H
#define _ADMIN_H

#include"Lib.h"
#include "AccountInfo.h"

class Admin: public AccountInfo
{
private:

public:
	void viewDataOfUser();
	void editInfo();
	void removeUser();
};
#endif // !_ADMIN_H


