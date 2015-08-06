#include<iostream>
#include <limits>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	int temp = 0;
	while (n)
	{
		temp = n % 10;
		sum = sum * 10 + temp;
		n /= 10;
	}
	if (sum <= (numeric_limits<int>::max)() && sum >= (numeric_limits<int>::min)())
	{ 
	cout << sum << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	cout << (numeric_limits<int>::min)() << endl;
	system("pause");
	return 0;
}