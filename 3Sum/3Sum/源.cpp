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
//�㷨һ
����������Ȼ���õ�һ��forѭ��ȷ����һ�����֡�
Ȼ���ڵڶ���ѭ����ڶ������������ֱַ���������м�ɨ��
�����������sum����0���õ�һ��⡣
�����������sumС��0��˵����Ҫ�������Եڶ����������ơ�
�����������sum����0��˵����Ҫ��С�����Ե������������ơ�
ʱ�临�Ӷȣ�O(n2)

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