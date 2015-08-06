#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

//�㷨һ�������Ƚϣ�o(nlogn)
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

//�㷨���������Ƚϣ�o(n).��ô����ʱ����Ѫ������
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
		//��t�з�����s��δ���ֵ��ַ����߸��ַ���t�г��ֵĴ������ڴ���s�еģ���ֱ��false
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