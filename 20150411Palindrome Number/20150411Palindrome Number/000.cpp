#include<iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	if (x<0)
	{
		cout << "���ǻ���" << endl;
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
			cout << "�ǻ���" << endl;
		}
		else
		{
			cout << "���ǻ���" << endl;
		}
	}
	system("pause");
	return 0;
}