#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x),left(NULL),right(NULL){}
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

//�ҵ���Ԫ���ڸöε�λ��
int findIndex(vector<int>& inorder, int val, int start, int end)
{
	for (size_t i = start; i <= end ; i++)
	{
		if (inorder[i] == val)
		{
			return i;
		}
	}
}

TreeNode* help(vector<int>& inorder,int start1,int end1,vector<int>& postorder,int start2,int end2)
{
	int len = end1 - start1 + 1;
	if (len == 0)                //���ؿսڵ�
	{
		return NULL;
	}
	if (len == 1)
	{
		TreeNode* root = new TreeNode(inorder[start1]);
		cout<<inorder[start1]<<endl;
		return root;
	}
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = postorder[end2];
	root->left = NULL;
	root->right = NULL;
	cout << postorder[end2]<<endl;
	//�������������Ļ���
	int indexOfRoot_inorder = findIndex(inorder, postorder[end2], start1, end1);
	int lenOfLeftTree = indexOfRoot_inorder - start1;
	//int lenOfRightTree = end1 - indexOfRoot_inorder;
	int lenOfRightTree = len - lenOfLeftTree -1;
	if (lenOfLeftTree>0) //���������еݹ�
	{
		root->left = help(inorder, start1, indexOfRoot_inorder - 1, postorder, start2, start2 + lenOfLeftTree - 1);
	}
	if (lenOfRightTree>0) //���������еݹ�
	{
		root->right = help(inorder, indexOfRoot_inorder+1, end1, postorder, start2 + lenOfLeftTree, end2 - 1);
	}
	return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if (postorder.size() == 0)
	{
		return NULL;
	}
	int end = inorder.size() - 1;
	TreeNode* t = help(inorder,0,end,postorder,0,end);
	return t;
}

int main()
{
	//vector<int> inorder =   {4,2,5,1,6,3,7};
	//vector<int> postorder = {4,5,2,6,7,3,1};
	vector<int> inorder = { 2, 3, 1 };
	vector<int> postorder = { 3, 2, 1 };
	TreeNode* root = buildTree(inorder,postorder);
	traverseTree(root);
	system("pause");
	//system("pause");
	return 0;
}