#include<iostream>
using namespace std;

struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
};

void createBiTree(TreeNode* &T)
{
	char ch = getchar();
	if (ch=='#')
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
		cout << T->val <<" ";
		traverse(T->left);
		traverse(T->right);
	}
}

bool isSameTree(TreeNode* p, TreeNode* q) 
{
	if (!p && !q)  return true;
	else if (p == NULL&&q != NULL || p != NULL&& q == NULL)
	{
		return false;
	}
	else if ( p->val != q->val)
	{
		return false;
	}
	else
	{
		return 	isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
}

int main()
{
	TreeNode* T1;
	TreeNode* T2;
	createBiTree(T1);
	traverse(T1);
	cout << endl;
	getchar();
	createBiTree(T2);
	traverse(T2);
	cout << endl;
	bool result = isSameTree(T1,T2);
	if (result)
	{
		cout << "两树相等"<< endl;
	}
	else
	{
		cout << "两树不相等" << endl;
	}
	system("pause");
	return 0;
}