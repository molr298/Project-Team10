#include "Seller.h"
void Seller::approveCart(bool approveOrder, string IDseller)
{
	if (approveOrder)
	{
		Product prd;
		prd.saveNotifUser(IDseller);
	}
	else return;
}