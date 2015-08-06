#include<iostream>
#include<vector>
using namespace std;
/*方法一*
/*
int main()
{
	int rowIndex;
	vector<vector<int>> sum;
	cin >> rowIndex;
	for (size_t i = 0; i <= rowIndex; i++)
	{
		vector<int> temp;
		for (size_t j = 0; j <=i; j++)
		{
			if (j==0 || j==i)
			{
				temp.push_back(1);
			}
			else
			{
				temp.push_back(sum[i-1][j-1]+sum[i-1][j]);
			}
		}
		sum.push_back(temp);
	}
	for (size_t j = 0; j < sum[rowIndex].size();)
	{
		cout <<sum[rowIndex][j++]<< " ";
	}
	system("pause");
}
*/

/*方法二：辅助空间o(k)*/
int main()
{
	int rowIndex = 3;
	vector<int> temp;
	for (size_t i = 0; i < rowIndex+1; i++)
	{
		temp.push_back(0);
	}
	temp[rowIndex] = 1;
	temp[0] = 1;
	for (size_t i = 0; i < rowIndex; i++)
	{	
		for (size_t j = rowIndex-1; j >0; j--)
		{
			temp[j] = temp[j] + temp[j - 1];
		}	
	}
	for (const auto c:temp)
	{
		cout << c << " ";
	}
	system("pause");
}

