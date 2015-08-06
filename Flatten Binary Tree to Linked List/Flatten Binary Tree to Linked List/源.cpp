#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

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

void DFS(TreeNode* root,vector<TreeNode*>& v)
{
	if (root)
	{
		v.push_back(root);
		DFS(root->left,v);
		DFS(root->right,v);
	}
}

void flatten(TreeNode* root) {
	vector<TreeNode*> v;
	DFS(root,v);
	cout << v.size() << endl;
	if (v.size()<2)
	{
		return;
	}
	TreeNode* p = root;
	for (size_t i = 1; i < v.size(); i++)
	{
		p->right = v[i];
		p->left = NULL;
		p = p->right;
	}
	p->right = NULL;
	p->left = NULL;
	traverseBiTree(root);
	return;
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "前序遍历结果：";
	traverseBiTree(T);
	cout << endl;
	flatten(T);
	system("pause");
	return 0;
}