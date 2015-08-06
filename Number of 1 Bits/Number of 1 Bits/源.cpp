#include<iostream>
using namespace std;

/*
//�㷨һ:���෨
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
//�㷨����λ�Ʒ��������
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
//�㷨����λ������ֻͳ��λΪһ�������������һ��һ��ͳ�Ƽ�һ��
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

//������㷨 hamming weight�㷨
typedef unsigned __int32 uint32_t;
int hammingWeight(_Uint32t n)
{
	const uint32_t m1 = 0x55555555;   //����2�� 01010101010101010101010101010101
	const uint32_t m2 = 0x33333333;   //����4�� 00110011001100110011001100110011
	const uint32_t m4 = 0x0f0f0f0f;   //����8�� 00001111000011110000111100001111
	const uint32_t m8 = 0x00ff00ff;   //����16��00000000111111111000000011111111
	const uint32_t m16 = 0x0000ffff;  //����32��11111111111111111111111111111111
	n = (n&m1) + ((n >> 1) & m1);          //�ֳ�16����СΪ2�ĵ�Ԫ�ֱ����ͳ��
	n = (n&m2) + ((n >> 2) & m2);          //�ϲ�8����СΪ4�ĵ�Ԫ�ֱ����ͳ��
	n = (n&m4) + ((n >> 4) & m4);          //�ϲ�4����СΪ8�ĵ�Ԫ�ֱ����ͳ��
	n = (n&m8) + ((n >> 8) & m8);          //�ϲ�2����СΪ16�ĵ�Ԫ�ֱ����ͳ��
	n = (n&m16) + ((n >> 16) & m16);        //�ϲ���2����СΪ32�ĵ�Ԫ����ͳ��
	return n;
}

int main()
{
	uint32_t m;
	cin >> m;
	cout << "m = "<< m << endl;
	int result;
	result = hammingWeight(m);
	cout << "1�ĸ��� = " <<result << endl;
	system("pause");
	return 0;
}