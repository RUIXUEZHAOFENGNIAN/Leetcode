#include<iostream>
#include<vector>
using namespace std;

/*与Search in Rotated Sorted Array的区别是包含了重复元素*/

/*
//算法一，线性扫描，时间复杂度o(n)
bool search(vector<int>& nums, int target) {
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] == target)
		{
			return true;
		}
	}
	return false;
}*/

//算法二，
bool search(vector<int>& nums, int target) {
	int l = 0;
	int r = nums.size() - 1;
	int mid = 0;
	while (l<=r)
	{
		 mid = (l + r) / 2;
		 cout << "mid = " << mid << endl;
		 if (target == nums[mid])
		 {
			 return true;
		 }
		 if (nums[l] == nums[mid])
		 {
			 ++l;
		 }
		 else if (nums[r] == nums[mid])
		 {
			 --r;
		 }
		 else  if ((nums[mid]>= nums[l] && (target>nums[mid] || target<nums[l])) || (nums[mid] < nums[l] && target> nums[mid] && target<=nums[r]))
		 {
			 l = mid + 1;
			 cout <<"l = "<< l << endl;
		 }
		 else
		 {
			 r = mid - 1;
			 cout <<"r = "<< r << endl;
		 }
	}
	return false;
}

int main()
{
	vector<int> nums = {2,4,4,5,7,0,1};
	vector<int> nums1 = {1, 3, 1, 1, 1}; 
	if (search(nums,4))
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