#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/*
For example, given array S = { -1 0 1 2 - 1 - 4 },
A solution set is :
(-1, 0, 1)
(-1, -1, 2)
*/

/*
//算法一
先升序排序，然后用第一重for循环确定第一个数字。
然后在第二重循环里，第二、第三个数字分别从两端往中间扫。
如果三个数的sum等于0，得到一组解。
如果三个数的sum小于0，说明需要增大，所以第二个数往右移。
如果三个数的sum大于0，说明需要减小，所以第三个数往左移。
时间复杂度：O(n2)

void traverseVV(vector<vector<int>>& result)
{
	for (size_t i = 0; i < result.size(); i++)
	{
		for (auto &c : result[i])
		{
			cout << c << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	vector<vector<int>> result;
	map<vector<int>, bool> mapping;
	for (size_t i = 0; i < nums.size() && nums[i]<=0; i++)
	{
		while (i>0 && nums[i] == nums[i-1])
		{
			++i;
		}
		int left = i + 1;
		int right = nums.size()-1;
		while (left < right)
		{
			int sum = nums[i] + nums[left] + nums[right];
			if (sum == 0)
			{
				vector<int> temp = { nums[i], nums[left], nums[right]};
				if (mapping.find(temp) == mapping.end())
				{
					result.push_back(temp);
					mapping[temp] = true;
				}
				++left;
				--right;
			}
			else if (sum < 0)
			{
				++left;
			}
			else
			{
				--right;
			}
		}
	}
	return result;
}*/

vector<vector<int>> threeSum(vector<int>& nums) {
{
	vector<vector<int>> result;
	return result;
}

int main()
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4};
	vector<vector<int>> result = threeSum(nums);
	traverseVV(result);
	system("pause");
	return 0;
}