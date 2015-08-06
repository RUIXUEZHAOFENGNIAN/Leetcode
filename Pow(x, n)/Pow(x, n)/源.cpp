#include<iostream>
using namespace std;

//o(n)
double pPowDFS(double x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	return  x * pPowDFS(x, n - 1);
}
//o(logn)
double myPow(double x, int n) 
{
	if (n == 0 || x == 1 || (x == -1 && n % 2 == 0))
	{
		return 1.0;
	}
	if (x == -1 && n % 2 == 1) { return -1.0; }
	if (n==0)
	{
		return 1.0;
	}
    if (n<0)
	{
		return 1.0 / myPow(x, -n);
	}
	double half = myPow(x,n/2);
	if (n%2==0)
	{
		return half*half;
	}
	else
	{
		return half*half*x;
	}
}

int main()
{
	double x;
	int n;
	cout << "x = ";
	cin >> x;
	cout <<"n = ";
	cin >> n;
	double result = myPow(x,n);
	cout << result << endl;
	system("pause");
	return 0;
}