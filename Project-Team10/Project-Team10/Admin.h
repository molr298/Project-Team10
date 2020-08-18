#ifndef _ADMIN_H
#define _ADMIN_H

#include"Lib.h"
#include "AccountInfo.h"
#include "Account.h"
#include"Notification.h"
#include <string.h>
class Admin: public AccountInfo, public AdminNotif
{
private:
	vector<AccountInfo> listAdmin;

public:
	void loadListAdmin();
	void displayListAdmin();
	void editInfo();
	void removeUser(string);
	void saveUser();
	void sendReport(string senderID);
	void acceptSeller(string admin);
};
#endif // !_ADMIN_H


