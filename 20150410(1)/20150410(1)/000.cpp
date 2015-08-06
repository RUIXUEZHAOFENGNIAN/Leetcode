#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	int n;
	vector<int> v;
	while (cin>>n)
	{
		v.push_back(n);
	}
	for (auto c:v)
	{
		cout << c << endl;
	}
	//ut << s << endl;
	system("pause");
	return 0;
}