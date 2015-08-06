#include<iostream>
#include<vector>
using namespace std;

//算法一：暴力破解--果断超时
/*
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (auto &c: matrix[i])
		{
			if (c == target)
			{
				return true;
			}
		}
	}
	return false;
}*/

//算法二：针对算法一的改进版本1
bool binarySearch(const vector<int>& rowElement,const int len,const int& target)
{
	int left = 0;
	int right = len - 1;
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (rowElement[mid] == target)
		{
			return true;
		}
		else if (rowElement[mid]>target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0)
	{
		return false;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	for (size_t i = 0; i < matrix.size(); i++)
	{
		if (matrix[i][0] <= target && target<=matrix[i][col-1])
		{
			if (binarySearch(matrix[i], col, target))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	vector<vector<int>> matrix{ { 1, 4, 7, 11, 15 }, 
	                            { 2, 5, 8, 12, 19 }, 
								{ 3, 6, 9, 16, 22 }, 
								{ 10, 13, 14, 17, 24}, 
								{ 18, 21, 23, 26, 30} 
	                          };
	int target;
	cout << "please input target:";
	cin >> target;
	if (searchMatrix(matrix,target))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}
