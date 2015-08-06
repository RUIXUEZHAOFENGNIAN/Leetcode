#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums) {
	if (nums.size() == 0)
	{
		return 0;
	}
	int best0 = 0;  //��ʾû͵���
	int best1 = nums[0];  //��ʾ͵�����
	for (size_t i = 1; i < nums.size(); i++)
	{
		int temp = best0;
		best0 = max(best0,best1);
		best1 = temp + nums[i];
	}
	return max(best0,best1);
}

int main()
{
	vector<int> nums;
	int val;
	while (cin>>val)
	{
		nums.push_back(val);
	}
	int total = rob(nums);
	cout << total << endl;
	system("pause");
	return 0;
}