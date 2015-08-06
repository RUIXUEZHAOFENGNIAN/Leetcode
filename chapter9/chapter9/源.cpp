#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<string>
using namespace std;

//exercise 9.15
bool compareV(vector<int>& v1,vector<int>& v2)
{
	if (v1.size() != v2.size())
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < v1.size(); i++)
		{
			if (v1[i] != v2[i])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	//list<deque<int>> l1;
	//exercise 9.13
	//from list<int> transfer vector<double>
	list<int> l1(3,1);
	vector<double> v1(l1.begin(),l1.end());
	for (auto &c:l1)
	{
		cout << c << " ";
	}
	cout << endl;
	for (auto& c:v1)
	{
		cout << c << " ";
	}
	cout << endl;

	//exercise 9.14
	list<char*> l2 = { "asdfads","asdfds"};
	//vector<string> v2(l2.begin(),l2.end());
	vector<string> v2;
	v2.assign(l2.begin(),l2.end());
	for (const auto &s : v2)
	{
		cout << s << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}