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
				std::cout << "ISBN��" << currItem.isbn() << " ������"<<cout<<"����¼" << std::endl;
				currItem = itemValue;
				cout = 1;
			}
		}
		std::cout << "ISBN��" << currItem.isbn() << " ������" << cout << "����¼" << std::endl;
	}
	system("pause");
	return 0;
}