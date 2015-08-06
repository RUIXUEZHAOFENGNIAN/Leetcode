#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//算法一，先排序,时间复杂度o(nlogn)
/*
int findMin(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	return nums.front();
}*/

//算法二：二分查找法，时间复杂度o(logn)
//4 5 6 7 0 1 2
int findMin(vector<int>& nums) {
	int left = 0;
	int right = nums.size()-1;
	int mid = 0;
	int ret = 0;
	while (left <= right)
	{
		if (left == right)  //只有一个元素
		{
			ret = nums[left];
			break;
		}
		if (left+1==right)  //只有两个元素
		{
			ret =  nums[left] >= nums[right] ? nums[right] : nums[left];
			break;
		}
		mid = (left + right) / 2;
		if (mid>0 && mid+1< nums.size() && nums[mid - 1] >= nums[mid] && nums[mid] <= nums[mid+1]  && nums[mid] <= nums[left])  //找到最小值
		{
			ret = nums[mid];
			break;
		}
		else if (nums[mid] > nums[right])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return ret;
}

int main()
{
	vector<int> nums1{ 4, 5, 6, 7, 0, 1, 2 };
	vector<int> nums2{1,2};
	vector<int> nums3{3,4,4,5,5,5,0,0,1};
	vector<int> nums4{1,2,3,4,5};
	vector<int> nums5{3,2,1};
	cout<<findMin(nums4)<<endl;
	system("pause");
	return 0;
}