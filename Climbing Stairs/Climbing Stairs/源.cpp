#include<iostream>
using namespace std;

int climbStairs(int n) {
	if (n < 1) return 0;
	int nowSteps;
	if (n==1)
	{
		return 1;
	}
	else if (n==2)
	{
		return 2;
	}
	else
	{
		int beforeTwoSteps = 1;
		int beforeOneSteps = 2;
		for (size_t i = 3; i <= n; i++)
		{
			nowSteps = beforeTwoSteps + beforeOneSteps;
			beforeTwoSteps = beforeOneSteps;
			beforeOneSteps = nowSteps;
		}
	}
	return nowSteps;
}

int main()
{
	int n;
	cin >> n;
	int result = climbStairs(n);
	cout << result << endl;
	system("pause");
	return 0;
}