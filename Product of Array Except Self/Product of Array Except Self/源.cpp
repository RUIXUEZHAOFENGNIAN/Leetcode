#include<iostream>
#include<vector>
using namespace std;

/*
//�㷨һ��ʹ�ó���
vector<int> productExceptSelf(vector<int>& nums) {
	long long product = 1;
	for (auto& c:nums)
	{
		product *= c;
	}
	vector<int> result;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] != 0)
		{
			result.push_back(product / nums[i]);
		}
		else
		{
			long long temp = 1;
			for (size_t j = 0; j < nums.size(); j++)
			{
				if (temp == 0)
				{
					break;
				}
				if (j != i)
				{
					temp *= nums[j];
				}
			}
			result.push_back(temp);
		}
	}
	for (auto& c : result)
	{
		cout<<c<<" ";
	}
	return result;
}*/

/*
//�㷨������ʹ�ó���,�����������ռ�
vector<int> productExceptSelf(vector<int>& nums) {
	if (nums.size()<2)
	{
		return nums;
	}
	vector<int> ret1(nums.size(),1);
	vector<int> ret2(nums.size(), 1);
	for (size_t i = 1; i < nums.size(); i++)  //ĳԪ��֮ǰ�ĳ˻�
	{
		ret1[i] = ret1[i-1]*nums[i-1];
	}
	for (size_t i = nums.size() - 2; i > 0; --i)  //ĳԪ��֮��ĳ˻�
	{
		ret2[i] *= ret2[i + 1] * nums[i + 1];
	}
	ret2[0] = ret2[1] * nums[1];
	for (size_t i = 0; i < ret1.size(); i++)
	{
		ret1[i] *= ret2[i];
	}
	return ret1;
}*/

//�㷨��������㷨�����Ż�����ʹ�ó���,��һ�������ռ�
vector<int> productExceptSelf(vector<int>& nums) {
	if (nums.size()<2)
	{
		return nums;
	}
	vector<int> ret1(nums.size(), 1);
	for (size_t i = 1; i < nums.size(); i++)  //ĳԪ��֮ǰ�ĳ˻�
	{
		ret1[i] = ret1[i - 1] * nums[i - 1];
	}
	long long backProduct = 1;
	for (size_t i = nums.size() - 2; i > 0; --i)  //ĳԪ��֮ǰ�ĳ˻���֮��ĳ˻���˼�Ϊ����
	{
		backProduct *= nums[i + 1];
		ret1[i] *= backProduct;
	}
	ret1[0] = backProduct*nums[1];
	for (auto& c : ret1)
	{
		cout << c << " ";
	}
	return ret1;
}

int main()
{
	vector<int> nums = { 1, 2, 3, 4 };
	vector<int> nums1 = { 1, 0 };
	vector<int> nums2 = { 0, 0 };
	productExceptSelf(nums);
	system("pause");
	return 0;
}