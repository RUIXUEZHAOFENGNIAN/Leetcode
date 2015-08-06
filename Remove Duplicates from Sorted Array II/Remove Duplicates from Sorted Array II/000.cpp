#include<iostream>
using namespace std;

int main()
{
	int A[] = {1,2,3,4,4,5};
	int n = 6;
	int sum = 0;
	int flag = 1;
	for (size_t i = 0; i < n && sum<n; i++)
	{
		
	    if (i + 1<n && A[i] == A[i + 1])
		{
			++flag;
			continue;
		}
		cout <<flag<< endl;
		if (flag >= 2)
		{
			A[sum++] = A[i];
			A[sum++] = A[i];
			flag = 1;
		}
		else
		    A[sum++] = A[i];
	}
	cout<< sum<<endl;
	for (size_t i = 0; i < sum; i++)
	{
		cout << A[i] << " ";
	}
	system("pause");
	return 0;
}