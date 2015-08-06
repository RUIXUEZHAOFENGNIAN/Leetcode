#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){};
};

//ǰ������ݹ鴴��������
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

//ǰ��ݹ����������
void traversebiTree(TreeNode* root)
{
	if (root)
	{
		cout << root->val << " ";
		traversebiTree(root->left);
		traversebiTree(root->right);
	}
}

/*  //��������������
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
	if (!root)  //����
	{
		return 0;
	}
	DFS(root);
	return max;
}
*/

//����������С���
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
	if (!root)  //����
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
	cout << "ǰ����������";
	traversebiTree(T);
	cout << endl;
	//int result = maxDepth(T);
	int result = minDepth(T);
	cout << result <<endl;
	system("pause");
	return 0;
}