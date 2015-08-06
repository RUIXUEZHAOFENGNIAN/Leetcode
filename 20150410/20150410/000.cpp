#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0, n = 0, i = 32;
	cin >> n;
	while (i--)
	{
		if (n % 2 == 1)
		{
			sum++;
			n = n / 2;
		}
		else
		{
			n = n / 2;
		}
	}
	cout << "Hamming weight = " << sum<<endl;
	system("pause");
	return 0;
}