#include<iostream>
using namespace std;

struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
};

//����������������н���ֵ,�ո��ַ��������
void createBiTree(TreeNode* &T)
{
	// ����������������н���ֵ��һ���ַ������ո��ַ����������
	//������������ʾ������T��  
	char ch;
	if ((ch = getchar()) == '#')
	{ 
		T = NULL;//����getchar����Ϊ��������׼�⺯��  
	}
	else
	{
		T = (TreeNode*)malloc(sizeof(TreeNode)); //�����µ�����                
		T->val = ch;                             //��getchar�������������  
		createBiTree(T->left);                   //�ݹ鴴��������  
		createBiTree(T->right);                  //�ݹ鴴��������  
	}
}

//===============================================����ݹ����������  
void PreOrderTraverse(TreeNode* &T){
	//����ݹ����������  
	if (T){//����㲻Ϊ�յ�ʱ��ִ��  
		cout << T->val<<" ";
		PreOrderTraverse(T->left); 
		PreOrderTraverse(T->right);
	}
	else cout << "";
}//PreOrderTraverse 

//=============================================����ݹ����������
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
		Posorder(T->left);//����ݹ����������  
		Posorder(T->right);//����ݹ����������  
		cout << T->val<<" ";//���ʸ����  
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
		invertTree(root->left);//����ݹ����������  
		invertTree(root->right);//����ݹ����������  
	}
	return root;
}


int main()
{
	TreeNode* T;
	createBiTree(T);
	cout << "�����ɹ�" <<endl;
	cout << "ǰ������"<<endl;
	PreOrderTraverse(T);
	cout << endl;
	cout << "��������" << endl;
	InorderTraverse(T);
	cout << endl;
	cout << "��������" << endl;
	Posorder(T);
	cout << endl;
	cout << "���ڵ��ֵ��" <<T->val << endl;
	TreeNode* result = invertTree(T);
	cout << "��ת��ĺ�������" << endl;
	Posorder(result);
	cout << endl;
	system("pause");
	return 0;
}