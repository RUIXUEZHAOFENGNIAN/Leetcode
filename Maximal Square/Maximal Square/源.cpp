#include<iostream>
#include<vector>
using namespace std;

int minNum(int num1,int num2,int num3)
{
	int temp = num1 > num2 ? num2 : num1;
	return temp > num3 ? num3 : temp;
}

//动规方程如下：if(dp(i,j))  dp(i,j) = min{dp(i-1,j-1),dp(i,j-1),dp(i-1,j)} + 1;
int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() == 0)
	{
		return 0;
	}
	vector<vector<int>> dp;
	vector<int> temp;
	//初始化dp数组
	for (size_t i = 0; i < matrix[0].size(); i++)
	{
		temp.push_back(0);
	}
	for (size_t i = 0; i < matrix.size(); i++)
	{
		dp.push_back(temp);
	}
	int ret = 0;  //正方形的边长
	for (size_t i = 0; i < dp.size(); i++)
	{
		for (size_t j = 0; j < dp[0].size(); j++)
		{
			dp[i][j] = matrix[i][j] - '0';
			if (i && j && dp[i][j])   //当前是1,带入动规方程
			{
				dp[i][j] = minNum(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1;
			}
			if (dp[i][j]>ret)
			{
				ret = dp[i][j];
			}
		}
	}
	return ret*ret;
}

int main()
{
	
	vector<vector<char>> matrix1 = { { '1', '0', '1', '0', '0'}, 
	                                 { '1', '0', '1', '1', '1'},
									 { '1', '1', '1', '1', '1'},
									 { '1', '0', '0', '1', '0'} };

	vector<vector<char>> matrix2 = { { '1', '1', '1', '0' },
	                                 { '1', '1', '0', '1' },
	                                 { '0', '1', '1', '1' },
	                                 { '1', '1', '1', '1' } };
	cout<<maximalSquare(matrix2)<<endl;
	system("pause");
	return 0;
}