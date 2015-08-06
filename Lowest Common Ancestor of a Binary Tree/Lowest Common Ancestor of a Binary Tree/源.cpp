#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void createTree(TreeNode*& head,TreeNode*& p,TreeNode*& q)
{
	head = new TreeNode(1);
	TreeNode* node = head;
	node->left = new TreeNode(2);
	node->right = new TreeNode(3);
	q = node->right;
	node->right->left = NULL;
	node->right->right = NULL;
	node = node->left;
	node->left = new TreeNode(4);
	p = node->left;
	node->right = NULL;
	node->left->left = NULL;
	node->left->right = NULL;
}

void postTraverseTree(TreeNode* head)
{
	if (head)
	{
		postTraverseTree(head->left);
		postTraverseTree(head->right);
		cout << head->val << " ";
	}
}

void stkToLink(vector<TreeNode*>& v,stack<TreeNode*> stk)
{
	while (!stk.empty())
	{
		v.push_back(stk.top());
		stk.pop();
	}
	reverse(v.begin(),v.end());
}

void traverseV(vector<TreeNode*> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i]->val << " ";
	}
	cout << endl;
}

/*
//算法一：自顶向下，分别得到根节点到节点p和节点q的链表,  计算两条链表的相交节点
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL || p == root || q == root)
	{
		return root;
	}
	stack<TreeNode*> stk;
	vector<TreeNode*> vp;
	vector<TreeNode*> vq;
	map<TreeNode*, bool> m;
	stk.push(root);
	m[root] = true;   //true标记已访问过
	while (!stk.empty())
	{
		TreeNode* top = stk.top();
		if (top->left && !m[top->left])  //进栈
		{
			stk.push(top->left);
			m[top->left] = true;
			if (top->left == p)  //找到P节点，即可得到根节点到P之间的节点
			{
				stkToLink(vp,stk);
				if (!vq.empty())             //若在之前vq已找到
				{
					break;
				}
			}
			if (top->left == q)  //找到q节点，即可得到根节点到q之间的节点
			{
				stkToLink(vq, stk);
				if (!vp.empty())             //若在之前vp已找到
				{
					break;
				}
			}
			continue;
		}
		if (top->right && !m[top->right])  //没被访问过则进栈
		{
			stk.push(top->right);
			m[top->right] = true;
			if (top->right == p)  //找到P节点，即可得到根节点到P之间的节点
			{
				stkToLink(vp, stk);
				if (!vq.empty())             //若在之前vq已找到
				{
					break;
				}
			}
			if (top->right == q)  //找到q节点，即可得到根节点到q之间的节点
			{
				stkToLink(vq, stk);
				if (!vp.empty())             //若在之前vp已找到
				{
					break;
				}
			}
			continue;
		}
		stk.pop();
	}
	//求链表相交节点
	traverseV(vp);
	traverseV(vq);
	int len = min(vp.size(),vq.size());
	size_t i = 0;
	for (; i < len; i++)
	{
		if (vp[i] != vq[i])
		{
			break;
		}
	}
	return vp[i-1];
}*/

/*
//算法二：递归
//http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
*/
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *n1, TreeNode *n2){
	//如果当前根结点为空返回NULL  
	if (root == NULL){
		return NULL;
	}
		
	//若当前找到n1或者n2其中一个，则直接返回  
	if (root == n1 || root == n2){
		return root;
	}
	//分别从左右子树中查找n1和n2  
	TreeNode *left = lowestCommonAncestor(root->left, n1, n2);
	if (left)
	{
		cout << "left = "<<left->val << endl;
	}
	TreeNode *right = lowestCommonAncestor(root->right, n1, n2);
	if (right)
	{
		cout << "right = "<<right->val << endl;
	}
	//若正好在分别在左右子树中找到n1和n2则说明当前节点就是要找的解  
	if (left&&right){
		cout << "left = " << left->val << endl;
		cout << "right = " << right->val << endl;
		return root;
	}
	//存在三种情况是的函数在此处返回  
	//1.第一次在左或右子树中找到n1、n2中的某个节点  
	//2.从在当前节点的左右子树中已经查找到要找的解  
	//3.以当前节点为根的子树根本就不存在n1和n2  
	return left ? left : right;
}

int main()
{
	TreeNode* head;
	TreeNode* p;
	TreeNode* q;
	createTree(head,p,q);
	cout <<"p->value = "<< p->val << endl;
	cout <<"q->value = "<< q->val << endl;
	postTraverseTree(head);
	cout << endl;
	TreeNode* result = lowestCommonAncestor(head,p,q);
	cout << "lowest Common Ancestor = " << result->val << endl;
	system("pause");
	return 0;
}