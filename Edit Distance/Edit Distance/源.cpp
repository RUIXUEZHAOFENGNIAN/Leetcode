#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
// wrong! 768 / 1146 test cases passed.没考虑的顺序也要一致.
//a) Insert a character
//b) Delete a character
//c) Replace a character
//case:Input = "ab",Output = "bc" Expected = 2
int minDistance(string word1, string word2) {
	unsigned len1 = word1.size();
	unsigned len2 = word2.size();
	unsigned minLen = len1 > len2 ? len2 : len1;
	//the steps of insert a character or delete a character
	unsigned minStep = len1 > len2 ? len1 - len2 : len2 - len1;
	cout << "the steps of insert a character or delete a character: " << minStep << endl;
	unsigned tempLen = 0;
	for (auto it1 = word1.begin(); it1 != word1.end(); ++it1)
	{
		string::size_type pos2 = word2.find(*it1);
		if (pos2 != string::npos)
		{
			++tempLen;
			word2[pos2] = '#';
		}
	}
	cout << "tempLen = "<< tempLen << endl;
	minStep += (minLen - tempLen);
	return minStep;
}*/

// http: //blog.163.com/gjx_12358@126/blog/static/895363452014232191498/
void traverse(vector<vector<int>>& dis)
{
	for (auto& v:dis)
	{
		for (auto& c:v)
		{
			cout << c << " ";
		}
		cout << endl;
	}
}

int minNum(int l,int m,int r)
{
	int temp = l < m ? l : m;
	return temp < r ? temp : r;
}

int minDistance(string word1, string word2) {
	int len1 = word1.size() + 1;
	int len2 = word2.size() + 1;
	vector<vector<int>> dis(len1,vector<int>(len2,0));
	//初始化，当word1为空时，dis[0][j] = j,即逐个添加word2字母
	for (size_t j = 0; j < len2; j++)
	{
		dis[0][j] = j;
	}
	//初始化，当word2为空时，dis[i][0] = i,即逐个删除word1的字母
	for (size_t i = 0; i < len1; i++)
	{
		dis[i][0] = i;
	}
	for (size_t i = 1; i < len1; i++)
	{
		for (size_t j = 1; j < len2; j++)
		{
			if (word1[i-1] == word2[j-1])
			{
				dis[i][j] = dis[i-1][j-1];
			}
			else
			{
				cout << "temp = " << min(dis[i][j - 1] + 1, dis[i - 1][j - 1] + 1) << endl;
				dis[i][j] = min(dis[i - 1][j] + 1, min(dis[i][j - 1] + 1, dis[i - 1][j - 1] +  1));
			}
		}
	}
	traverse(dis);
	return dis[len1-1][len2-1];
}

int main()
{
	string word1, word2;
	cin >> word1 >> word2;
	cout << "minDistance = " << minDistance(word1, word2) << endl;
	system("pause");
	return 0;
}