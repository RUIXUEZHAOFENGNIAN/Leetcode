#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

/*
//算法一：Edit Distance的子问题  stupid!!
int numDistinct(string s, string t) {
	unsigned lenS = s.size() + 1;
	unsigned lenT = t.size() + 1;
	vector<vector<int>> dp(lenS,vector<int>(lenT,0));
	//初始化，t为空时s删除
	for (size_t i = 0; i < lenS; i++)
	{
		dp[i][0] = i;
	}
	//初始化，s为空时s添加t中字符
	for (size_t j = 0; j < lenT; j++)
	{
		dp[0][j] = j;
	}
	for (size_t i = 1; i < lenS; i++)
	{
		for (size_t j = 1; j < lenT; j++)
		{
			if (s[i - 1] == t[j - 1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else   //only one choice,delete a character in string s
			{
				dp[i][j] = dp[i - 1][j] + 1;
			}

		}
	}
	return dp[lenS - 1][lenT - 1] + 1;
}*/

/*
//算法二：计算 t 中各字母在 s 的出现次数，乘积即为所求。结果 time error ╮(╯▽╰)╭
int numDistinct(string s, string t) {
    map<char,int> letterCount;
	unsigned pos1 = 0;
	unsigned pos2 = 0;
	unsigned ret = 1;
	unsigned num = 0;
	for (string::iterator it1 = t.begin(),it2 = t.begin()+1; it2 != t.end(); ++it1,++it2)
	{
		//cout << "*it1 = "<< *it1 << "  *it2 = "<< *it2 << endl;
		pos1 = s.find_first_of(*it1);
		s.erase(0,pos1);
		pos2 = s.find_first_of(*it2);
		cout << "pos1 = "<<pos1 << "  pos2 = "<< pos2 << endl;
		if (pos1 == string::npos || pos2 == string::npos)  //S中没有t中的某字符


		{
			return 0;
		}
		for (size_t pos = 0; pos != pos2; ++pos)  //在pos1和pos2中计算*it1的个数
		{
			if (s[pos] == *it1)
			{
				++letterCount[*it1];
				++num;
			}
		}
		ret *= num;
		cout << "num = " << num << endl;
		num = 0;
		cout << "the numbers of letter " << *it1 << ": " << letterCount[*it1] << endl;
		s.erase(0, pos2);
		cout << "s = " << s << endl;
	}
	//计算t最后一个字符在S中的的个数
	for (size_t i = 0; i != s.size(); i++)
	{
		if (s[i] == t.back())
		{
			++num;
			++letterCount[t.back()];
		}
	}
	cout << "num = "<< num << endl;
	ret *= num;
	cout << "the numbers of letter " << t.back() << ": " << letterCount[t.back()] << endl;
	return ret;
}*/

//算法三 还是得用动态规划，，fuck!
int numDistinct(string s, string t) {
	unsigned lenS = s.size() + 1;
	unsigned lenT = t.size() + 1;
	vector<vector<int>> dp(lenS,vector<int>(lenT,0));
	//初始化，当t为空时S只有全部删除这一方式
	for (size_t i = 0; i != lenS; i++)
	{
		dp[i][0] = 1;
	}
	//初始化，当s为空且t非空时为0
	for (size_t j = 1; j != lenT; j++)
	{
		dp[0][j] = 0;
	}
	for (size_t i = 1; i != lenS; i++)
	{
		for (size_t j = 1; j != lenT; j++)
		{
			if (s[i-1] == t[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i-1][j];  //保留或者抛弃
			}
			else
			{
				dp[i][j] = dp[i - 1][j];   //只能抛弃
			}
		}
	}
	return dp[lenS - 1][lenT - 1];
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout<< numDistinct(s1,s2) << endl;
	system("pause");
	return 0;
}