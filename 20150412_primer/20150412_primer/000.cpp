#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> text;
	string s;
	while (cin >> s)
	{
		text.push_back(s);
	}
	for (auto n:text)
	{
		//cout << n << endl;
		for(auto u:n)
		{
			char c = toupper(u);
			cout << c;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}