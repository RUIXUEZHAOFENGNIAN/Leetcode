#include<iostream>
#include<vector>
#include<string>
#include<iterator>
using namespace std;

int main()
{
	vector<string> v;
	vector<int> n(10);
	vector<int>::iterator it;
	string s;
	int num;
	for (int i = 0; i <= 9; i++)
	{
		n[i] = i+1;
	}
	/*while (cin >>num)
	{
		n.push_back(num);
		//it++;
	} */
	for (it=n.begin();it!=n.end();it++)
	{
		(*it) *= 2;
	}
	for (auto x:n)
	{
		cout << x<<" ";
	}
/*	while (getline(cin,s))
	{
		v.push_back(s);
	}
	for (auto it = v.cbegin(); it!=v.cend()&&!it->empty(); ++it)
	{
		cout << *it;
	}*/
	cout << endl;
	system("pause");
	return 0;
}