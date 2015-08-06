#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

void traverseTree(TreeNode* root)
{
	if (root)
	{
		cout << root->val << " ";
		traverseTree(root->left);
		traverseTree(root->right);
	}
}

int findIndexOfInorder(vector<int>& inorder,int val, int start,int end)
{
	for (size_t i = start; i <= end; i++)
	{
		if (val == inorder[i])
		{
			return i;
		}
	}
}

TreeNode* help(vector<int>&inorder, int start1, int end1, vector<int>&preorder, int start2, int end2)
{
	int len = end2 - start2 + 1;
	if (len==0)
	{
		return NULL;
	}
	if (len==1)
	{
		TreeNode* t = new TreeNode(preorder[start2]);
		//cout << preorder[start2]<< endl;
		return t;
	}
	TreeNode* t = new TreeNode(preorder[start2]);
//	cout << preorder[start2] << endl;
	int indexOfInorder = findIndexOfInorder(inorder, preorder[start2], start1, end1);
	int lenOfLeftTree = indexOfInorder - start1;
	int lenOfRightTree = len - lenOfLeftTree - 1;
	if (lenOfLeftTree > 0)
	{
		t->left = help(inorder, start1, indexOfInorder - 1, preorder, start2 + 1, start2 + lenOfLeftTree);
	}
	if (lenOfRightTree > 0)
	{
		t->right = help(inorder,indexOfInorder+1,end1,preorder,start2+lenOfLeftTree+1,end2);
	}
	return t;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0)
	{
		return NULL;
	}
	int end = preorder.size() - 1;
	TreeNode* root = help(inorder, 0, end, preorder, 0, end);
	return root;
}

int main()
{
	vector<int> preorder = {1,2,4,5,3,6,7};
	vector<int> inorder =  {4,2,5,1,6,3,7};
	TreeNode* root = buildTree(preorder,inorder);
	traverseTree(root);
	system("pause");
	return 0;
}