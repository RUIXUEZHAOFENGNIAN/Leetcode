#include<iostream>
#define N 6
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

//递归构建链表
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
		head = (ListNode*)malloc(sizeof(ListNode));
		head->val = val;
		createLink(head->next);
	}
}

//测试用例，构建一个环链表。注意“环尾”不一定在head节点
void createCircle(ListNode*& head)
{
	ListNode* p = head;
	//head->next = p;
	for (size_t i = 2; i < N; i++)
	{
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		temp->val = i;
		p->next = temp;
		p = temp;
		
	}
	p->next = head;
}

//遍历环
void traverseCircle(ListNode* head)
{
	cout << head->val<<" ";
	ListNode* q = head->next;
	while (q!=head)
	{
		cout << q->val << " ";
		q = q->next;
	}
	cout << endl;
	cout << "入环处：" <<q->val << endl;
}

//递归遍历链表
void traverseLink(ListNode* head)
{
	if (head)
	{
		cout << head->val << " ";
		traverseLink(head->next);
	}
}

bool hasCycle(ListNode *head) 
{
	if (!head || !head->next)
	{
		return false;
	}
	ListNode* p = head;
	ListNode* q = head->next;
	while (1)
	{
		if (q == p)   //开始在前边的节点跑得快，追上了后来跑得慢的节点，说明有环
		{
			return true;
		}
		if (!q || !q->next || !p)   //遇到了尾巴，说明是单链表
		{
			return false;
		}
		q = q->next->next;
		p = p->next;
	}
}

int main()
{
	ListNode* head1;
	ListNode* head2;
	head2 = (ListNode*)malloc(sizeof(ListNode));
	head2->val = 1;
	cout << "请输入链表数值，0表示为空" << endl;
	createLink(head1);
	cout << "构建好的单链表如下：" << endl;
	traverseLink(head1);
	cout << endl;
	createCircle(head2);
	cout << "构建好的环链表如下：" << endl;
	traverseCircle(head2);
	bool result1, result2;
	result1 = hasCycle(head1);
	result2 = hasCycle(head2);
	if (result1)
	{
		cout << "head1链表有环" << endl;
	}
	else
	{
		cout << "head1链表无环" << endl;
	}
	if (result2)
	{
		cout << "head2链表有环" << endl;
	}
	else
	{
		cout << "head2链表无环" << endl;
	}
	system("pause");
	return 0;
}