#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
//��ʱ�㷨��ʱ�临�Ӷ�o(n)
bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		size_t temp = i + k;
		for (size_t j = i+1; temp < nums.size(),j <= temp; j++)
		{
			if (nums[i] == nums[j])
			{
				cout << i <<"  "<< j << endl;
				return true;
			}
		}
	}
	return false;
}
*/
//ӳ�䷨��ʱ�临�Ӷ�Ϊo(n)
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	map<int, int> buf;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (buf.find(nums[i]) != buf.end() && (i-buf[nums[i]]) <= k)
		{
			return true;
		}
		else
		{
			buf[nums[i]] = i;
		}
	}
	return false;
}

int main()
{
	vector<int> nums = {3,2,5,8,6,1,8,2,9,4,7};
	int k = 3;
	//vector<int> nums = { 99,99};
	//int k = 2;
	map<int, int> buf;
	for (size_t i = 0; i < nums.size(); i++)
	{
		buf[nums[i]] = i;
	}
	bool result = containsNearbyDuplicate(nums,k);
	if (result)
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "ľ��"<< endl;
	}
	system("pause");
	return 0;
}