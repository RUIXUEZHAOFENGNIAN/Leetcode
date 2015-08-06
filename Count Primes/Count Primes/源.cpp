#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*
//�㷨һ������----ѭ������ֱ���жϷ�Χ�����е�����ʱ�临�Ӷ�o(n^2)  Time Limit Exceeded��
bool identify(int n)
{
	for (size_t i = 2; i < n; i++)
	{
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}

int countPrimes(int n) {
	if (n<3)
	{
		return 0;
	}
	else if (n==3)
	{
		return 1;
	}
	else
	{
		int sum = 1;
		for (size_t i = 3; i < n; i++)
		{
			if (identify(i))
			{
				sum++;
			}
		}
		return sum;
	}
}*/

//�㷨��������----ѭ������ֱ���жϸ���n��Χ�ڵ�����ʱ�临�Ӷ�o(n^1.5)  Time Limit Exceeded��
bool identify(int n)
{
	for (size_t i = 2; i*i <= n; i++)
	{
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}

int countPrimes(int n) {
	if (n<3)
	{
		return 0;
	}
	else if (n==3)
	{
		return 1;
	}
	else
	{
		int sum = 1;
		for (size_t i = 3; i < n; i++)
		{
			if (identify(i))
			{
				sum++;
			}
		}
		return sum;
	}
}

/*
//�㷨��������--�ÿռ任ʱ�䣬�������е��������ų�����,ʱ�临�Ӷȹ��ƻ���o(n^2)����ģ���ʱ������
vector<int> primeNum;
bool identify(int n)
{
	for (size_t i = 0; i < primeNum.size(); i++)
	{
		if (n%primeNum[i] == 0)  //˵���Ǻ���
		{
			return false;
		}
	}
	return true;
}

int countPrimes(int n) {
	if (n<3)
	{
		return 0;
	}
	else if (n == 3)
	{
		return 1;
	}
	else
	{
		int sum = 1;
		primeNum.push_back(2);
		for (size_t i = 3; i < n; i++)
		{
			if (identify(i))
			{
				sum++;
				primeNum.push_back(i);
			}
		}
		return sum;
	}
}*/

/*
//�㷨�ģ�AC ������
//����---2����С����������ô2�ı�������Ϊ��������Ϊ���ǿ��Էֽ�Ϊһ����*2�����������ǿ��Խ�С��n������2�ı�����ȫ���ų���
//�ų���2����������ʣ�µ����д���2����С����������һ��������Ҳ����3
//ͬ�����ǿ����ų���С��n������3���������������õ���һ������Ϊ5.
int countPrimes(int n) {
	if (n<3)
	{
		return 0;
	}
	else
	{
		bool* a = new bool[n];
		memset(a,true,sizeof(bool)*n);
		for (size_t i = 2; i*i < n; i++)   //i��ƽ��
		{
			if (a[i]) //˵��i������
			{
				for (size_t j = 2; j*i < n; j++)
				{
					a[i*j] = false;
				}
			}
		}
		int cout = 0;
		for (size_t i = 2; i < n; i++)
		{
			if (a[i])
			{
				++cout;
			}
		}
		return cout;
	}
}*/

int main()
{
	int n;
	cin >> n;
	int result = countPrimes(n);
	cout << result << endl;
	system("pause");
	return 0;
}