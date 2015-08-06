#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

void createLink(ListNode* &head)
{
	head = (ListNode*)malloc(sizeof(ListNode));
	head->val = 1;
	ListNode* p;
	p = head;
	for (int i = 2; i < 6; i++)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = i;
		p->next = newNode;
		p = p->next;
	}
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->val = 3;
	newNode->next = NULL;
	p->next = newNode;
}

void traverse(ListNode* head)
{
	ListNode* p = head;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

ListNode* removeElements(ListNode* head, int val) 
{
	//考虑要删除元素是链首或者整个链表
	while (head != NULL && head->val == val)
	{
		head = head->next;
	}
	ListNode* p = head;
	while (p != NULL)
	{
		ListNode* q = p->next;
		if (q != NULL && q->val == val)
		{
			p->next = q->next;
			free(q);
			if (p->next != NULL && p->next->val == val)
			{
				continue;
			}
		}
		p = p->next;
	}
	return head;
}

int main()
{
	ListNode* head = NULL;
	createLink(head);
	traverse(head);
	removeElements(head,3);
	traverse(head);
	system("pause");
	return 0;
}