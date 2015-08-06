#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> result;
	if (nums.size() == 0)  return result;
	string temp;
	temp += to_string(nums[0]);
	int range = 1;
		for (size_t j = 1; j < nums.size(); j++)
		{
			if (nums[j]-nums[j-1] == 1)
			{
				if (j == nums.size()-1)
				{
					temp += "->";
					temp += to_string(nums.back());
				}
				++range;
			}
			else   //说明不再是连续
			{
				if (range>1)   //说明有连续的数
				{
					temp += "->";
					temp += to_string(nums[j - 1]);
				}
				result.push_back(temp);
				temp.clear();
				temp += to_string(nums[j]);
				range = 1;
			}
		}
	result.push_back(temp);
	return result;
}

void traverseVectorString(vector<string>& result)
{
	for (size_t i = 0; i < result.size(); i++)
	{
		for (auto &c:result[i])
		{
			cout << c;
		}
		cout << endl;
	}
}

int main()
{
	vector<int> nums;
	vector<string> result;
	int val;
	while (cin>>val)
	{
		nums.push_back(val);
	}
	result = summaryRanges(nums);
	traverseVectorString(result);
	system("pause");
	return 0;
}