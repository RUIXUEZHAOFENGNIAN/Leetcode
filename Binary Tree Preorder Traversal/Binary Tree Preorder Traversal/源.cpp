#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
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
void traverseBiTree(TreeNode* root)
{
	if (root)
	{
		cout << root->val << " ";
		traverseBiTree(root->left);
		traverseBiTree(root->right);
	}
}

void traverseVector(vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void DFS(TreeNode* root,vector<int>& result)
{
	if (root)
	{
		result.push_back(root->val);
		DFS(root->left,result);
		DFS(root->right,result);
	}
}

vector<int> preorderTraversal(TreeNode* root) 
{
	vector<int> result;
	if (!root)
	{
		return result;
	}
	DFS(root,result);
	return result;
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "前序遍历结果：";
	traverseBiTree(T);
	cout << endl;
	vector<int> result = preorderTraversal(T);
	traverseVector(result);
	system("pause");
	return 0;
}