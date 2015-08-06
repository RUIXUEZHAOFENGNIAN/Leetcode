#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*
//算法一：分析----循环遍历直接判断范围内所有的数。时间复杂度o(n^2)  Time Limit Exceeded。
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

//算法二：分析----循环遍历直接判断根号n范围内的数。时间复杂度o(n^1.5)  Time Limit Exceeded。
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
//算法三：分析--用空间换时间，利用已有的素数来排除合数,时间复杂度估计还是o(n^2)级别的，超时。。。
vector<int> primeNum;
bool identify(int n)
{
	for (size_t i = 0; i < primeNum.size(); i++)
	{
		if (n%primeNum[i] == 0)  //说明是合数
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
//算法四：AC 啦啦啦
//分析---2是最小的质数，那么2的倍数均不为质数（因为它们可以分解为一个数*2），所以我们可以将小于n的数中2的倍数，全部排除掉
//排除掉2的整数倍后，剩下的数中大于2的最小的数就是下一个质数，也就是3
//同样我们可以排除掉小于n的数中3的整数倍的数，得到下一个质数为5.
int countPrimes(int n) {
	if (n<3)
	{
		return 0;
	}
	else
	{
		bool* a = new bool[n];
		memset(a,true,sizeof(bool)*n);
		for (size_t i = 2; i*i < n; i++)   //i的平方
		{
			if (a[i]) //说明i是素数
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