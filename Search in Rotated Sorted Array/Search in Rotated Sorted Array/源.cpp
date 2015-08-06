#include<iostream>
#include<vector>
using namespace std;

//�㷨�������ֲ��ң�ʱ�临�Ӷ�o(logn)
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
//�㷨һ������ɨ�裬ʱ�临�Ӷ�o(n),Ӧ�ûᳬʱ,��Ȼ���ˣ������ˡ���
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