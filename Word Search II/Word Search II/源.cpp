#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> findWords;
size_t index = 0;
int start = 0;
void dfs(const vector<vector<char>>& board,vector<vector<char>>& visited,const vector<string>& words,const int word_nums,int x,int y)
{
	
	if (word_nums < 0)  //�����ҹ����е�����
	{
		return;
	}
	if (words[start].size() == index)     //��������
	{
		cout << words[start]<< endl;
		//cout << x<<" "<<y<< endl;
		findWords.push_back(words[start]);
		//start++;
	}
	if (x<0 || x>=board.size() || y<0 || y>=board[x].size())  //Խ��
	{
		return;
	}
	if (visited[x][y] == '*')   //֮ǰ���ʹ�
	{
		return;
	}
	if (words[start][index]!=board[x][y])  //��ǰ�ַ������
	{
		return;
	}
	visited[x][y] = '*';
	++index;
	dfs(board, visited, words, word_nums, x, y + 1);   //����
	dfs(board, visited, words, word_nums, x + 1, y);     //����
	dfs(board, visited, words, word_nums, x - 1, y);    //����
	dfs(board, visited, words, word_nums, x, y - 1);     //����
	visited[x][y] = '#';//��˷
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
			visited[i][j] = '#';  //#��ʾδ����
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