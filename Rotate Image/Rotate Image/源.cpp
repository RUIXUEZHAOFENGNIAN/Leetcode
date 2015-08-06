#include<iostream>
#include<vector>
using namespace std;

//算法一：另开一空间向量
void rotate(vector<vector<int>>& matrix) 
{
	if (matrix.size() == 0)
	{
		return;
	}
	vector<vector<int>> temp = matrix;
	
	for (size_t i = 0; i < matrix.size(); i++)
	{
		size_t row = temp[0].size() - 1 - i;
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			temp[j][row] = matrix[i][j];
		}
	}
	matrix = temp;
}

void traverseVectorVector(vector<vector<int>>& matrix)
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<int>> matrix = { { 1, 2, 3, 4 },
	                               { 5, 6, 7, 8 },
	                               { 9, 10, 11, 12 },
	                              { 13, 14, 15, 16 } };
	rotate(matrix);
	traverseVectorVector(matrix);
	system("pause");
	return 0;
}