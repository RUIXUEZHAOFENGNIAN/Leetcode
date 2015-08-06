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

vector<vector<int>> BFS(levelNode* root)
{
	int curLevel = 1;
	vector<vector<int>> result;
	vector<int> temp;
	queue<levelNode*> q;
	q.push(root);        //���ڵ����
	while (!q.empty())
	{
		root = q.front();
		if (root->level > curLevel)  //˵���ѽ�����һ����׸��ڵ�
		{
			if (curLevel%2==0)          //ż����ʱ�����ҵ���
			{
				reverse(temp.begin(),temp.end());
			}
			result.push_back(temp);
			temp.clear();
			++curLevel;
			temp.push_back(root->node->val);
		}  
		else
		{
			temp.push_back(root->node->val);       //˵�����ڵ�ǰ�㣬�����ӵ�temp
		}
		if (root->node->left)                  //���ӷǿգ�����
		{
			levelNode* a;
			a = (levelNode*)malloc(sizeof(levelNode));
			a->level = root->level + 1;
			a->node = root->node->left;
			q.push(a);
		}
		if (root->node->right)    //�Һ��ӷǿգ�����
		{
			levelNode* a;
			a = (levelNode*)malloc(sizeof(levelNode));
			a->level = root->level + 1;
			a->node = root->node->right;
			q.push(a);
		}
		q.pop();       //����
	}
	if (curLevel % 2 == 0)          //ż����ʱ�����ҵ���
	{
		reverse(temp.begin(), temp.end());
	}
	result.push_back(temp);
	return result;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
	if (!root)
	{
		vector<vector<int>> v;
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
	vector<vector<int>> result = zigzagLevelOrder(T);
	cout << "��α��������" << endl;
	traverVectorVector(result);
	system("pause");
	return 0;
}