#include<iostream>
#include<vector>
using namespace std;

/*算法一：穷举法  时间复杂度O(n平方)*/
/*
int maxSubArray(vector<int>& nums)
{
	int max = nums[0];
	for (size_t i = 0; i < nums.size(); i++)
	{
		int sum = 0;
		for (size_t j = i; j < nums.size(); j++)
		{
			sum += nums[j];
			if (sum>max)
			{
				max = sum;
			}
		}
	}
	return max;
}
*/

/*算法二：Kadane算法/扫描法  时间复杂度O(n)*/
int maxSubArray(vector<int>& nums)
{
	int sum = 0;                             //或者初始化为  summ = INT_MIN 也OK
	int max_sum = nums[0];                  //这里一定要赋值max_sum=INT_MIN或者第一个元素，否则遇到全部为负数的数组将出错 
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (sum<=0)       //nums[i]之前的元素和小于0则舍弃，从nums[i]开始计算
		{
			sum = nums[i];
		}
		else            //nums[i]之前的元素和大于0则相加
		{
			sum += nums[i];
		}
		if (sum>max_sum)    //更新当前的最大值
		{
			max_sum = sum;
		}
	}
	return max_sum;
}

int main()
{
	vector<int> nums = {-2,1,-3, 4,-1,2, 1,-5,4};
	cout << maxSubArray(nums) << endl;
	system("pause");
	return 0;
}