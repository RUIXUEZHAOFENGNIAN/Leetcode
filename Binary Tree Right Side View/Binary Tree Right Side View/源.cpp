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
	q.push(root);        //���ڵ����
	while (!q.empty())
	{
		root = q.front();
		if (root->level > curLevel)  //˵���ѽ�����һ����׸��ڵ�
		{
			temp.push_back(root->node->val);
			++curLevel;
		}
		if (root->node->right)    //�Һ��ӷǿգ�����
		{
			levelNode* a;
			a = (levelNode*)malloc(sizeof(levelNode));
			a->level = root->level + 1;
			a->node = root->node->right;
			q.push(a);
		}
		if (root->node->left)                  //���ӷǿգ�����
		{
			levelNode* a;
			a = (levelNode*)malloc(sizeof(levelNode));
			a->level = root->level + 1;
			a->node = root->node->left;
			q.push(a);
		}
		q.pop();       //����
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
	cout << "ǰ����������";
	traverseBiTree(T);
	cout << endl;
	vector<int> result = rightSideView(T);
	cout << "�������󿴵Ľ����" << endl;
	traverVector(result);
	system("pause");
	return 0;
}