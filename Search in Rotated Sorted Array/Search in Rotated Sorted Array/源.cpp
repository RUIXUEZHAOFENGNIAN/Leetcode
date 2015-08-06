#include<iostream>
#include<vector>
using namespace std;

//算法二：二分查找，时间复杂度o(logn)
int search(vector<int>& nums, int target) {
	if (nums.size()==0)
	{
		return -1;
	}
	int l = 0;
	int r = nums.size() - 1;
	int mid = 0;
	while (l<=r)
	{
		mid = (l + r) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		if ( (nums[mid]>= nums[l] && (target>nums[mid] || target < nums[l])) || (nums[mid] <nums[l] && target>nums[mid] && target<=nums[r]))
		{
			l = mid + 1;
		}
		else 
		{
			r = mid - 1;
		}
	}
	return -1;
}

/*
//算法一：线性扫描，时间复杂度o(n),应该会超时,竟然过了，，过了。。
int search(vector<int>& nums, int target) {
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target)
		{
			return i;
		}
	}
	return -1;
}*/

int main()
{
	vector<int> nums1 = {4,5,6,7,0,1,2};
	cout << search(nums1,2) << endl;
	system("pause");
	return 0;
}