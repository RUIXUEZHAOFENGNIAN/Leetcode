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
	if (val==0)
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

void traverVectorVector(vector<vector<int>> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int>>  resultOfRootToLeaf;
vector<int> temp;
void DFS(TreeNode* root)
{
	if (root)
	{
		temp.push_back(root->val);
	}
	if (!root->left && !root->right)
	{
		resultOfRootToLeaf.push_back(temp);
		return;
	}
	if (root->left)
	{
		DFS(root->left);
		temp.pop_back();
	}
	if (root->right)
	{
		DFS(root->right);
		temp.pop_back();
	}
}

int toInt(vector<int> temp)
{
	int sum = 0;
	int bit = 1;
	for (size_t i = temp.size()-1; i>0; i--)
	{
		sum += temp[i] * bit;
		bit *= 10;
	}
	sum += temp[0] * bit;
	return sum;
}

int sumNumbers(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}
	DFS(root);
	traverVectorVector(resultOfRootToLeaf);
	int sum = 0;
	for (size_t i = 0; i < resultOfRootToLeaf.size(); i++)
	{
		int temp = toInt(resultOfRootToLeaf[i]);
		sum += temp;
	}
	return sum;
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "前序遍历结果：";
	traverseBiTree(T);
	cout << endl;
	int result = sumNumbers(T);
	cout << result << endl;
	system("pause");
	return 0;
}