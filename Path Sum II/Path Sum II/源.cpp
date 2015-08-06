#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

void createBiTree(TreeNode* &T)
{
	int ch;
	cin >> ch;
	if (ch == 0)
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
		cout << T->val << " ";
		traverse(T->left);
		traverse(T->right);
	}
}

int curSum = 0;
int flag = 0;
vector<int> temp;
void dfs(TreeNode* root, int sum,vector<vector<int>>& result)
{
	//cout << "curSum:" << curSum << endl;
	if (root != NULL)
	{
		curSum += root->val;
		temp.push_back(root->val);
		cout << "curSum:" << curSum << endl;
		if (curSum == sum &&root->left == NULL &&root->right == NULL)
		{
			result.push_back(temp);
			for (auto& c:temp)
			{ 
				cout << c << " ";
			}
			cout << endl;
		}
		dfs(root->left, sum,result);
		if (root->left)
		{
			curSum -= root->left->val;
			temp.pop_back();
		}
		dfs(root->right, sum,result);
		if (root->right)
		{
			curSum -= root->right->val;
			temp.pop_back();
		}
	}
}

vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
	vector<vector<int>> result;
	if (!root)
	{
		return result;
	}
	dfs(root,sum,result);
	return result;
}

void traverseVectorVector(vector<vector<int>> v)
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

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "前序遍历结果：" << endl;
	traverse(T);
	cout << endl;
	int sum;
	cout << "输入sum值" << endl;
	cin >> sum;
	vector<vector<int>> result = pathSum(T,sum);
	traverseVectorVector(result);
	system("pause");
	return 0;
}