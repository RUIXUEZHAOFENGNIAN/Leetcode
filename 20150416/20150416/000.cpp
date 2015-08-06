#include<iostream>
#include<string>
using namespace std;

typedef struct BiTNode
{
	char data;
	struct BiTNode *left, *right;
}BiTNode,*BiTree;

string s;
int i = 0;
void createBiTree(string::iterator p, BiTNode *T)
{
	if (*p == '#') T = NULL;
	else
	{
		if (p != s.end())
		{
			if (T = (BiTNode*)malloc(sizeof(BiTNode)))
			{
				T->data = *p;
				//cout <<T->data<< endl;
				createBiTree(++p,T->left);
				createBiTree(++p,T->right);
			}
		}
	}
}

void PreOrderTraverse(BiTree T)
{
	if (T)
	{ 
		cout <<T->data<< endl;
		PreOrderTraverse(T->left);
		PreOrderTraverse(T->right);
	}
}

int main()
{
	cin >> s;
	BiTree root = NULL;
	createBiTree(s.begin(),root);
	cout <<root->data << endl;
	PreOrderTraverse(root);
	system("pause");
	return 0;
}