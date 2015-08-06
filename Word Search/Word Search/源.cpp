#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int index,int i, int j)
{
	if (index == word.size())
	{
		return true;
	}
	if (i >= board.size() || i < 0||j >= board[i].size() || j < 0) //越界
	{
		return false;
	}
	if (word[index] != board[i][j])  //不相等
	{
		return false;
	}
	if (visited[i][j] == true)  //已经访问过
	{
		return false;
	}
	visited[i][j] = true;
	bool temp = dfs(board, visited, word, index+1, i, j + 1) //向右扩展
		|| dfs(board, visited, word, index + 1, i + 1, j) //向下扩展
		|| dfs(board, visited, word, index + 1, i, j - 1) //向左扩展
		|| dfs(board, visited, word, index + 1, i - 1, j); //向上扩展
	visited[i][j] = false;
	return temp;
}

int main()
{
	string word="ABCESEEDAS";
	vector<vector<char>> board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D','E','E'} };
	vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[i].size(); j++)
		{
			if (dfs(board, visited, word, 0, i, j))
			{
				    cout << "find it" << endl;
					break;
			}
		}
	}
	system("pause");
	return 0;
}