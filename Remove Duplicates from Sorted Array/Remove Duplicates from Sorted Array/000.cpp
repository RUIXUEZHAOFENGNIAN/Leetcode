#include<iostream>
using namespace std;
#define n 10

int main()
{
	int A[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int sum = 0;
	for (size_t i = 0; i < n && sum<n; i++)
	{
		if (i+1<n && A[i] == A[i+1])
		{
			continue;
		}
		else
		{
			A[sum++] = A[i];
		}
	}
	for (size_t i = 0; i < sum; i++)
	{
		cout << A[i]<<"  ";
	}
	system("pause");
	return 0;
}