#include<iostream>
#include<vector>
using namespace std;

int sum = 0;
vector<int> temp;
void dfs(int k,int n,int index,vector<vector<int>>& result)
{
	if (sum>n)
	{
		return;
	}
	if (k == 0 && sum == n)
	{
			result.push_back(temp);
			for (auto &c : temp)
			{
				cout << c << " ";
			}
			cout << endl;
	}
	for (size_t i = index;i <= 9; i++)
	{
		sum += i;
		temp.push_back(i);
		dfs(k-1,n,i+1,result);
		sum -= i;      //»ØË·
		temp.pop_back();
	}
}

int main()
{
	int k, n;
	vector<vector<int>> result;
	cin >> k >> n;
	dfs(k,n,1,result);
	system("pause");
	return 0;
}