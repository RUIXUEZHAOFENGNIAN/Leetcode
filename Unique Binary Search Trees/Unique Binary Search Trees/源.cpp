#include<iostream>
#include<vector>
using namespace std;

/*从处理子问题的角度来看，选取一个结点为根，就把结点切成左右子树，以这个结点为根的可行二叉树
数量就是左右子树可行二叉树数量的乘积，所以总的数量是将以所有结点为根的可行结果累加起来*/
int numTrees(int n) 
{
	if (n==0 || n==1)
	{
		return 1;
	}
	else
	{
		vector<int> temp;
		temp.push_back(1);
		temp.push_back(1);
		for (size_t i = 2; i <= n; i++)
		{
			int a = 0;
			for (size_t j = 0; j < i; j++)
			{
				a += (temp[j] * temp[i-j-1]);
			}
			temp.push_back(a);
		}
		return temp.back();
	}
}

int main()
{
	int n;
	cin >> n;
	int result = numTrees(n);
	cout << result << endl;
	system("pause");
	return 0;
}