#include<iostream>
#include<vector>
using namespace std;

/*  //���ѣ�ʱ�临�Ӷ�o(n)
int searchInsert(vector<int>& nums, int target) 
{
	if (nums.size() == 0)   //����Ϊ�յ����
	{
		return 0;
	}
	nums.push_back(INT_MAX);
	for (size_t i = 0; i < nums.size(); i++)
	{
		//�ҵ�target���߱�target���������Ϊ����λ��
		if (target <= nums[i])
		{
			return i;
		}
	}
}*/

//���ֲ��ҷ���ʱ�临�Ӷ�o(logn)  
//����ְ����벻ͨ����Ԫ��ֻ��һ�������----
int searchInsert(vector<int>& nums, int target)
{
	if (nums.size() == 0)   //����Ϊ�յ����
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
	cout << "������Ҫ���ҵ���"<<endl;
	int target;
	cin >> target;
	getchar();
	cout << "���������飺"<<endl;
	while (cin>>val)
	{
		nums.push_back(val);
	}
	int result = searchInsert(nums,target);
	cout << result << endl;
	system("pause");
	return 0;
}