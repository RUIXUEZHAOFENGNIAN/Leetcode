#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*方法一：时间复杂度为0(nlogn)*/
/*
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	//for (size_t i = m, j = 0; i < (m + n),j<n; i++,j++)   nums1[i] = nums2[j];  //leetcode中AC的写法,因为题目中nums1的初始长度不是m
	for (auto &c : nums2)
		nums1.push_back(c);
	sort(nums1.begin(),nums1.end());
}
*/
/*方法二，时间复杂度0(logn)，从后往前扫描的话nums1不需要往后移动元素*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = m + n - 1, j = m - 1, k = n - 1;
	while (j>=0 && k>=0)
	{
		nums1[i--] = nums1[j] >= nums2[k] ? nums1[j--] : nums2[k--];
	}
	while (k>=0)
	{
		nums1[i--] = nums2[k--];
	}
}

int main()
{
	vector<int> nums1(10);
	nums1 = { 1, 5, 9, 13, 0, 0, 0, 0, 0, 0};
	cout << nums1.size()<<endl;
	vector<int> nums2 = { 2, 6, 10, 15, 20, 36 };
	int m = 4;
	int n = nums2.size();
	merge(nums1,m,nums2,n);
	for (size_t i = 0; i < nums1.size(); i++)
	{
		cout << nums1[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}