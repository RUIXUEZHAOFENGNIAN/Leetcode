#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//算法一：先排序,时间复杂度o(nlogn)
int findKthLargest(vector<int>& nums, int k) {
	sort(nums.begin(),nums.end());
	return *(nums.end() - k);
	/*
	for (size_t i = nums.size() - 1; i>0; i--)
	{
		if (k==1)
		{
			return nums[i];
		}
		if (nums[i] != nums[i-1])
		{
			--k;
		}
	}*/
	//return nums[0];
}

int main()
{
	vector<int> nums1 = { 3, 2, 1, 5, 6, 4 };
	vector<int> nums2 = { -1, -1};
	cout << findKthLargest(nums1,6) << endl;
	//cout << findKthLargest(nums2, 2) << endl;
	system("pause");
	return 0;
}