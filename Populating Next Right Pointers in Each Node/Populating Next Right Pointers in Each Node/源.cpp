#include<iostream>
using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL){};
};

//�����������������
void createBiTree(TreeLinkNode* &root)
{
	int val;
	cin >> val;
	if (val == 0)
	{
		root = NULL;
	}
	else
	{
		root = (TreeLinkNode*)malloc(sizeof(TreeLinkNode));
		root->val = val;
		createBiTree(root->left);
		createBiTree(root->right);
	}
}

//�������������
void traverseBiTree(TreeLinkNode* root)
{
	if (root)
	{
		cout<< root->val<<" ";
		traverseBiTree(root->left);
		traverseBiTree(root->right);
	}
}

void nextTraverseBiTree(TreeLinkNode* root)
{
	for (TreeLinkNode* p = root; p!=NULL; p = p->left)
	{
		TreeLinkNode* temp = p;
		while (temp!=NULL)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

void buid(TreeLinkNode* &root)
{
	if (root->left)
	{
		root->left->next = root->right;
		if (root->next)
		{
			root->right->next = root->next->left;
		}
		else
		{
			root->right->next = NULL;
		}
		buid(root->left);
		buid(root->right);
	}
}

void connect(TreeLinkNode *root) 
{
	if (!root)  //����
	{
		return;
	}
	else if (!root->left)  //��ֻ��һ���ڵ㣬ƽ���������
	{
		root->next = NULL;
		return;
	}
	else
	{
		root->next = NULL;
		buid(root);
	}
}

int main()
{
	TreeLinkNode* root;
	createBiTree(root);
	traverseBiTree(root);
	cout << endl;
	connect(root);
	nextTraverseBiTree(root);
	system("pause");
	return 0;
}