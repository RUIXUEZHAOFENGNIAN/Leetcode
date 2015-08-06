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

struct Node
{
	TreeNode* node;
	int level;
	Node(TreeNode* n,int newLevel):node(n),level(newLevel){}
};

void traverseVector(vector<vector<int>> ret)
{
	for (size_t i = 0; i < ret.size(); i++)
	{
		for (size_t j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> result;
	if (!root)
	{
		return result;
	}
	queue<Node> q;
	q.push(Node(root, 0));  //根节点进队
	vector<int> temp; //保留每一层节点
	int curLevel = 0;
	int test = 0;
	while (!q.empty())   //队列非空
	{
		Node node = q.front();  //获得队首
		//进行每层之间的判断
		if (curLevel < node.level)
		{
			cout << test++ << "层遍历：";
			for (auto &c : temp)
				cout << c << " ";
			cout << endl;
			result.push_back(temp);
			temp.clear();
			curLevel = node.level;
		}
		temp.push_back(node.node->val);
		if (node.node->left)
		{
			q.push(Node(node.node->left, node.level + 1));  //左孩子进队
		}

		if (node.node->right)
		{
			q.push(Node(node.node->right, node.level + 1));  //右孩子进队
		}

		q.pop();//删除队首
	}
	result.push_back(temp);
	cout << "result.size() = " << result.size() << endl;
	reverse(result.begin(),result.end());
	return result;
}

int main()
{
	TreeNode* root;
	createBiTree(root);
	cout << "前序遍历结果："<< endl;
	traverse(root);
	cout << endl;
	vector<vector<int>> ret =levelOrderBottom(root);
	cout << "(从下到上)层次遍历结果：" << endl;
	traverseVector(ret);
    system("pause");
	return 0;
}