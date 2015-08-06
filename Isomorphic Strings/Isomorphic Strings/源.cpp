#include<iostream>
#include<map>
#include<string>
using namespace std;

bool isIsomorphic(string s, string t) {
	if (s.length() != t.length())
	{
		return false;
	}
	map<char, char> m;
	for (auto it1 = s.begin(),it2 = t.begin(); it1!=s.end(),it2!=t.end(); it1++,it2++)
	{
		if (m.find(*it1) == m.end()) //不存在该键值对
		{
			m[*it1] = *it2;
		}
		else
		{
			if (*it2 != m[*it1])  //存在不同的键值对
			{
				return false;
			}
		}
	}
	m.clear();
	for (auto it1 = s.begin(), it2 = t.begin(); it1 != s.end(), it2 != t.end(); it1++, it2++)
	{
		if (m.find(*it2) == m.end()) //不存在该键值对
		{
			m[*it2] = *it1;
		}
		else
		{
			if (*it1 != m[*it2])  //存在不同的键值对
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	string s;
	cout << "请输入字符串s: ";
	cin >> s;
	string t;
	cout << "请输入字符串t: ";
	cin >> t;
	cout << s << endl;
	cout << t << endl;
	bool result = isIsomorphic(s,t);
	if (result)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	system("pause");
	return 0;
}