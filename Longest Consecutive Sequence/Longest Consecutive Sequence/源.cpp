#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�㷨һ ʹ��unique����
/*
int longestConsecutive(vector<int>& nums) {
	if (nums.empty())
	{
		return 0;
	}
	sort(nums.begin(),nums.end());
	//���ظ�Ԫ���Ƶ�ĩβ
	auto end_uinque = unique(nums.begin(),nums.end());
	unsigned maxLenght = 1;
	unsigned tempLenght = 1;
	for (vector<int>::iterator pre = nums.begin(), it = nums.begin() + 1; it != end_uinque; ++it, ++pre)
	{
		//���µ�ǰtemplenghtֵ()
		tempLenght = (*it - *pre) <= 1 ? tempLenght + 1 : 1;
		//���µ�ǰ��󳤶�
		maxLenght = tempLenght > maxLenght ? tempLenght : maxLenght;
	}
	return maxLenght;
}*/

//��ʹ��unique
int longestConsecutive(vector<int>& nums) {
	if (nums.empty())
	{
		return 0;
	}
	sort(nums.begin(), nums.end());
	unsigned maxLenght = 1;
	unsigned tempLenght = 1;
	for (vector<int>::iterator pre = nums.begin(), it = nums.begin() + 1; it != nums.end(); ++it, ++pre)
	{
		if (*it == *pre) continue;
		//���µ�ǰtemplenghtֵ()
		tempLenght = (*it - *pre) == 1 ? tempLenght + 1 : 1;
		//���µ�ǰ��󳤶�
		maxLenght = tempLenght > maxLenght ? tempLenght : maxLenght;
	}
	return maxLenght;
}

int main()
{
	vector<int> nums{100, 4, 200, 1, 3, 2,5,101,102,103,104,105,106,107};
	vector<int> nums1{ 1, 2, 0, 1 };
	cout<< longestConsecutive(nums1) <<endl;
	system("pause");
	return 0;
}