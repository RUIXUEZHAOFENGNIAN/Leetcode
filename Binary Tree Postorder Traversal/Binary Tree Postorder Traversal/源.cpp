#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
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

//����ݹ����������
void traverseBiTree(TreeNode* root)
{
	if (root)
	{
		traverseBiTree(root->left);
		traverseBiTree(root->right);
		cout << root->val << " ";
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

void DFS(TreeNode* root, vector<int>& result)
{
	if (root)
	{
		DFS(root->left, result);
		DFS(root->right, result);
		result.push_back(root->val);
	}
}

vector<int> postorderTraversal(TreeNode* root) 
{
	vector<int> result;
	if (!root)
	{
		return result;
	}
	DFS(root, result);
	return result;
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "������������";
	traverseBiTree(T);
	cout << endl;
	vector<int> result = postorderTraversal(T);
	traverseVector(result);
	system("pause");
	return 0;
}