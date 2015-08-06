#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

vector<string> result;
string temp;
map<char, string> m;
void dfs(string digits)
{
	int len = digits.size();
	if (len == 0)
	{
		result.push_back(temp);
		return;
	}
	if (len>0)
	{
		for (size_t j = 0; j < m[digits[0]].size(); j++)
		{
			temp += m[digits[0]][j];
			dfs(digits.substr(1,len-1));
			temp.pop_back();
		}
	}
}

vector<string> letterCombinations(string digits) {
	if (digits.length() == 0)
	{
		return result;
	}
	m['2'] = "abc";
	m['3'] = "def";
	m['4'] = "ghi";
	m['5'] = "jkl";
	m['6'] = "mmo";
	m['7'] = "pqrs";
	m['8'] = "tuv";
	m['9'] = "wxyz";
	dfs(digits);
	return result;
}

void traverse(vector<string>& result)
{
	for (size_t i = 0; i < result.size(); i++)
	{
		for (auto &c:result[i])
		{
			cout << c;
		}
		cout << endl;
	}
}

int main()
{
	string s;
	cin >> s;
	cout << s << endl;
	vector<string> result = letterCombinations(s);
	traverse(result);
	/*
	map<char, string> m;
	m['1'] = "abc";
	cout << m['1'] << endl;
	cout << m['1'].size() << endl;
	cout << m['1'][1] << endl;*/
	system("pause");
	return 0;
}