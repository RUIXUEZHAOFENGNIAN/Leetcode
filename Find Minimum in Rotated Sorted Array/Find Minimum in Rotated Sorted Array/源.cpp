#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums) {
	if (nums.size() == 1)
	{
		return nums[0];
	}
	int end = nums.size() - 1;
	int start = 0;
	int mid = 0;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (mid>0 && nums[mid]<nums[mid-1] && mid+1<nums.size() && nums[mid]<nums[mid+1])
		{
			return nums[mid];
		}
		if (nums[mid] > nums[end])  //ÅÅ³ı×ó²à
		{
			start = mid + 1;
		}
		else if (nums[mid] < nums[end]) //ÅÅ³ıÓÒ²à
		{
			end = mid;
		}
	}
	return nums.front()>nums.back()?nums.back():nums.front();
}

int main()
{
	vector<int> nums1 = { 4, 5, 6, 7, 0, 1, 2 };
	vector<int> nums2 = { 2, 1 };
	vector<int> nums3 = {3,1,2};
	cout << findMin(nums3) << endl;;
	system("pause");
	return 0;
}