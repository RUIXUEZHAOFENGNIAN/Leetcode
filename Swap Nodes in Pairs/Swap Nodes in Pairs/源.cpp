#include<iostream>
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
	if (val==0)
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

void traverseLink(ListNode* head)
{
	if (head)
	{
		cout << head->val <<" ";
		traverseLink(head->next);
	}
}

ListNode* swapPairs(ListNode* head) 
{
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* p = head;
	ListNode* q = head->next;
	int temp;
	temp = p->val;
	p->val = q->val;
	q->val = temp;
	while (q->next!=NULL && q->next->next!=NULL)
	{
		p = q->next;
		q = q->next->next;
		temp = p->val;
		p->val = q->val;
		q->val = temp;
	}
	return head;
}

int main()
{
	ListNode* head;
	cout << "请输入链表数值，0表示为空" << endl;
	createLink(head);
	cout << "构建好的单链表如下：" << endl;
	traverseLink(head);
	swapPairs(head);
	cout << "交换后的单链表如下：" << endl;
	traverseLink(head);
	system("pause");
	return 0;
}