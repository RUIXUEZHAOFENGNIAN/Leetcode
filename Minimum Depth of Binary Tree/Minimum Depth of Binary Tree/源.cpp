#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){};
};

//前序遍历递归创建二叉树
void createBiTree(TreeNode* &root)
{
	int val;
	cin >> val;
	if (val == 0)
	{
		root = NULL;
	}
	else
	{
		root = (TreeNode*)malloc(sizeof(TreeNode));
		root->val = val;
		createBiTree(root->left);
		createBiTree(root->right);
	}
}

//前序递归遍历二叉树
void traversebiTree(TreeNode* root)
{
	if (root)
	{
		cout << root->val << " ";
		traversebiTree(root->left);
		traversebiTree(root->right);
	}
}

/*  //二叉树的最大深度
int depth = 1;
int max = 1;
void DFS(TreeNode* root)
{
	if (depth > max)
	{
		max = depth;
	}
	if (root->left)
	{
		++depth;
		DFS(root->left);
		--depth;
	}
	if (root->right)
	{
		++depth;
		DFS(root->right);
		--depth;
	}
}

int maxDepth(TreeNode* root)
{
	if (!root)  //空树
	{
		return 0;
	}
	DFS(root);
	return max;
}
*/

//二叉树的最小深度
int depth = 1;
int min = INT_MAX;
void DFS(TreeNode* root)
{
	if (depth < min && !root->left && !root->right)
	{
		min = depth;
	}
	if (root->left)
	{
		++depth;
		DFS(root->left);
		--depth;
	}
	if (root->right)
	{
		++depth;
		DFS(root->right);
		--depth;
	}
}

int minDepth(TreeNode* root)
{
	if (!root)  //空树
	{
		return 0;
	}
	DFS(root);
	return min;
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "前序遍历结果：";
	traversebiTree(T);
	cout << endl;
	//int result = maxDepth(T);
	int result = minDepth(T);
	cout << result <<endl;
	system("pause");
	return 0;
}