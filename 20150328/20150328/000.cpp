#include<iostream>
int main()
{
	int val = 0, curVal = 0;
	if (std::cin>>curVal)
	{
		int sum = 1;
		while (std::cin>>val)
		{
			if (val == curVal)
			{
				sum++;
			}
			else
			{
				std::cout << curVal << " occurs " <<sum<< " times"<<std::endl;
				curVal = val;
				sum = 1;
			}
		}
		std::cout << curVal << " occurs " << sum << " times" << std::endl;
	}
	system("pause");
}