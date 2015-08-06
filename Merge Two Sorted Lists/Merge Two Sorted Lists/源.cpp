#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

void createLink1(ListNode* &l1)
{
	l1 = (ListNode*)malloc(sizeof(ListNode));
	l1->val = 1;
	ListNode* p = l1;
	for (int i = 3; i < 15; i += 2)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = i;
		p->next = newNode;
		p = p->next;
	}
	p->next = NULL;
}

void createLink2(ListNode* &l2)
{
	l2 = (ListNode*)malloc(sizeof(ListNode));
	l2->val = 2;
	ListNode* p = l2;
	for (int i = 4; i < 7; i += 2)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = i;
		p->next = newNode;
		p = p->next;
	}
	p->next = NULL;
}

void traverse(ListNode* head)
{
	ListNode* p = head;
	while (p!=NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	ListNode* head;
	ListNode* p;
	ListNode* q;
	ListNode* h;
	int flag = 1;
	if (l1->val<l2->val)
	{
		head = h = l1;
		p = head->next;
		q = l2;
	}
	else
	{
		head = h = l2;
		p = head->next;
		q = l1;
	}
	if (p == NULL)
	{
		h->next = q;
		return head;
	}
	while (1)
	{
		if (p->val < q->val)
		{
			h->next = p;
			h = h->next;
			p = p->next;
		}
		else
		{
			h->next = q;
			h = h->next;
			q = q->next;
		}
		if (p == NULL)
		{
			h->next = q;
			break;
		}
		if (q == NULL)
		{
			h->next = p;
			break;
		}
	}
	return head;
}

int main()
{
	ListNode* l1 = NULL;
	ListNode* l2 = NULL;
	createLink1(l1);
	createLink2(l2);
	traverse(l1);
	traverse(l2);
	ListNode* result = mergeTwoLists(l1,l2);
	traverse(result);
	system("pause");
	return 0;
}