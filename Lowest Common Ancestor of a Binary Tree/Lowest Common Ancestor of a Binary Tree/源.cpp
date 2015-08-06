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
//�㷨һ���Զ����£��ֱ�õ����ڵ㵽�ڵ�p�ͽڵ�q������,  ��������������ཻ�ڵ�
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
	m[root] = true;   //true����ѷ��ʹ�
	while (!stk.empty())
	{
		TreeNode* top = stk.top();
		if (top->left && !m[top->left])  //��ջ
		{
			stk.push(top->left);
			m[top->left] = true;
			if (top->left == p)  //�ҵ�P�ڵ㣬���ɵõ����ڵ㵽P֮��Ľڵ�
			{
				stkToLink(vp,stk);
				if (!vq.empty())             //����֮ǰvq���ҵ�
				{
					break;
				}
			}
			if (top->left == q)  //�ҵ�q�ڵ㣬���ɵõ����ڵ㵽q֮��Ľڵ�
			{
				stkToLink(vq, stk);
				if (!vp.empty())             //����֮ǰvp���ҵ�
				{
					break;
				}
			}
			continue;
		}
		if (top->right && !m[top->right])  //û�����ʹ����ջ
		{
			stk.push(top->right);
			m[top->right] = true;
			if (top->right == p)  //�ҵ�P�ڵ㣬���ɵõ����ڵ㵽P֮��Ľڵ�
			{
				stkToLink(vp, stk);
				if (!vq.empty())             //����֮ǰvq���ҵ�
				{
					break;
				}
			}
			if (top->right == q)  //�ҵ�q�ڵ㣬���ɵõ����ڵ㵽q֮��Ľڵ�
			{
				stkToLink(vq, stk);
				if (!vp.empty())             //����֮ǰvp���ҵ�
				{
					break;
				}
			}
			continue;
		}
		stk.pop();
	}
	//�������ཻ�ڵ�
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
//�㷨�����ݹ�
//http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
*/
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *n1, TreeNode *n2){
	//�����ǰ�����Ϊ�շ���NULL  
	if (root == NULL){
		return NULL;
	}
		
	//����ǰ�ҵ�n1����n2����һ������ֱ�ӷ���  
	if (root == n1 || root == n2){
		return root;
	}
	//�ֱ�����������в���n1��n2  
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
	//�������ڷֱ��������������ҵ�n1��n2��˵����ǰ�ڵ����Ҫ�ҵĽ�  
	if (left&&right){
		cout << "left = " << left->val << endl;
		cout << "right = " << right->val << endl;
		return root;
	}
	//������������ǵĺ����ڴ˴�����  
	//1.��һ����������������ҵ�n1��n2�е�ĳ���ڵ�  
	//2.���ڵ�ǰ�ڵ�������������Ѿ����ҵ�Ҫ�ҵĽ�  
	//3.�Ե�ǰ�ڵ�Ϊ�������������Ͳ�����n1��n2  
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