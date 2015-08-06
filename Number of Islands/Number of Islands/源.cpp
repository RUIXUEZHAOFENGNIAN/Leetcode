#include<iostream>
#include<vector>
using namespace std;

int m, n;
void DFS(vector<vector<char>>& grid,int i,int j)
{
	//边界条件控制
	if (j==n || i==m || j==-1 || i==-1)
	{
		return;
	}
	//把相邻的1（岛屿）赋值为0
	if (grid[i][j] == '1')
	{
		grid[i][j] = '#';
		DFS(grid, i, j + 1);
		DFS(grid, i + 1, j);
		DFS(grid, i, j - 1);
		DFS(grid, i - 1, j);
	}
}

int numIslands(vector<vector<char>>& grid) 
{
	m = grid.size();
	if (m==0)
	{
		return 0;
	}
	n = grid[0].size();
	int sum = 0;
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (grid[i][j] == '1')
			{
				++sum;
				DFS(grid, i, j);
			}
		}
	}
	return sum;
}

int main()
{
	/*
	vector<vector<char>> grid = { { '1', '1', '0', '0', '1' }, 
	                              { '1', '1', '0', '0', '0' }, 
	                              { '0', '0', '1', '0', '0' }, 
								  { '1', '0', '0', '1', '1' } };
	*/
	vector<vector<char>> grid = { { '1', '1', '1' },
	                              { '0', '0', '0' },
	                              { '1', '1', '1' } };
	int result;
	result = numIslands(grid);
	cout << result << endl;
	system("pause");
	return 0;
}