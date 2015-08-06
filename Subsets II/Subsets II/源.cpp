#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*与题目Subsets的区别是：Given a collection of integers that might contain duplicate，即考虑结果集中包括重复解的情况*/
vector<int> temp;
void dfs(vector<vector<int>>& result, int size, vector<int> nums, int index)
{
	int flag = true;
	for (size_t j = 0; j < result.size();j++)
	{
		if (result[j] == temp)
		{
			flag == false;
			return;
		}
	}
	if (flag)
	{
		result.push_back(temp);
		for (auto &c : temp)
		{
			cout << c << " ";
		}
		cout << endl;
	}
	for (size_t i = index; i < size; i++)
	{
		temp.push_back(nums[i]);
		dfs(result, size, nums, i + 1);
		temp.pop_back();
	}
}

int main()
{
	vector<int> nums = { 1, 2, 2 };
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	int size = nums.size();
	dfs(result, size, nums, 0);
	system("pause");
	return 0;
}