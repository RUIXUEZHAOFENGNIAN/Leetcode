#include<iostream>
using namespace std;

int main()
{
	int A[] = {2,2,3,4,1,4,3};
	int n = 7;
	int x = 0;
	for (size_t i = 0; i < n; ++i)
		x ^= A[i];
	cout << x << endl;
	system("pause");
	return 0;
}