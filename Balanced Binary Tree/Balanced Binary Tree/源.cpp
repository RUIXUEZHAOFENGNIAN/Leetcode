#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

void createBiTree(TreeNode* &T)
{
	int val;
	cin >> val;
	if (val == 0)
	{
		T = NULL;
	}
	else
	{
		T = (TreeNode*)malloc(sizeof(TreeNode));
		T->val = val;
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

int getDepth(TreeNode* T,int curDepth)
{
	if (!T)
	{
		return curDepth;
	}
	return max(getDepth(T->left, curDepth + 1), getDepth(T->right, curDepth + 1));
}

//计算了每颗树的平衡性
bool isBalanced(TreeNode* root) 
{
	if (!root)
	{
		return true;
	}
	int leftDepth = getDepth(root->left,0);
	int rightDepth = getDepth(root->right,0);
	cout << "leftDepth:" << leftDepth<< endl;
	cout << "rightDepth:" << rightDepth<<endl;
	if (abs(leftDepth - rightDepth) >1)
	{
		return false;
	}
	else
	{
		return isBalanced(root->left) && isBalanced(root->right);
	}
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "前序遍历：";
	traverse(T);
	cout << endl;
	bool result = isBalanced(T);
	if (result)
	{
		cout << "平衡" << endl;
	}
	else
	{
		cout << "不平衡" << endl;
	}
	system("pause");
	return 0;
}