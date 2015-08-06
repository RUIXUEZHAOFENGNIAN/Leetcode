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
			if (target == sum) //���ֵΪ0ʱֱ�ӷ��ؽ��
			{
				cout << "target = " << target << endl;
				return target;
			}
			else if (sum > target) //���ֵ����0�����ƶ�
			{
				--right;
			}
			else  //���ֵС��0ʱ�����ƶ�
			{
				++left;
			}
			if (abs(target - sum) < min_diff)   //������С���Բ�ֵ
			{
				min_diff = abs(target - sum);
				ret = sum;
				sum = 0;                         //����sumֵ
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