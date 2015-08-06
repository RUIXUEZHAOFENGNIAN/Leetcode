#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	if (grid.size() == 0)
	{
		return 0;
	}
	size_t m = grid.size();
	size_t n = grid[0].size();
	//得到最上侧和最左测的情况
	for (size_t i = 1; i < n; i++)
	{
		grid[0][i] += grid[0][i-1];
	}
	for (size_t i = 1; i < m; i++)
	{
		grid[i][0] += grid[i-1][0];
	}
	for (size_t i = 1; i < m; i++)
	{
		for (size_t j = 1; j < n; j++)
		{
			grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
		}
	}
	return grid[m-1][n-1];
}

int main()
{
	vector<vector<int>> grid1 = { {5,4,7,2},
	                             {3,7,1,9},
								 {0,4,3,2},
								 {8,3,2,7} };
	vector<vector<int>> grid2 = { { 5, 4, 7, 2 } };
	cout << minPathSum(grid1) << endl;
	system("pause");
	return 0;
}