#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
};

//�����������������
void createBiTree(TreeNode* &T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = (TreeNode*)malloc(sizeof(TreeNode));
		T->val = ch;
		createBiTree(T->left);
		createBiTree(T->right);
	}
}

//�������������
void preOrderBiTree(TreeNode* T, string &leftToRight)
{
	if (T)
	{
		cout << T->val << " ";
		leftToRight += T->val;
		preOrderBiTree(T->left, leftToRight);
		preOrderBiTree(T->right, leftToRight);
	}
	else
	{
		cout << "#"<<" ";
		leftToRight += "#";
	}
}

//����������������������
void preOrderBiTreeNew(TreeNode* T, string &rightToLeft)
{
	
	if (T)
	{
		cout << T->val << " ";
		rightToLeft += T->val;
		preOrderBiTreeNew(T->right, rightToLeft);
		preOrderBiTreeNew(T->left, rightToLeft);
	}
	else
	{
		cout << "#"<<" ";
		rightToLeft += "#";
	}
}

//�ж϶������Ƿ�Գ�
bool isSymmetric(TreeNode* root)
{
	string leftToRight;
	preOrderBiTree(root, leftToRight);
	string rightToLeft;
	preOrderBiTreeNew(root,rightToLeft);
	if (leftToRight.length() == rightToLeft.length())
	{
		int i = 0;
		while (i<leftToRight.length() && leftToRight[i] == rightToLeft[i])
		{
			i++;
		}
		if (i == leftToRight.length())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


int main()
{
	TreeNode* T;
	createBiTree(T);
	bool result = isSymmetric(T);
	if (result)
	{
		cout << "�ö������Գ�" << endl;
	}
	else
	{
		cout << "�ö������ǶԳ�" << endl;
	}
	system("pause");
	return 0;
}
