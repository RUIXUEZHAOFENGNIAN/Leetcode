#include<iostream>
#include<vector>
using namespace std;

/*
//算法一：顺序查找，时间复杂度o(n)
int findPeakElement(vector<int>& nums) {
	if (nums.size()==1)
	{
		return 0;
	}
	if (nums.back()>nums[nums.size()-2])
	{
		return nums.size() - 1;
	}
	if (nums.size()==2)
	{
		return nums[0] > nums[1] ? 0 : 1;
	}
	for (size_t i = 1; i < nums.size()-1; i++)
	{
		if (nums[i]>nums[i-1] && nums[i] > nums[i+1])
		{
			return i;
		}
	}
}*/

//算法二：二分查找，时间复杂度o(logn)
int findPeakElement(vector<int>& nums) {
	int low = 0;
	int high = nums.size()-1;
	int mid = 0;
	while (low<high)
	{
		mid = (low + high) / 2;
		if (nums[mid]>nums[mid+1])
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return high;   
}

int main()
{
	vector<int> nums;
	int val;
	while (cin>>val)
	{
		nums.push_back(val);
	}
	cout << findPeakElement(nums) << endl;
	system("pause");
	return 0;
}