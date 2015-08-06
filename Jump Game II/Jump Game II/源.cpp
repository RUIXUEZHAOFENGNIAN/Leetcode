#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& nums) {
	if (nums.size() < 2)
	{
		return 0;
	}
	int numberOfJumps = 1;
	int start = 0;
	while (1)
	{
		if (start + nums[start] >= nums.size()-1)
		{
			return numberOfJumps;
		}
		int temp = start;
			for (size_t j = start; nums.size()>j && j <= start + nums[start]; j++)
			{
				int max = temp + nums[temp];
				if (j + nums[j] > max)
				{
					
					max = j + nums[j];
					temp = j;
				}
			}
			start = temp;
			++numberOfJumps;
	}
}

int main()
{
	vector<int> nums1 = {2,3,1,1,4};
	vector<int> nums2 = {1, 2};
	vector<int> nums3 = { 5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0 };
	vector<int> nums4 = { 3, 4, 3, 1, 0, 7, 0, 3, 0, 2, 0, 3 };
	cout << jump(nums4) << endl;
	system("pause");
	return 0;
}