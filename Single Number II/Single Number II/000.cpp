#include<iostream>
#include<unordered_map>
using namespace std;

/*
//��һ������һ����СΪ32���������洢�������ڸ�λ��1��Ȼ��ÿ��λ�ö���ģ
//��ģ��
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
ÿ��ѭ���ȼ��� twos�����������ε� 1 �ķֲ���Ȼ��������һ�ε� 1 �ķֲ������� ���߽���������õ��������ε� 1 ��
�ֲ������Ȼ��� threes ȡ�������� ones��twos�����������������Ŀ���ǽ����������ε�λ�����㡣
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