#include<iostream>
using namespace std;

int main()
{
	int elem = 5;
	int A[] = {1,2,5,5,6,7,8};
	int n = 7;
	int length=0;
	for (size_t i = 0; i < n; i++)
	{
		if (A[i] != elem)
		{
			A[length++] = 0;
		}
	}
	system("pause");
	return 0;
}