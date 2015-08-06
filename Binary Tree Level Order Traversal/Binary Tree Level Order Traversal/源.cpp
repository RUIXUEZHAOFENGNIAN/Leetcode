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
	q.push(Node(root, 0));  //���ڵ����
	vector<int> temp; //����ÿһ��ڵ�
	temp.push_back(root->val);
	int curLevel = -1;
	while (!q.empty())   //���зǿ�
	{
		Node node = q.front();  //��ö���
		if (node.node->left)
		{
			q.push(Node(node.node->left, node.level + 1));  //���ӽ���
		}

		if (node.node->right)
		{
			q.push(Node(node.node->right, node.level + 1));  //�Һ��ӽ���
		}
		//����ÿ��֮����ж�
		if (curLevel != node.level)
		{
			if (curLevel != -1)   //��֮ǰ�ǲ�ӽ������,�������һ�㻹û�ӽ������
			{
				result.push_back(temp);
			}
			curLevel = node.level;
			temp.clear();
			temp.push_back(node.node->val);
		}
		else   //���ڵ�ǰ�����
		{
			temp.push_back(node.node->val);
		}
		q.pop();//ɾ������
	}
	result.push_back(temp);
	return result;
}

int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "ǰ�������";
	traverse(T);
	cout << endl;
	cout << "��α���:"<<endl;
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