#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void quicksort(vector<int> candidates, int l, int r)
{
	if (l < r)
	{
		int i = l, j = r,temp=candidates[l];
		while (i<j)
		{
			while (candidates[j]>temp && j>i)  //从右边向前找到首个小于candidates[l]的值
			{
				j--;
			}
			candidates[i++] = candidates[j];
			while (candidates[i]>=temp && j>i)//从左边向后找到首个大于等于candidates[l]的值
			{
				i++;
			}
			candidates[j] = candidates[i];
		}
		candidates[i] = temp;
		quicksort(candidates,l,i-1);
		quicksort(candidates,i+1,r);
	}
}

int sum = 0;
vector<int> temp;
void dfs(vector<int> candidates, int index, int target, vector<vector<int>>& result)
{
	if (sum > target)
		return;
	if (sum == target && index<candidates.size())
	{
		for (auto &c : temp)
		{
			cout << c << " ";
		}
		cout << endl;
		result.push_back(temp);
	}
	for (size_t i = index; i < candidates.size(); i++)
	{
		sum += candidates[i];
		temp.push_back(candidates[i]);
		dfs(candidates, i, target, result);
		temp.pop_back();
		sum -= candidates[i];
	}
}
int main()
{
	int target = 11;
	vector<vector<int>> result;
	vector<int> candidates = { 8, 7, 4, 3};
	//int candidates[] = {5,2,3,2,6,7};
	//int length = sizeof(candidates) / sizeof(int);
   // quicksort(candidates,0,candidates.size()-1);
	sort(candidates.begin(),candidates.end());
	for (auto &c:candidates)
	{
		cout << c << " ";
	}
	cout << endl;
	//cout << length << endl;
	dfs(candidates,0,target,result);
	system("pause");
	return 0;
}



