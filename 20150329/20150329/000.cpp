#include<iostream>
#include"Sales_item.h"
int main()
{
	Sales_item currItem,itemValue;
	if (std::cin>>currItem)
	{
		int cout = 1;
		while (std::cin >> itemValue)
		{
			if (currItem.isbn() == itemValue.isbn())
			{
				cout++;
			}
			else
			{
				std::cout << "ISBN是" << currItem.isbn() << " 的书有"<<cout<<"条记录" << std::endl;
				currItem = itemValue;
				cout = 1;
			}
		}
		std::cout << "ISBN是" << currItem.isbn() << " 的书有" << cout << "条记录" << std::endl;
	}
	system("pause");
	return 0;
}