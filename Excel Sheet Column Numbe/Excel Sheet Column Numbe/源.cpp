#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int titleToNumber(string s) {
	if (s.empty())
	{
		return 0;
	}
	int column = 0;
	int n = 0;
	for (size_t i = s.size()-1; i >0; i--)
	{
		column += (s[i] - 'A' + 1)*pow(26, n++);
	}
	column += (s[0] - 'A' + 1)*pow(26, n);
	return column;
}

int main()
{
	string s;
	cin >> s;
	cout<<titleToNumber(s)<<endl;
	system("pause");
	return 0;
}