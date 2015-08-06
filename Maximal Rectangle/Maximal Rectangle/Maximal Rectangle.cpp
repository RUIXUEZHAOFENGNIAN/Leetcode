#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//算法一：转化为计算每行的直方图的最大面积
void traverseVV(vector<vector<char>>& matrix)
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

int LargestRectangleInHistogram(vector<char>& row)
{
	vector<int> histogram;
	for (vector<char>::iterator it = row.begin(); it != row.end(); it++)
	{
		histogram.push_back(*it-'0');
	}
	histogram.push_back(0);
	stack<int> stk;
	int i = 0;
	int maxArea = 0;
	while (i<histogram.size())
	{
		if (stk.empty() || histogram[i] >= histogram[stk.top()])
		{
			stk.push(i++);
		}
		else
		{
			int height = histogram[stk.top()];
			stk.pop();
			int curArea = height*(stk.empty()?i:i-stk.top()-1);
			if (curArea>maxArea)
			{
				maxArea = curArea;
			}
		}
	}
	return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	int maxRectangle = 0;
	for (size_t i = 0; i < matrix[0].size(); i++)  //列
	{
		for (size_t j = 1; j < matrix.size(); j++)  //行
		{
			if (matrix[j][i] == '1')
			{
				matrix[j][i] += matrix[j-1][i] - '0';
			}
		}
	}
	traverseVV(matrix);
	for (auto &c:matrix)
	{
		int temp = LargestRectangleInHistogram(c);
		if (temp > maxRectangle)
		{
			maxRectangle = temp;
		}
	}
	return maxRectangle;
}

int main()
{
	vector<vector<char>> matrix1 = { { '1', '0', '1', '0', '0' },
	                                { '1', '0', '1', '1', '1' },
	                                { '1', '1', '1', '1', '1' },
	                                { '1', '0', '0', '1', '0' } };
	vector<vector<char>> matrix2 = { { '0', '0', '0'},
	                                 { '0', '0', '0'},
	                                 { '1', '1', '1'} };
	cout<<maximalRectangle(matrix1)<<endl;
	system("pause");
	return 0;
}