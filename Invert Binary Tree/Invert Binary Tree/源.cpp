#include<iostream>
using namespace std;

struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
};

//按先序输入二叉树中结点的值,空格字符代表空树
void createBiTree(TreeNode* &T)
{
	// 按先序输入二叉树中结点的值（一个字符），空格字符代表空树，
	//构造二叉树表表示二叉树T。  
	char ch;
	if ((ch = getchar()) == '#')
	{ 
		T = NULL;//其中getchar（）为逐个读入标准库函数  
	}
	else
	{
		T = (TreeNode*)malloc(sizeof(TreeNode)); //产生新的子树                
		T->val = ch;                             //由getchar（）逐个读入来  
		createBiTree(T->left);                   //递归创建左子树  
		createBiTree(T->right);                  //递归创建右子树  
	}
}

//===============================================先序递归遍历二叉树  
void PreOrderTraverse(TreeNode* &T){
	//先序递归遍历二叉树  
	if (T){//当结点不为空的时候执行  
		cout << T->val<<" ";
		PreOrderTraverse(T->left); 
		PreOrderTraverse(T->right);
	}
	else cout << "";
}//PreOrderTraverse 

//=============================================中序递归遍历二叉树
void InorderTraverse(TreeNode* &T)
{
	if (T)
	{
		InorderTraverse(T->left);
		cout << T->val << " ";
		InorderTraverse(T->right);
	}
	else
	{
		cout << "";
	}
	
}

void Posorder(TreeNode* &T){
	if (T){
		Posorder(T->left);//后序递归遍历左子树  
		Posorder(T->right);//后序递归遍历右子树  
		cout << T->val<<" ";//访问根结点  
	}
	else cout << "";
}

TreeNode* invertTree(TreeNode* root)
{
	if (root)
	{
			TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
			temp = root->right;
			root->right = root->left;
			root->left = temp;
		invertTree(root->left);//后序递归遍历左子树  
		invertTree(root->right);//后序递归遍历右子树  
	}
	return root;
}


int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "创建成功" <<endl;
	cout << "前序结果："<<endl;
	PreOrderTraverse(T);
	cout << endl;
	cout << "中序结果：" << endl;
	InorderTraverse(T);
	cout << endl;
	cout << "后序结果：" << endl;
	Posorder(T);
	cout << endl;
	cout << "根节点的值：" <<T->val << endl;
	TreeNode* result = invertTree(T);
	cout << "反转后的后序结果：" << endl;
	Posorder(result);
	cout << endl;
	system("pause");
	return 0;
}