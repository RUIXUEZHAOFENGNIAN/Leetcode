#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMinimum(vector<int>& temp)
{
	int min = INT_MAX;
	for (auto &c:temp)
	{
		if (c<min)
		{
			min = c;
		}
	}
	return min;
}

void triverseTriangle(vector<vector<int>>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.size() == 1)
	{
		return triangle[0][0];
	}
	for (size_t i = 1; i < triangle.size(); i++)
	{
		for (size_t j = 0; j < triangle[i].size(); j++)
		{
			if (j==0)
			{
				triangle[i][0] += triangle[i-1][0];
			}
			else if (j==triangle[i].size()-1)
			{
				int index = triangle[i].size() - 1;
				int indexBefore = triangle[i - 1].size() - 1;
				triangle[i][index] += triangle[i-1][indexBefore];
			}
			else
			{
				triangle[i][j] += min(triangle[i-1][j - 1], triangle[i-1][j]);
			}
		}
	}
	triverseTriangle(triangle);
	return findMinimum(triangle.back());
}

int main()
{
	vector<vector<int>> triangle1 = { {2}, {3,4}, {6,5,7}, {4,1,8,3} };
	vector<vector<int>> triangle2 = { { -1 }, { 2, 3 }, { 1, -1, -3 } };
	//cout<<minimumTotal(triangle1)<<endl;
	cout << minimumTotal(triangle2) << endl;
	system("pause");
	return 0;
}