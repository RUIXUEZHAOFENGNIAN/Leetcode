#include<iostream>
#include<vector>
using namespace std;

vector<int> temp;
void dfs(int k,int n,int index,vector<vector<int>>& result)
{
	if (k==0)
	{
		result.push_back(temp);
		for (auto &c:temp)
		{
			cout <<c<< " ";
		}
		cout << endl;
	}
	for (size_t i = index; i <=n; i++)
	{
		temp.push_back(i);
		dfs(k-1,n,i+1,result);
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