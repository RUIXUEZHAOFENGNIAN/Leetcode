#include<iostream>
#include<vector>
#include<string>
using namespace std;

void traverseVV(vector<vector<string>>& ret)
{
	for (size_t i = 0; i < ret.size(); i++)
	{
		for (auto& c:ret[i])
		{
			cout << c << "  ";
		}
		cout << endl;
	}
}

//判断分割出来的字符是否是回文
bool identifyPalindrome(string s)
{
	int start = 0;
	int end = s.length()-1;
	while (start<=end)
	{
		if (s[start] != s[end])
		{
			return false;
		}
		else
		{
			++start;
			--end;
		}
	}
	return true;
}

//DFS列出所有可能的分割情况
void partitionHelper(string s,vector<string> temp,vector<vector<string>>& ret)
{
	if (s.length() == 0)
	{
		ret.push_back(temp);
		return;
	}
	size_t len = s.length();
	for (size_t i = 1; i <= len; i++)
	{
		string subS = s.substr(0,i);
		if (identifyPalindrome(subS))
		{
			temp.push_back(subS);
			partitionHelper(s.substr(i, len - i), temp, ret);
			temp.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> ret;
	if (s.empty())
	{
		return ret;
	}
	vector<string> temp;
	partitionHelper(s,temp,ret);
	return ret;
}

int main()
{
	string s;
	cin >> s;
	vector<vector<string>> ret = partition(s);
	traverseVV(ret);
	system("pause");
	return 0;
}