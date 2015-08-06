#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

void createTree(TreeNode*& head)
{
	int val;
	cin >> val;
	if (val == 0)
	{
		head = NULL;
	}
	else
	{
		head = new TreeNode(val);
		createTree(head->left);
		createTree(head->right);
	}
}

void traverseTree(TreeNode* head)
{
	if (head)
	{
		traverseTree(head->left);
		traverseTree(head->right);
		cout << head->val << " ";
	}
}

/*
There¡¯s only three cases you need to consider
1.Both nodes are to the left of the tree.
2.Both nodes are to the right of the tree.
3.One node is on the left while the other is on the right.
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (!root || !p || !q)
	{
		return NULL;
	}
	if (min(p->val, q->val) <= root->val && root->val <= max(p->val, q->val))
	{
		return root;
	}
	else if (root->val < min(p->val,q->val))
	{
		return lowestCommonAncestor(root->right,p,q);
	}
	else
	{
		return lowestCommonAncestor(root->left, p, q);
	}
}

int main()
{
	TreeNode* head;
	createTree(head);
	traverseTree(head);
//	TreeNode* result = lowestCommonAncestor(head,p,q);
	system("pause");
	return 0;
}