#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*��Combination Sum������Each number in C may only be used once in the combination.*/
vector<int> temp;
int sum = 0;
void dfs(vector<int>& candidates, int target, int index, vector<vector<int>>& result)
{
	if (sum>target)  //��֦
	{
		return;
	}
	else if (sum == target)
	{
		for (auto &c : temp)
		{
			cout << c << " ";
		}
		cout << endl;
		result.push_back(temp);
	}
	for (size_t j = index; j < candidates.size(); j++)
	{
		sum += candidates[j];
		temp.push_back(candidates[j]);
		dfs(candidates, target, j+1, result);
		temp.pop_back();     //����
		sum -= candidates[j];
		//index������ͬ������ͬ��Ԫ��
		while (j<candidates.size()-1 && candidates[j]==candidates[j+1])
		{
			++j;
		}
	}
}

int main()
{
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	vector<vector<int>> result;
	int target = 8;
	sort(candidates.begin(), candidates.end());
	for (auto &c : candidates)
	{
		cout << c << " ";
	}
	cout << endl;
	dfs(candidates, target, 0, result);
	system("pause");
	return 0;
}