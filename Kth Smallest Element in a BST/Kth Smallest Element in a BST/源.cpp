#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

void inorderTraverseTree(TreeNode* head)
{
	if (head)
	{
		inorderTraverseTree(head->left);
		cout << head->val << " ";
		inorderTraverseTree(head->right);
	}
}

void DFS(TreeNode* root,int& k,int& temp)
{
	if (root)
	{
		DFS(root->left, k,temp);
		if (k<1)
		{
			return;
		}
		if (k==1)
		{
			temp = root->val;
		}
		cout << "k = "<< k << " " << "val = " << root->val <<endl;
		k--;
		DFS(root->right, k,temp);
	}
}


int kthSmallest(TreeNode* root, int k) 
{
	int temp = 0;
	DFS(root,k,temp);
	return temp;
}

int main()
{
	TreeNode* head;
	createTree(head);
	inorderTraverseTree(head);
	cout << endl;
	cout<<kthSmallest(head,4)<<endl;
	system("pause");
	return 0;
}