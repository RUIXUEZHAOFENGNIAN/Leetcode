#include<iostream>
#include<vector>
using namespace std;

//贪心算法
bool canJump(vector<int>& nums) {
	if (nums.size() < 2)
	{
		return true;
	}
	int target = nums.size() - 1;
	int start = 0;
	while (1)
	{
		for (size_t i = start; i<nums.size() && i <= start + nums[start]; i++)
		{
			if (start + nums[start] >= target)   //能跳到
			{
				return true;
			}
			if ((i + nums[i]) >(start + nums[start]))
			{
				start = i;
			}
		}
		start += nums[start];
		if (nums[start] == 0)
		{
			return false;
		}
	}
	return false;
}

int main()
{
	vector<int> nums1 = { 2, 3, 1, 1, 4 };
	vector<int> nums2 = { 3, 2, 1, 0, 4 };
	if (canJump(nums2))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}