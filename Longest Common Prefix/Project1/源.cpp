#include<iostream>
#include<vector>
#include<string>
using namespace std;

//			
string longestCommonPrefix(vector<string>& strs) 
{
	//
	int minLength = INT_MAX;
	for (size_t i = 0; i < strs.size(); i++)
	{
		if (strs[i].size() < minLength)
		{
			minLength = strs[i].size();
		}
	}
	cout << minLength << endl;
	string result;
	for (size_t i = 0; i < minLength; i++)
	{
		for (size_t j = 0; j < strs.size()-1; j++)
		{
			if (strs[j][i] != strs[j+1][i])
			{
				return result;
			}
		}
		result += strs[0][i];
	}
	return result;
}

void traverseVectorString(vector<string>& strs)
{
	for (size_t i = 0; i < strs.size(); i++)
	{
		for ( auto it = strs[i].begin(); it != strs[i].end(); it++)
		{
			cout << *it;
		}
		cout << endl;
	}
}

int main()
{
	vector<string> strs;
	char ch;
	string s;
	while (cin>>ch)
	{
		if (ch == '#')
		{
			strs.push_back(s);
			s.clear();
			continue;
		}
		s += ch;
	}
	traverseVectorString(strs);
	string result;
	result = longestCommonPrefix(strs);
	cout << result << endl;
	system("pause");
	return 0;
}