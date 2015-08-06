#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};

//ÏÈÐò±éÀú¶þ²æÊ÷
void traverseBiTrees(TreeNode* root)
{
	if (root)
	{
		cout << root->val << " ";
		traverseBiTrees(root->left);
		traverseBiTrees(root->right);
	}
}

vector<TreeNode*> generateTrees(int n) 
{

}

int main()
{
	int n;
	cin >> n;
	vector<TreeNode*> result;
	result = generateTrees(n);
	for (size_t i = 0; i < result.size(); i++)
	{
		traverseBiTrees(result[i]);
		cout << endl;
	}
	system("pause");
	return 0;
}