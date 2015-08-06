#include<iostream>
using namespace std;

/*
//算法一:除余法
int hammingWeight(_Uint32t n) 
{
	int sum = 0;
	while (n)
	{
		if (n%2==1)
		{
			++sum;
		}
		n /= 2;
	}
	return sum;
}*/

/*
//算法二：位移法，逐个数
int hammingWeight(_Uint32t n)
{
	int sum = 0;
	while (n)
	{
		sum += n & 1;
		n = n >> 1;
	}
	return sum;
}*/

/*
//算法三：位操作，只统计位为一的情况（即消除一个一则统计加一）
int hammingWeight(_Uint32t n)
{
	int sum = 0;
	while (n)
	{
		n = n&(n - 1);
		sum++;
	}
	return sum;
}*/

//大神的算法 hamming weight算法
typedef unsigned __int32 uint32_t;
int hammingWeight(_Uint32t n)
{
	const uint32_t m1 = 0x55555555;   //周期2， 01010101010101010101010101010101
	const uint32_t m2 = 0x33333333;   //周期4， 00110011001100110011001100110011
	const uint32_t m4 = 0x0f0f0f0f;   //周期8， 00001111000011110000111100001111
	const uint32_t m8 = 0x00ff00ff;   //周期16，00000000111111111000000011111111
	const uint32_t m16 = 0x0000ffff;  //周期32，11111111111111111111111111111111
	n = (n&m1) + ((n >> 1) & m1);          //分成16个大小为2的单元分别进行统计
	n = (n&m2) + ((n >> 2) & m2);          //合并8个大小为4的单元分别进行统计
	n = (n&m4) + ((n >> 4) & m4);          //合并4个大小为8的单元分别进行统计
	n = (n&m8) + ((n >> 8) & m8);          //合并2个大小为16的单元分别进行统计
	n = (n&m16) + ((n >> 16) & m16);        //合并成2个大小为32的单元进行统计
	return n;
}

int main()
{
	uint32_t m;
	cin >> m;
	cout << "m = "<< m << endl;
	int result;
	result = hammingWeight(m);
	cout << "1的个数 = " <<result << endl;
	system("pause");
	return 0;
}