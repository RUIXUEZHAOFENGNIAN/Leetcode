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
	q.push(root);        //根节点进队
	while (!q.empty())
	{
		root = q.front();
		if (root->level > curLevel)  //说明已进入下一层的首个节点
		{
			if (curLevel%2==0)          //偶数层时，从右到左
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
			temp.push_back(root->node->val);       //说明还在当前层，继续加到temp
		}
		if (root->node->left)                  //左孩子非空，进队
		{
			levelNode* a;
			a = (levelNode*)malloc(sizeof(levelNode));
			a->level = root->level + 1;
			a->node = root->node->left;
			q.push(a);
		}
		if (root->node->right)    //右孩子非空，进队
		{
			levelNode* a;
			a = (levelNode*)malloc(sizeof(levelNode));
			a->level = root->level + 1;
			a->node = root->node->right;
			q.push(a);
		}
		q.pop();       //出队
	}
	if (curLevel % 2 == 0)          //偶数层时，从右到左
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
	cout << "前序遍历结果：";
	traverseBiTree(T);
	cout << endl;
	vector<vector<int>> result = zigzagLevelOrder(T);
	cout << "层次遍历结果：" << endl;
	traverVectorVector(result);
	system("pause");
	return 0;
}