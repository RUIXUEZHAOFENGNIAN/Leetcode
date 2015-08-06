#include<iostream>
#include<vector>
using namespace std;

struct zero
{
	int row;
	int column;
	zero(int i, int j) :row(i),column(j){}
};

void setZeroes(vector<vector<int>>& matrix) {
	if (matrix.size()==0)
	{
		return;
	}
	vector<zero> z;
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == 0)
			{
				zero temp(i,j);
				z.push_back(temp);
			}
		}
	}
	for (size_t x = 0; x < z.size(); x++)
	{
		for (size_t j = 0; j < matrix[0].size(); j++)  //行设置为0
		{
			matrix[z[x].row][j] = 0;
		}
		for (size_t i = 0; i < matrix.size(); i++)  //行设置为0
		{
			matrix[i][z[x].column] = 0;
		}
	}
}

int main()
{
	vector<vector<int>> matrix = { { 1, 1, 1, 1 }, { 1, 1, 0, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 } };
	setZeroes(matrix);
	for (auto &c:matrix)
	{
		for (auto &c1:c)
		{
			cout << c1 << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}