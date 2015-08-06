#include<iostream>
#include<vector>
using namespace std;

/*  //暴搜，时间复杂度o(n)
int searchInsert(vector<int>& nums, int target) 
{
	if (nums.size() == 0)   //数组为空的情况
	{
		return 0;
	}
	nums.push_back(INT_MAX);
	for (size_t i = 0; i < nums.size(); i++)
	{
		//找到target或者比target大的数，即为所求位置
		if (target <= nums[i])
		{
			return i;
		}
	}
}*/

//二分查找法，时间复杂度o(logn)  
//好奇怪啊，想不通数组元素只有一个的情况----
int searchInsert(vector<int>& nums, int target)
{
	if (nums.size() == 0)   //数组为空的情况
	{
		return 0;
	}
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (target <= nums[mid] && mid>0 && target>nums[mid-1])
		{
			cout << nums[mid] <<endl;
			return mid;
		}
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			left = mid+1;
			cout << "left = "<< left << endl;
		}
		else
		{
			right = mid-1;
			cout << "right = " << right << endl;
		}
	}
	//return nums.size();
}

int main()
{
	int val;
	vector<int> nums;
	cout << "请输入要查找的数"<<endl;
	int target;
	cin >> target;
	getchar();
	cout << "请输入数组："<<endl;
	while (cin>>val)
	{
		nums.push_back(val);
	}
	int result = searchInsert(nums,target);
	cout << result << endl;
	system("pause");
	return 0;
}