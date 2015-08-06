#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

struct levelNode
{
	int level;
	TreeNode* node;
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

void traverVector(vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
			cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> BFS(levelNode* root)
{
	int curLevel = 1;
	vector<int> temp;
	temp.push_back(root->node->val);
	queue<levelNode*> q;
	q.push(root);        //根节点进队
	while (!q.empty())
	{
		root = q.front();
		if (root->level > curLevel)  //说明已进入下一层的首个节点
		{
			temp.push_back(root->node->val);
			++curLevel;
		}
		if (root->node->right)    //右孩子非空，进队
		{
			levelNode* a;
			a = (levelNode*)malloc(sizeof(levelNode));
			a->level = root->level + 1;
			a->node = root->node->right;
			q.push(a);
		}
		if (root->node->left)                  //左孩子非空，进队
		{
			levelNode* a;
			a = (levelNode*)malloc(sizeof(levelNode));
			a->level = root->level + 1;
			a->node = root->node->left;
			q.push(a);
		}
		q.pop();       //出队
	}
	return temp;
}

vector<int> rightSideView(TreeNode* root) 
{
	if (!root)
	{
		vector<int> v;
		return v;
	}
	levelNode* a;
	a = (levelNode*)malloc(sizeof(levelNode));
	a->level = 1;
	a->node = root;
	return BFS(a);
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "前序遍历结果：";
	traverseBiTree(T);
	cout << endl;
	vector<int> result = rightSideView(T);
	cout << "从右往左看的结果：" << endl;
	traverVector(result);
	system("pause");
	return 0;
}