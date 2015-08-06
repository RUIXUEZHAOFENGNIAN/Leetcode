#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
	for (size_t i = 1; i < nums.size(); i++)
	{
			if (nums[i-1] == nums[i])
			{
				return true;
			}
	}
}

int main()
{
	vector<int> nums = {1,2,3,4,5,8,9,6,1};
	sort(nums.begin(),nums.end());
	bool duplicate = containsDuplicate(nums);
	if (duplicate)
	{
		cout << "сп" << endl;
	}
	system("pause");
	return 0;
}