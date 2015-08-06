#include<iostream>
#include<vector>
using namespace std;

/*�㷨һ����ٷ�  ʱ�临�Ӷ�O(nƽ��)*/
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

/*�㷨����Kadane�㷨/ɨ�跨  ʱ�临�Ӷ�O(n)*/
int maxSubArray(vector<int>& nums)
{
	int sum = 0;                             //���߳�ʼ��Ϊ  summ = INT_MIN ҲOK
	int max_sum = nums[0];                  //����һ��Ҫ��ֵmax_sum=INT_MIN���ߵ�һ��Ԫ�أ���������ȫ��Ϊ���������齫���� 
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (sum<=0)       //nums[i]֮ǰ��Ԫ�غ�С��0����������nums[i]��ʼ����
		{
			sum = nums[i];
		}
		else            //nums[i]֮ǰ��Ԫ�غʹ���0�����
		{
			sum += nums[i];
		}
		if (sum>max_sum)    //���µ�ǰ�����ֵ
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