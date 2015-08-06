#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// 参考链接博文http://blog.csdn.net/yutianzuijin/article/details/16850031
void traverseVV(vector<vector<string>>& ret)
{
	for (size_t i = 0; i < ret.size(); i++)
	{
		for (auto& c : ret[i])
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
	int end = s.length() - 1;
	while (start <= end)
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

/*
//算法一：
//按照Palindrome Partitioning 的方法超时TLE

//DFS列出所有可能的分割情况
void partitionHelper(string s, int& min, int& numberCut)
{
	if (s.length() == 0)
	{
		if (numberCut < min)
		{
			cout << "number = "<< numberCut << endl;
			min = numberCut;
			numberCut = 0;
		}
		return;
	}
	size_t len = s.length();
	for (size_t i = 1; i <= len; i++)
	{
		string subS = s.substr(0, i);
		if (identifyPalindrome(subS) && numberCut<min)
		{
			++numberCut;
			partitionHelper(s.substr(i, len - i), min, numberCut);
		}
	}
}


int minCut(string s) {
	if (s.empty())
	{
		return 0;
	}
	int min = INT_MAX;
	int numberCut = 0;
	partitionHelper(s, min, numberCut);
	cout << "min = "<< min << endl;
	return min-1;
}

//从最长字符串开始分割
void partitionHelper(string s, vector<vector<string>>& ret,vector<string> temp)
{
	if (s.length() == 0)
	{
		ret.push_back(temp);
		return;
	}
	size_t len = s.length();
	for (size_t i = len; i >= 1; i--)
	{
		string subS = s.substr(0, i);
		if (identifyPalindrome(subS))
		{
			temp.push_back(subS);
			partitionHelper(s.substr(i, len - i), ret, temp);
			temp.pop_back();
		}
	}
}*/

/*
//对算法一的分析--解决重复子问题的方法主要有两种：备忘录或者DP
//算法二:时间复杂度o(n^2)  肿么还是TLE？！！fuck!!
void dfs(int& min,int i,int parts,int len,vector<vector<int>>& dp,vector<vector<int>> count)
{
	if (count[i][parts] == 1)   //对该类型（前i个元素的分割数为parts）的情况已考虑过
	{
		return;
	}
	if (i==len)     //对整个字符串都分割成回文子字符串了
	{
		if (parts<min)   //更新min值
		{
			min = parts;
		}
		return;
	}
	count[i][parts] = 1;
	for (size_t j = len-1; j != i-1; j--)
	{
		if (dp[i][j] == 1 && parts<min)
		{
			dfs(min, j + 1, parts + 1, len, dp, count);
		}
	}
}

int minCut(string s) {
	vector<int> temp(s.length(),0);
	vector<vector<int>> dp(s.length(),temp);
	//构造判断i到j是否为回文的dp数组
	for (size_t i = dp.size()-1; i != -1; --i)
	{
		for (size_t j = i; j < dp.size(); j++)
		{
			if (s[i] == s[j] && (j-i<2 || dp[i+1][j-1]==1))
			{
				dp[i][j] = 1;
			}
		}
	}
	vector<int> temp1(s.length()+1,0);
	vector<vector<int>> count(s.length()+1,temp1);
	int min = INT_MAX;
	dfs(min, 0, 0, s.length(), dp, count);
	return min-1;
}*/

//算法三---对算法二的改进，备忘录数组count[][]转换为一维的dp,count[i] = {1+count[j+1]},dp[i][j] = 1
//从i开始的字符串的最小划分为：如果从位置i到位置j的子串是回文串，则从i开始的划分可以通过将i到j的子串看作划
//分的一部分，然后加上从j + 1位置开始的子串最小划分，并选择可能情况中的最小值即为从i开始的最小划分
/*

int minCut(string s) {
	vector<int> temp(s.length(), 0);
	vector<vector<int>> dp(s.length(), temp);
	//构造判断i到j是否为回文的dp数组
	for (size_t i = s.size() - 1; i != -1; --i)
	{
		for (size_t j = i; j < s.size(); j++)
		{
			if (s[i] == s[j] && (j - i<2 || dp[i + 1][j - 1] == 1))
			{
				dp[i][j] = 1;
			}
		}
	}
	vector<int> count(s.length()+1,0);
	for (size_t i = s.length()-1; i != -1; i--)
	{
		count[i] = INT_MAX;
		for (size_t j = i; j < s.length(); j++)
		{
			if (dp[i][j] == 1)
			{
				count[i] = min(1+count[j+1],count[i]);
			}
		}
	}
	return count[0]-1;
}*/
//针对上述函数的优化
int minCut(string s) {
	vector<int> temp(s.length(), 0);
	vector<vector<int>> dp(s.length(), temp);
	vector<int> count(s.length() + 1, 0);
	//构造判断i到j是否为回文的dp数组
	for (size_t i = s.size() - 1; i != -1; --i)
	{
		count[i] = INT_MAX;
		for (size_t j = i; j < s.size(); j++)
		{
			if (s[i] == s[j] && (j - i<2 || dp[i + 1][j - 1] == 1))
			{
				dp[i][j] = 1;
				count[i] = min(1 + count[j + 1], count[i]);
			}
		}
	}
	return count[0] - 1;
}


int main()
{
	string s;
	vector<string> temp;
	vector<vector<string>> ret;
	cin >> s;
	//cout << s.substr(s.length(),0) << endl;
//	partitionHelper(s,ret,temp);
//	traverseVV(ret);
	/*
	if (identifyPalindrome(s))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}*/
	cout << minCut(s) << endl;
	system("pause");
	return 0;
}