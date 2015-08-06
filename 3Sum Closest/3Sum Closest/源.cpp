#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(),nums.end());
	int min_diff = INT_MAX;
	int sum = 0;
	int ret = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		int left = i+1;
		int right = nums.size() - 1;
		while (left<right)
		{
			sum = nums[left] + nums[right] + nums[i];
			if (target == sum) //差距值为0时直接返回结果
			{
				cout << "target = " << target << endl;
				return target;
			}
			else if (sum > target) //差距值大于0向左移动
			{
				--right;
			}
			else  //差距值小于0时向右移动
			{
				++left;
			}
			if (abs(target - sum) < min_diff)   //更新最小绝对差值
			{
				min_diff = abs(target - sum);
				ret = sum;
				sum = 0;                         //更新sum值
				cout << "min_diff = " << min_diff << " ret = " << ret << endl;
			}
		}
	}
	return ret;
}

int main()
{ 
	//vector<int> num1 = { -1,2,1,-4 };
	//int target1 = 1;
	vector<int> num2 = { 0, 0, 0, 0};
	int target2 = 1;
	cout << threeSumClosest(num2, target2) << endl;
	system("pause");
	return 0;
}