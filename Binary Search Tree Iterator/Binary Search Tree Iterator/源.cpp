#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

stack<TreeNode*> stk;
void leftLoop(TreeNode* root)
{
	while (root)
	{
		stk.push(root);
		root = root->left;
	}
}
void BSTIterator(TreeNode *root) {
	leftLoop(root);
}

/** @return whether we have a next smallest number */
bool hasNext() {
	return !stk.empty();
}

/** @return the next smallest number */
int next() {
	TreeNode* top = stk.top();
	int val = top->val;
	stk.pop();
	if (top->right)
	{
		leftLoop(top->right);
	}
	return val;
}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

int main()
{
	system("pause");
	return 0;
}
