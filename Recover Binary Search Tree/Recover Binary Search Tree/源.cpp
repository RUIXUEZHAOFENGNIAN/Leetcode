#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//先序创建二叉树
void createBiTree(TreeNode* &T)
{
	int val;
	cin >> val;
	if (val!=00)
	{
		T = new TreeNode(val);
		createBiTree(T->left);
		createBiTree(T->right);
	}
	else
	{
		T = NULL;
	}
}

//中序遍历二叉树
void InorderTraverse(TreeNode* T)
{
	if (T)
	{
		InorderTraverse(T->left);
		cout << T->val << " ";
		InorderTraverse(T->right);
	}
}

void getInorderTraverse(TreeNode* T, vector<int>& vi)
{
	if (T)
	{
		getInorderTraverse(T->left, vi);
		vi.push_back(T->val);
		getInorderTraverse(T->right, vi);
	}
}

void putInorderTraverse(TreeNode* T, vector<int>& vi)
{
	if (T)
	{
		putInorderTraverse(T->left, vi);
		T->val = vi.front();
		vi.erase(vi.begin());
		putInorderTraverse(T->right, vi);
	}
}

//算法一：空间复杂度o(n)
/*
void recoverTree(TreeNode* root) {
	int numBefore = INT_MIN;
	vector<int> vi;
	getInorderTraverse(root, vi);
	sort(vi.begin(),vi.end());
	putInorderTraverse(root, vi);
}*/

//算法二：空间复杂度o(n)
void recoverTree(TreeNode* root) {
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "Before recover: ";
	InorderTraverse(T);
	cout << endl;
	recoverTree(T);
	cout << "After recover: ";
	InorderTraverse(T);
	system("pause");
	return 0;
}