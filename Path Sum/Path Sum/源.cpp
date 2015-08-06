#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

void createBiTree(TreeNode* &T)
{
	int ch;
	cin >> ch;
	if (ch == 0)
	{
		T = NULL;
	}
	else
	{
		T = (TreeNode*)malloc(sizeof(TreeNode));
		T->val = ch;
		createBiTree(T->left);
		createBiTree(T->right);
	}
}

void traverse(TreeNode* T)
{
	if (T)
	{
		cout << T->val << " ";
		traverse(T->left);
		traverse(T->right);
	}
}

int curSum = 0;
int flag = 0;
void dfs(TreeNode* root, int sum)
{
	cout << "curSum:" << curSum << endl;
	traverse(root);
	cout << endl;
	if (root!=NULL)
	{
		curSum += root->val;
		cout << "curSum:" << curSum << endl;
		if (curSum == sum &&root->left == NULL &&root->right == NULL)
		{
			flag = 1;
			cout << "flag:" << flag << endl;
			return;
		}
		dfs(root->left,sum);
		if (root->left)
		{
			curSum -= root->left->val;
		}
		dfs(root->right,sum);
		if (root->right)
		{
			curSum -= root->right->val;
		}
	}
}

bool hasPathSum(TreeNode* root, int sum) 
{
	dfs(root, sum);
	cout << "root:" << root->val << endl;
	cout << flag << endl;
	if (flag)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	//traverse(T);
	bool result = hasPathSum(T, 1);
	if (result)
	{
		cout << "has the path>--YES" << endl;
	}
	else
	{
		cout << "has the path ? --NO" << endl;
	}
	system("pause");
	return 0;
}