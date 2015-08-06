#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> findWords;
size_t index = 0;
int start = 0;
void dfs(const vector<vector<char>>& board,vector<vector<char>>& visited,const vector<string>& words,const int word_nums,int x,int y)
{
	
	if (word_nums < 0)  //都查找过所有单词了
	{
		return;
	}
	if (words[start].size() == index)     //收敛条件
	{
		cout << words[start]<< endl;
		//cout << x<<" "<<y<< endl;
		findWords.push_back(words[start]);
		//start++;
	}
	if (x<0 || x>=board.size() || y<0 || y>=board[x].size())  //越界
	{
		return;
	}
	if (visited[x][y] == '*')   //之前访问过
	{
		return;
	}
	if (words[start][index]!=board[x][y])  //当前字符不相等
	{
		return;
	}
	visited[x][y] = '*';
	++index;
	dfs(board, visited, words, word_nums, x, y + 1);   //向右
	dfs(board, visited, words, word_nums, x + 1, y);     //向下
	dfs(board, visited, words, word_nums, x - 1, y);    //向上
	dfs(board, visited, words, word_nums, x, y - 1);     //向左
	visited[x][y] = '#';//回朔
	--index;
}

int main()
{
	vector<string> words = { "eat", "oath", "pea", "rain" };
	vector<vector<char>> board = {{ 'o','a', 'a', 'n' },{ 'e', 't', 'a', 'e' },{ 'i', 'h', 'k', 'r' },{'i', 'f', 'l', 'v' } };
	int word_nums = words.size();
	size_t vertical = board.size();
	vector<vector<char>> visited = board;
	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board[i].size(); j++)
		{
			visited[i][j] = '#';  //#表示未访问
		}
	}
	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t  j = 0; j < board[i].size(); j++)
		{
			dfs(board, visited, words,word_nums, i, j);
		}

	}
	
	system("pause");
	return 0;
}