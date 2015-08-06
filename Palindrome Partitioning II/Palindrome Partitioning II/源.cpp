#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// �ο����Ӳ���http://blog.csdn.net/yutianzuijin/article/details/16850031
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

//�жϷָ�������ַ��Ƿ��ǻ���
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
//�㷨һ��
//����Palindrome Partitioning �ķ�����ʱTLE

//DFS�г����п��ܵķָ����
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

//����ַ�����ʼ�ָ�
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
//���㷨һ�ķ���--����ظ�������ķ�����Ҫ�����֣�����¼����DP
//�㷨��:ʱ�临�Ӷ�o(n^2)  ��ô����TLE������fuck!!
void dfs(int& min,int i,int parts,int len,vector<vector<int>>& dp,vector<vector<int>> count)
{
	if (count[i][parts] == 1)   //�Ը����ͣ�ǰi��Ԫ�صķָ���Ϊparts��������ѿ��ǹ�
	{
		return;
	}
	if (i==len)     //�������ַ������ָ�ɻ������ַ�����
	{
		if (parts<min)   //����minֵ
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
	//�����ж�i��j�Ƿ�Ϊ���ĵ�dp����
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

//�㷨��---���㷨���ĸĽ�������¼����count[][]ת��Ϊһά��dp,count[i] = {1+count[j+1]},dp[i][j] = 1
//��i��ʼ���ַ�������С����Ϊ�������λ��i��λ��j���Ӵ��ǻ��Ĵ������i��ʼ�Ļ��ֿ���ͨ����i��j���Ӵ�������
//�ֵ�һ���֣�Ȼ����ϴ�j + 1λ�ÿ�ʼ���Ӵ���С���֣���ѡ���������е���Сֵ��Ϊ��i��ʼ����С����
/*

int minCut(string s) {
	vector<int> temp(s.length(), 0);
	vector<vector<int>> dp(s.length(), temp);
	//�����ж�i��j�Ƿ�Ϊ���ĵ�dp����
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
//��������������Ż�
int minCut(string s) {
	vector<int> temp(s.length(), 0);
	vector<vector<int>> dp(s.length(), temp);
	vector<int> count(s.length() + 1, 0);
	//�����ж�i��j�Ƿ�Ϊ���ĵ�dp����
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