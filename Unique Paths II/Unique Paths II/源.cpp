#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> v(m,vector<int>(n,0));
	v[m/2][n/2] = 1;
	vector<vector<int>> buf(m, vector<int>(n, 0));
	if (m == 0 || n == 0)
		cout << "0" << endl;
	else if (m == 1 && n == 1)
		cout <<"1"<< endl;
	else
	{
		bool obstacleGridFoud = false;
		for (size_t i = 0; i < n; i++)
		{
			if (!obstacleGridFoud && v[0][i] == 0)
			{
				buf[0][i] = 1;
			}
			else
			{
				buf[0][i] = 0;
				obstacleGridFoud = true;
			}
		}
		obstacleGridFoud = false;
		for (size_t i = 0; i < m; i++)
		{
			if (!obstacleGridFoud && v[i][0] == 0)
			{
				buf[i][0] = 1;
			}
			else
			{
				buf[i][0] = 0;
				obstacleGridFoud = true;
			}
		}
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				cout << buf[i][j] << "  ";
			}
			cout << endl;
		}
		for (size_t i = 1; i < m; i++)
		{
			for (size_t j = 1; j < n; j++)
			{
				if (v[i][j]==1)
				{
					buf[i][j] = 0;
				}
				else
				{
					buf[i][j] = buf[i-1][j] + buf[i][j-1];
				}
			}
		}
		cout <<buf[m-1][n-1]<< endl;
	}
	system("pause");
}