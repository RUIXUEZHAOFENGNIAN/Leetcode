#include<iostream>
#include<unordered_map>
using namespace std;

/*
//法一：利用一个大小为32的数组来存储所有数在该位的1，然后每个位置都求模
//求模法
int singleNumber(vector<int>& nums) 
{
	int bit[32] = { 0 };
	int result = 0;
	for (size_t i = 0; i < 32; i++)
	{
		for (size_t j = 0; j < nums.size(); j++)
		{
			bit[i] += (nums[j] >> i) & 1;
		}
	}
	for (size_t i = 0; i < 32; i++)
	{
		bit[i] %= 3;
	}
	for (size_t i = 0; i < 32; i++)
	{
		if (bit[i] == 1)
		{
			result += (1 << i); 
		}
	}
	cout << result<<endl;
	return result;
}*/

/*
每次循环先计算 twos，即出现两次的 1 的分布，然后计算出现一次的 1 的分布，接着 二者进行与操作得到出现三次的 1 的
分布情况，然后对 threes 取反，再与 ones、twos进行与操作，这样的目的是将出现了三次的位置清零。
*/
int singleNumber(vector<int>& nums)
{
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < nums.size(); i++){
		two |= one&nums[i];
		one ^= nums[i]; 
		three = one&two;
		one &= ~three;
		two &= ~three;
	}
	cout << one << endl;
	return one;
}

int main()
{
	vector<int> nums;
	int input;
	while (cin>>input)
	{
		nums.push_back(input);
	}
	singleNumber(nums);
	system("pause");
	return 0;
}