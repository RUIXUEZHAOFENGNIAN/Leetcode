#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int numRows;
	vector<vector<int>> sum;
	cin >> numRows;

		for (size_t i = 0; i < numRows; i++)
		{
			vector<int> temp;
			for (size_t j = 0; j <= i; j++)
			{
				if (j == 0 || j == i)
				{
					temp.push_back(1);
				}
				else
				{
					temp.push_back(sum[i - 1][j-1] + sum[i - 1][j]);
				}
				
			}
			sum.push_back(temp);
		}
	for (size_t i = 0; i < numRows; i++)
	{
		for (size_t j = 0; j < sum[i].size(); j++)
		{
			cout << sum[i][j]<< " ";
		}
		cout << endl;
	}
	system("pause");
}