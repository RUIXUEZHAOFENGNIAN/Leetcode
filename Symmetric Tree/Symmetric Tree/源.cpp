#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
};

//先序遍历创建二叉树
void createBiTree(TreeNode* &T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
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

//先序遍历二叉树
void preOrderBiTree(TreeNode* T, string &leftToRight)
{
	if (T)
	{
		cout << T->val << " ";
		leftToRight += T->val;
		preOrderBiTree(T->left, leftToRight);
		preOrderBiTree(T->right, leftToRight);
	}
	else
	{
		cout << "#"<<" ";
		leftToRight += "#";
	}
}

//先右再左地先序遍历二叉树
void preOrderBiTreeNew(TreeNode* T, string &rightToLeft)
{
	
	if (T)
	{
		cout << T->val << " ";
		rightToLeft += T->val;
		preOrderBiTreeNew(T->right, rightToLeft);
		preOrderBiTreeNew(T->left, rightToLeft);
	}
	else
	{
		cout << "#"<<" ";
		rightToLeft += "#";
	}
}

//判断二叉树是否对称
bool isSymmetric(TreeNode* root)
{
	string leftToRight;
	preOrderBiTree(root, leftToRight);
	string rightToLeft;
	preOrderBiTreeNew(root,rightToLeft);
	if (leftToRight.length() == rightToLeft.length())
	{
		int i = 0;
		while (i<leftToRight.length() && leftToRight[i] == rightToLeft[i])
		{
			i++;
		}
		if (i == leftToRight.length())
		{
			return true;
		}
		else
		{
			return false;
		}
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
	bool result = isSymmetric(T);
	if (result)
	{
		cout << "该二叉树对称" << endl;
	}
	else
	{
		cout << "该二叉树非对称" << endl;
	}
	system("pause");
	return 0;
}
