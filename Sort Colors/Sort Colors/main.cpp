#include<iostream>
#include<vector>
using namespace std;

/*算法一： two-pass algorithm using counting sort.*/
/*
void sortColors(vector<int>& nums) 
{
	int num_0 = 0, num_1 = 0, num_2 = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			num_0++;
		}
	    if (nums[i] == 1)
		{
			num_1++;
		}
		if (nums[i] == 2)
		{
			num_2++;
		}
	}
	for (size_t i = 0; i < num_0; i++)
	{
		nums[i] = 0;
	}
	for (size_t i = num_0; i < (num_1+num_0); i++)
	{
		nums[i] = 1;
	}
	for (size_t i = (num_1 + num_0); i < nums.size(); i++)
	{
		nums[i] = 2;
	}
}
*/

/*算法二： one-pass algorithm using only constant固定的 space.*/
/*
void sortColors(vector<int>& nums)
{
	vector<int> temp = nums;
	int start = 0, end = nums.size()-1;
	cout << end << endl;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			temp[start++] = 0;
		}
		if (nums[i] == 2)
		{
			temp[end] = 2;
			end--;
		}
	}
	cout << end << endl;
	while (start<=end)
	{
		temp[start++] = 1;
	}
	nums = temp;
}
*/

/*算法三：平移插入*/
void sortColors(vector<int>& nums)
{
	int i = -1,j = -1,k = -1;
	for (size_t p = 0; p < nums.size(); p++)
	{
		if (nums[p] == 0)
		{
			nums[++k] = 2;
			nums[++j] = 1;
			nums[++i] = 0;
		}
		else if (nums[p] == 1)
		{
			nums[++k] = 2;
			nums[++j] = 1;
		}
		else
		{
			nums[++k] = 2;
		}
	}
}

int main()
{
	vector<int> nums = {2,2,1,0,1,0,2,1,1,0};
	sortColors(nums);
	for (auto &c:nums)
	{
		cout <<c<<" ";
	}
	system("pause");
	return 0;
}