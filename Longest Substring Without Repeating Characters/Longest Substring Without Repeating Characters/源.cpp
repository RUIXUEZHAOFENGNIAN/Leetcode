#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

//"abcabcbb" is "abc
/*
//算法一
int lengthOfLongestSubstring(string s) {
	if (s.empty())
	{
		return 0;
	}
	map<char,int> mp;
	int maxLen = 0;
	for (size_t i = 0; i != s.size(); i++)
	{
		for (size_t j = i; j != s.size(); j++)
		{
			if (mp.find(s[j]) == mp.end())
			{
				mp[s[j]] = j;
			}
			else
			{
				cout << "mp.size() = "<< mp.size() << endl;
				if (mp.size() > maxLen)
				{
					maxLen = mp.size();
				}
				mp.clear();
				break;
			}
		}
	}
	if (mp.size() > maxLen)
	{
		maxLen = mp.size();
	}
	mp.clear();
	return maxLen;
}*/

//"abcabcbb" is "abc
//算法二   还是超时 ╮(╯▽╰)╭
/*
bool identifyRedundancy(const string& s)
{
	cout << "s = "<< s << endl;
	map<char, bool> mp;
	for (auto& c:s)
	{
		if (mp.find(c) == mp.end())
		{
			mp[c] = true;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int partionString(string s,int& length)
{
	if (length == 0)
	{	
		return 0;
	}
	size_t len = s.length();
	for (size_t i = 0; i+length <= len; i++)
	{
		if (identifyRedundancy(s.substr(i, length)))  //第一个肯定是最长的
		{
			cout << "wanted string = " << s.substr(i, length) << endl;
			return length ;
		}
		//cout << s.substr(i,length) << " ";
	}
	//cout << endl;
	return partionString(s,--length);
}

int lengthOfLongestSubstring(string s) {
	int max = 0;
	//vector<string> temp;
	int length = s.size();
	max = partionString(s,length);
	//traverseVV(ret);
	return max;
}*/

int lengthOfLongestSubstring(string& s) {
	map<char, size_t> mp;
	int lenMax = 0;
	int tempLen = 0;
	int left = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (mp.find(s[i]) != mp.end())  //之前已经出现过s[i],则从之前那个位置+1,继续遍历
		{
			if (tempLen>lenMax)
			{
				lenMax = tempLen;
			}
			left = mp[s[i]] > left ? mp[s[i]] : left;
			tempLen = i - left;
			cout << "tempLen = " << tempLen << endl;
			//map<char, size_t>::iterator it2 = mp.find(s[i]);
			//map<char, size_t>::iterator it1 = mp.begin();
			//mp.erase(it1,it2);
			mp[s[i]] = i;
			//cout << "map.size() = "<< mp.size() << endl;
		}
		else
		{
			mp[s[i]] = i;
			tempLen++;
		}
	}
	if (tempLen > lenMax)
	{
		cout << "flag tempLen = "<< tempLen << endl;
		lenMax = tempLen;
	}
	return lenMax;
}

int main()
{
	string s;
	cin >> s;
	cout<<lengthOfLongestSubstring(s)<<endl;
	system("pause");
    return 0;
}