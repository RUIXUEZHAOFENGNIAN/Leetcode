#include<iostream>
using namespace std;

// 0000 0010 1001 0100 0001 1110 1001 1100
// 0011 1001 0111 1000 0010 1001 0100 0000

//算法一：在leetcode中提交能过
_Uint32t reverseBits(_Uint32t n) {
	_Uint32t ret = 0;
	for (size_t i = 0; i < 32; i++)
	{
		if (n)
		{
			ret <<= 1;
			ret =ret + n % 2;
			n >> 1;
			//cout << ret << endl;
		}
		else
		{
			ret <<= (32 - i);
			break;
		}
	}
	return ret;
}

/*
_Uint32t reverseBits(_Uint32t n) {
	int bitOfNums[32] = { 0 };
	int index = 0;
	while (n)
	{
		if (n % 2 == 1 && index < 32)
		{
			bitOfNums[index] = 1;
		}
		n /= 2;
		++index;
	}
	int i = 31;
	int q = 1;
	_Uint32t ret = 0;
	while (i>=0)
	{
		ret += bitOfNums[i]*q;
		q *= 2;
		--i;
	}
	return ret;
}*/

int main()
{
	_Uint32t n;
	cin >> n;
	cout << reverseBits(n) << endl;
	system("pause");
	return 0;
}