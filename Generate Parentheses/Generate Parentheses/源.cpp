#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*思路：当左括号出现次数< n 时，就可以放置新的左括号。当右括号出现次数小于左括号出现次数时，就可以放置新的右括号。*/
void generateParenthesis(vector<string>&result, int n, string temp,int left, int right)  //注意是引用
{
	if (left==n && right==n)   //剪枝
	{
		result.push_back(temp);
		return;
	}
	if (left < n)
	{
		temp += "(";
		generateParenthesis(result, n,temp,left+1, right);
		temp.pop_back();   //回溯
	} 
	if (right < left)
	{
		temp += ")";
		generateParenthesis(result, n,temp,left, right+1);
		temp.pop_back();
	}
}

int main()
{
	int n;
	vector<string> result;
	int left = 0, right = 0;
	string temp;
	cin >> n;
	generateParenthesis(result,n,temp,left,right);
	for (size_t i = 0; i < result.size();i++)
	{
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}