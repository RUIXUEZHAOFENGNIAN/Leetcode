#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

//算法一：排序后比较，o(nlogn)
/*
bool isAnagram(string s, string t) {
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	if (s == t)
	{
		return true;
	}
	else
	{
		return false;
	}
}*/

//算法二：排序后比较，o(n).怎么更耗时啊吐血。。。
bool isAnagram(string s, string t) {
	if (s.length() != t.length())
	{
		return false;
	}
	map<char, int>  mp1,mp2;
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (mp1.find(*it) == mp1.end())
		{
			mp1[*it] = 1;
		}
		else
		{
			++mp1[*it];
		}
	}
	for (string::iterator it = t.begin(); it != t.end(); it++)
	{
		//在t中发现有s中未出现的字符或者该字符在t中出现的次数大于大于s中的，则直接false
		if (mp1.find(*it) == mp1.end() || mp2.count(*it) > mp1.count(*it))
		{
			return false;
		}
		if (mp2.find(*it) == mp2.end())
		{
			mp2[*it] = 1;
		}
		else
		{
			++mp2[*it];
		}
	}
	if (mp1.size() != mp2.size())
	{
		return false;
	}
	else
	{
		for (auto it1 = mp1.begin(); it1 != mp1.end(); ++it1)
		{
			if (it1->second != mp2[it1->first] )
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	string s, t;
	cin >> s >> t;
	if (isAnagram(s,t))
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