#include<iostream>
int main()
{
	int v1 = 0, sum = 0;
	//std::cout << "Enter two numbers:" <<std::endl;
	//std::cin >> v1 >> v2;
	//int temp = v1;
	while (std::cin >> v1){
		sum += v1;
	}
	std::cout << "the sum is " << sum << std::endl;
	system("pause");
	return 0;
}