#include<iostream>
#include<vector>
using namespace std;

void addElement(vector<vector<int>>& matrix, vector<int>& ret, int rowLeftTop, int colLeftTop, int rowRightBottom, int colRightBottom)
{
	if (colLeftTop == colRightBottom)  //只有一列的情况
	{
		for (size_t i = rowLeftTop; i <= rowRightBottom; i++)
		{
			ret.push_back(matrix[i][rowLeftTop]);
		}
	}
	else if (rowLeftTop == rowRightBottom)     //只有一行的情况
	{
		for (size_t i = colLeftTop; i <= colRightBottom; i++)
		{
			ret.push_back(matrix[rowLeftTop][i]);
		}
	}
	else
	{
		for (size_t i = colLeftTop; i <= colRightBottom; i++)   //上面一行
		{
			ret.push_back(matrix[rowLeftTop][i]);
		}
		for (size_t i = rowLeftTop + 1; i <= rowRightBottom; i++)   //右边一列
		{
			ret.push_back(matrix[i][colRightBottom]);
		}
		for (size_t i = colRightBottom - 1; i > colLeftTop; i--)   //下面一行
		{
			ret.push_back(matrix[rowRightBottom][i]);
		}
		for (size_t i = rowRightBottom; i >rowLeftTop; i--)   //左边一列
		{
			ret.push_back(matrix[i][colLeftTop]);
		}
	}
}


vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ret;
	if (matrix.size() == 0)  //空的情况
	{
		return ret;
	}
	int rowLeftTop = 0;
	int colLeftTop = 0;
	int rowRightBottom = matrix.size() - 1;
	int colRightBottom = matrix[0].size() - 1;
	while (rowLeftTop <= rowRightBottom && colLeftTop <= colRightBottom)
	{
		addElement(matrix, ret,rowLeftTop, colLeftTop, rowRightBottom, colRightBottom);
		++rowLeftTop;
		++colLeftTop;
		--rowRightBottom;
		--colRightBottom;
	}
	return ret;
}

int main()
{
	vector<vector<int>> matrix1 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	vector<vector<int>> matrix2 = { { 1, 2, 3, 4 }, {5, 6, 7, 8 }, { 9, 10, 11, 12} };
	vector<vector<int>> matrix3 = { { 1 } };
	vector<vector<int>> matrix4 = { { 3 }, { 2 } };
	vector<int> result = spiralOrder(matrix4);
	for (auto &c:result)
	{
		cout << c << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}