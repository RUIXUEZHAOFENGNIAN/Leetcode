#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums) {
	size_t n = nums.size();
	if (n==0)
	{
		return 0;
	}
	if (n == 1)
	{
		return nums[0];
	}
	int best0 = nums[0];  //没偷这家
	int best1 = nums[0];  //偷了第一家
	for (size_t i = 2; i < n-1; i++)
	{
		int temp = best0;
		best0 = max(best1,temp);
		best1 = nums[i] + temp;
	}
	int sum1 = max(best0, best1);

	int bestAnother0 = 0;  //没偷这家
	int bestAnother1 = 0;  //没偷第一家
	for (size_t i = 1; i < n; i++)
	{
		int temp = bestAnother0;
		bestAnother0 = max(bestAnother1, temp);
		bestAnother1 = nums[i] + temp;
	}
	int sum2 = max(bestAnother0, bestAnother1);
	return max(sum1,sum2);
}

int main()
{
	vector<int> nums;
	int val;
	while (cin>>val)
	{
		nums.push_back(val);
	}
	cout << rob(nums) << endl;
	system("pause");
	return 0;
}