#include<iostream>
#include<vector>
using namespace std;

/*
//算法一：使用除法
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
//算法二：不使用除法,用两个辅助空间
vector<int> productExceptSelf(vector<int>& nums) {
	if (nums.size()<2)
	{
		return nums;
	}
	vector<int> ret1(nums.size(),1);
	vector<int> ret2(nums.size(), 1);
	for (size_t i = 1; i < nums.size(); i++)  //某元素之前的乘积
	{
		ret1[i] = ret1[i-1]*nums[i-1];
	}
	for (size_t i = nums.size() - 2; i > 0; --i)  //某元素之后的乘积
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

//算法三：针对算法二的优化，不使用除法,用一个辅助空间
vector<int> productExceptSelf(vector<int>& nums) {
	if (nums.size()<2)
	{
		return nums;
	}
	vector<int> ret1(nums.size(), 1);
	for (size_t i = 1; i < nums.size(); i++)  //某元素之前的乘积
	{
		ret1[i] = ret1[i - 1] * nums[i - 1];
	}
	long long backProduct = 1;
	for (size_t i = nums.size() - 2; i > 0; --i)  //某元素之前的乘积与之后的乘积相乘即为所求
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