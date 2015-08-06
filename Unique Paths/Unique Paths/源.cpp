#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> v(m,vector<int>(n));
	for (size_t i = 1; i < n; i++)
	{
		v[0][i] = 1;
	}
	for (size_t i = 1; i < m; i++)
	{
		v[i][0] = 1;
	}
	for (size_t i = 1; i < m; i++)
	{
		for (size_t j = 1; j < n; j++)
		{
			v[i][j] = v[i][j - 1] + v[i - 1][j];
		}
	}
	cout <<v[m-1][n-1]<< endl;
	system("pause");
}