#include<iostream>
#include<map>
#include<vector>
using namespace std;

//≈–∂œ
bool identify(vector<char> temp)
{
	map<int, char> m;
	for (size_t i = 0; i < temp.size(); i++)
	{
		if (temp[i] != '.')
		{
			if (m.find(temp[i]) != m.end())
			{
				return false;
			}
			m[temp[i]] = i;
		}
	}
	return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
	//≈–∂œ––
	//≈–∂œ¡–
	vector<char> tempColumn;
	vector<char> tempRow;
	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board.size(); j++)
		{
			tempRow.push_back(board[i][j]);
			tempColumn.push_back(board[j][i]);
		}
		if (!identify(tempRow) || !identify(tempColumn))    
		{
			return false;
		}
		tempRow.clear();
		tempColumn.clear();
	}
	//≈–∂œ◊”æ≈π¨∏Ò
	// Blocks
	vector<char> nineGrid;
	for (size_t i = 3; i <= board.size(); i += 3)
	{
		for (size_t j = 3; j <= board.size(); j += 3)
		{
			for (size_t y = i - 3; y < i; y++)
			{
				for (size_t x = j - 3; x < j; x++)
				{
					nineGrid.push_back(board[y][x]);
				}
			}
			if (!identify(nineGrid))
			{
				return false;
			}
			nineGrid.clear();
		}
	}
	return true;
}

/*  //À„∑®∂˛
bool isValidSudoku(vector<vector<char> > &board) {
	// Note: The Solution object is instantiated only once.
	int row[9], col[9];

	for (int i = 0; i < 9; i++)
	{
		memset(row, 0, sizeof(int) * 9);
		memset(col, 0, sizeof(int) * 9);
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				if (row[board[i][j] - '1'] > 0)return false;
				else row[board[i][j] - '1']++;
			}
			if (board[j][i] != '.')
			{
				if (col[board[j][i] - '1'] > 0)return false;
				else col[board[j][i] - '1']++;
			}
		}
	}

	for (int i = 0; i < 9; i += 3)
		for (int j = 0; j < 9; j += 3)
		{
			memset(row, 0, sizeof(int) * 9);
			for (int a = 0; a < 3; a++)
				for (int b = 0; b < 3; b++)
					if (board[i + a][j + b] != '.')
					{
						if (row[board[i + a][j + b] - '1']>0)return false;
						else row[board[i + a][j + b] - '1']++;
					}
		}
	return true;
}*/

int main()
{
	vector<vector<char>> board = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
	                               { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
								   { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
								   { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
								   { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
								   { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
								   { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
								   { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
								   { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	                              };
	vector<vector<char>> board1 = { { '.', '.', '4', '.', '.', '.', '6', '3', '.' },
	                                { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
	                                { '5', '.', '.', '.', '.', '.', '.', '9', '.' },
	                                { '.', '.', '.', '4', '5', '.', '.', '.', '.' },
	                                { '4', '.', '3', '.', '.', '.', '.', '.', '1' },
	                                { '.', '.', '.', '7', '.', '.', '.', '.', '.' },
	                                { '.', '.', '.', '5', '.', '.', '.', '.', '.' },
	                                { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
	                                { '.', '.', '.', '.', '.', '.', '.', '.', '.' }
	                              };
	vector<vector<char>> board2 = { { '.', '8', '7', '6', '5', '4', '3', '2', '1' },
	                                { '2', '.', '.', '.', '.', '.', '.', '.', '.' },
	                                { '3', '.', '.', '.', '.', '.', '.', '.', '.' },
	                                { '4', '.', '.', '.', '.', '.', '.', '.', '.' },
	                                { '5', '.', '.', '.', '.', '.', '.', '.', '.' },
	                                { '6', '.', '.', '.', '.', '.', '.', '.', '.' },
	                                { '7', '.', '.', '.', '.', '.', '.', '.', '.' },
	                                { '8', '.', '.', '.', '.', '.', '.', '.', '.' },
	                                { '9', '.', '.', '.', '.', '.', '.', '.', '.' }
	                              };
	bool result = isValidSudoku(board2);
	if (result)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}