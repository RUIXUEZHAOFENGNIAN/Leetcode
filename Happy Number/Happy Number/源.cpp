#include<iostream>
#include<map>
using namespace std;

int sum = 0;
map<int, int> m;
bool isHappy(int n) {
	if (m.find(n) != m.end())
	{
		return false;
	}
	m[n] = sum++;
	int next = 0;
	while (n)
	{
		next += (n%10)*(n%10);
		n /= 10;
	}
	if (next == 1)
	{
		return true;
	}
	isHappy(next);
}

int main()
{
	int n;
	cin >> n;
	bool result = isHappy(n);
	if (result)
	{
		cout<< "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	system("pause");
	return 0;
}