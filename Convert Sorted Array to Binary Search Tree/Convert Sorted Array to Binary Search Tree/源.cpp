#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

//递归创建平衡二叉查找树
TreeNode* DFSCreateBiSearchTree(vector<int> nums, int l,int r)
{
	int len = r - l + 1;
	if (len == 0)
	{
		return NULL;
	}
	if (len == 1)   //叶节点
	{
		TreeNode* t = new TreeNode(nums[l]);
		return t;
	}
	int mid = (l + r) / 2;
	TreeNode* t = new TreeNode(nums[mid]);
	int lenOfLeftTree = mid - l;
	int lenOfRightTree = len - lenOfLeftTree - 1;
	if (lenOfLeftTree>0)
	{
		t->left = DFSCreateBiSearchTree(nums,l,mid-1);
	}
	if (lenOfRightTree>0)
	{
		t->right = DFSCreateBiSearchTree(nums, mid+1, r);
	}
	return t;
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

TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	if (nums.size() == 0)
	{
		return NULL;
	}
	TreeNode* root = DFSCreateBiSearchTree(nums,0,nums.size()-1);
	return root;

}

int main()
{
	vector<int> nums = {1,2,3,4,5,6,7,8};
	TreeNode* T = sortedArrayToBST(nums);
	traverseBiTree(T);
	system("pause");
	return 0;
}