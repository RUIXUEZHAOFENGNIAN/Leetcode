#include<iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	if (x<0)
	{
		cout << "不是回文" << endl;
	}
	else
	{
		int temp0 = x;
		long long temp1 = 0;
		while (x)
		{
			temp1 = temp1*10 + x % 10;
			x /= 10;
		}
		if (temp1 == temp0)
		{
			cout << "是回文" << endl;
		}
		else
		{
			cout << "不是回文" << endl;
		}
	}
	system("pause");
	return 0;
}