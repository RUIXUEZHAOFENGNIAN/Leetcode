#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> result;
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			int toLeft = mid-1;
			int toRight = mid+1;
			while (toLeft>=0)
			{
				if (nums[toLeft] != target)
				{
					break;
				}
				else
				{
					--toLeft;
				}

			}
			while (toRight < nums.size())
			{
				if (nums[toRight] != target)
				{
					break;
				}
				else
				{
					++toRight;
				}
			}
			if (toRight - toLeft > 2)
			{
				result = { toLeft + 1, toRight-1};
			}
			else
			{
				result = {mid,mid};
			}
			return result;
			break;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	result = { -1, -1 };
	return result;
}

int main()
{
	vector<int> nums1 = { 5, 7, 7, 8, 8,8, 10 };
	vector<int> nums2 = { 2, 2, 2 };
	vector<int> nums3;
	vector<int> result = searchRange(nums3,2);
	for (auto &c : result)  cout << c << " ";
	system("pause");
	return 0;
}