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

struct Node
{
	TreeNode* node;
	int level;
	Node(TreeNode *n, int l) :node(n), level(l){}
};

void createBiTree(TreeNode* &T)
{
	int val;
	cin >> val;
	if (val == 0)
	{
		T = NULL;
	}
	else
	{
		T = (TreeNode*)malloc(sizeof(TreeNode));
		T->val = val;
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

vector<vector<int>> result;
vector<vector<int>> levelOrder(TreeNode* root)
{
	if (!root)
	{
		return result;
	}
	queue<Node> q;
	q.push(Node(root, 0));  //根节点进队
	vector<int> temp; //保留每一层节点
	temp.push_back(root->val);
	int curLevel = -1;
	while (!q.empty())   //队列非空
	{
		Node node = q.front();  //获得队首
		if (node.node->left)
		{
			q.push(Node(node.node->left, node.level + 1));  //左孩子进队
		}

		if (node.node->right)
		{
			q.push(Node(node.node->right, node.level + 1));  //右孩子进队
		}
		//进行每层之间的判断
		if (curLevel != node.level)
		{
			if (curLevel != -1)   //把之前那层加进结果中,所以最后一层还没加进结果中
			{
				result.push_back(temp);
			}
			curLevel = node.level;
			temp.clear();
			temp.push_back(node.node->val);
		}
		else   //仍在当前层遍历
		{
			temp.push_back(node.node->val);
		}
		q.pop();//删除队首
	}
	result.push_back(temp);
	return result;
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "前序遍历：";
	traverse(T);
	cout << endl;
	cout << "层次遍历:"<<endl;
	vector<vector<int>> ret = levelOrder(T);
	for (size_t i = 0; i < ret.size(); i++)
	{
		for (size_t j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}