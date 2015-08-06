#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> anagrams(vector<string>& strs) {
	map<string, int> m;
	vector<string> result;
	for (size_t i = 0; i < strs.size(); i++)
	{
		string temp = strs[i];
		sort(temp.begin(), temp.end());
		if (m.find(temp) == m.end())   //说明之前都没有同构词
		{
			m[temp] = i;
		}
		else
		{
			if (m[temp] >= 0)   
			{
				result.push_back(strs[m[temp]]);   //把第一个同构词加进来
				m[temp] = -1;
			}	
			result.push_back(strs[i]);
		}
	}
	return result;
}

int main()
{
	vector<string> strs = { "tea", "and", "ate", "eat", "dan" };
	vector<string> result = anagrams(strs);
	for (auto &c:result)
	{
		cout << c << endl;
	}
	system("pause");
	return 0;
}