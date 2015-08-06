#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string convertToTitle(int n) {
	string ret;
	while (n)
	{
		int temp = n % 26;
		if (temp == 0)
		{
			ret += 'Z';
			n /= 26;
			n -= 1;       //½øÒ»Î»
		}
		else
		{
			ret += (char)(temp - 1 + 'A');
			n /= 26;
		}
	}
	reverse(ret.begin(),ret.end());
	return ret;
}

int main()
{
	//cout << (char)('A' + 1) << endl;
	int n;
	cin >> n;
	//string result;
	cout << convertToTitle(n) << endl;
	system("pause");
	return 0;
}