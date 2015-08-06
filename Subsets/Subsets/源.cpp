#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> temp;
void dfs(vector<vector<int>>& result,int size,vector<int> nums,int index)
{
	int flag = true;
	for (auto &c : result)
	{
		if (c==temp)
		{
			flag == false;
		}
	}
	if (flag)
	{
		result.push_back(temp);
		for (auto &c:temp)
		{
			cout << c << " ";
		}
		cout << endl;
	}
	for (size_t i = index; i < size; i++)
	{
		temp.push_back(nums[i]);
		dfs(result,size,nums,i+1);
		temp.pop_back();
	}
}

int main()
{
	vector<int> nums = {1,2,3};
	sort(nums.begin(),nums.end());
	vector<vector<int>> result;
	int size = nums.size();
	dfs(result,size,nums,0);
	system("pause");
	return 0;
}