#include "Lib.h"
#include "AccountInfo.h"
#include "Admin.h"
#include"Customer.h"
class ListAccount
{
private:
	int adminNum;
	int userNum;
	vector<AccountInfo*> listAccountAdmin;
	vector<AccountInfo*> listAccountUser;

public:
	void loadListUserAccount();
	void loadListAdminAccount();
	void registerUserAccount();
};

