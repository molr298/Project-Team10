#include "Customer.h"

void Customer::buyStuff()
{
	Product::loadListProduct();
	string search;
	cout << "Enter ID or name to search: ";
	getline(cin, search);
	vector<Product> filterProduct;
	int flag = 0;
	for (int i = 0; i < prdv.size(); i++)
	{
		if (prdv[i].getID() == search || prdv[i].getProductName() == search) /////////Hàm tìm keyword sẽ review sau https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
		{
			flag = 1;
			filterProduct.push_back(prdv[i]);
		}
	}
	if (flag == 0)
	{
		cout << "Items not found" << endl;
		return;
	}
	///////Viết hàm display filterProduct trong đó có cho chọn theo thứ tự để thêm vào vector ordv (Order vector)

	////// Order vector tác động lại file Product.txt dựa vào các attribute của người mua sau đó gửi thông báo cho người bán


	int choice;
	while (true)
	{
		for (int i = 0; i < filterProduct.size(); i++)
		{
			cout << "Product " << i + 1 << endl;
			filterProduct[i].display();
			cout << "____________________________________" << endl;
		}
		cout << "Make your choice: ";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		int n;
		cout << "You choose this product" << endl;
		filterProduct[choice - 1].display();
		Product p;
		
		p = filterProduct[choice - 1];
		cout << "How many do you buy ?: ";
		cin >> n;
		
		ordv.push_back(filterProduct[choice - 1]);
	}
	Customer::viewCart();

}
void Customer::viewCart()
{
	if (ordv.size() == 0)
	{
		cout << "No items are currently on the list" << endl;
		return;
	}
	cout << "Review your shopping list" << endl;
	for (int i = 0; i < ordv.size(); i++)
	{
		cout << "Product " << i + 1 << endl;
		ordv[i].display();
		cout << "____________________________________" << endl;
	}
}