#include<iostream>
using namespace std;

//λ�������ԣ�n&(n-1)��ȥ�����һ��1
bool isPowerOfTwo(int n) {
	//n = (unsigned int)n;
	if (n == 0)
	{
		return 0;
	}
	int temp = n&(n - 1);
	if (temp == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int n;
	cin >> n;
	if (isPowerOfTwo(n))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}