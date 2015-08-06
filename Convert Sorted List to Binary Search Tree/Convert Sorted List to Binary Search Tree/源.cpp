#include<iostream>
#include<vector>
using namespace std;


//˼·һ��ת����������ٲ������ڴ����
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){};
};

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

//�ݹ鴴��������
void createLink(ListNode*& head)
{
	int val;
	cin >> val;
	if (val == 0)
	{
		head = NULL;
	}
	else
	{
		head = new ListNode(val);
		createLink(head->next);
	}
}

void linkToArray(ListNode* head,vector<int>& nums)
{
	if (head)
	{
		nums.push_back(head->val);
		linkToArray(head->next,nums);
	}
}

//�ݹ鴴��ƽ����������
TreeNode* DFSCreateBiSearchTree(vector<int> nums, int l, int r)
{
	int len = r - l + 1;
	if (len == 0)
	{
		return NULL;
	}
	if (len == 1)   //Ҷ�ڵ�
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
		t->left = DFSCreateBiSearchTree(nums, l, mid - 1);
	}
	if (lenOfRightTree>0)
	{
		t->right = DFSCreateBiSearchTree(nums, mid + 1, r);
	}
	return t;
}

//ǰ��ݹ����������
void traverseBiTree(TreeNode* root)
{
	if (root)
	{
		cout << root->val << " ";
		traverseBiTree(root->left);
		traverseBiTree(root->right);
	}
}

TreeNode* sortedListToBST(ListNode* head) {
	if (head==NULL)
	{
		return NULL;
	}
	vector<int> nums;
	linkToArray(head,nums);
	TreeNode* root = DFSCreateBiSearchTree(nums, 0, nums.size() - 1);
	return root;
}

int main()
{
	//vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8 };
	ListNode* head;
	createLink(head);
	TreeNode* T = sortedListToBST(head);
	traverseBiTree(T);
	system("pause");
	return 0;
}