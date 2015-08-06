#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

void createLink(ListNode* &phead)
{
    phead = (ListNode*)malloc(sizeof(ListNode));
	phead->val = 1;
	ListNode* p = phead;
	int sum = 2;
	while (sum--)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = 1;
		p->next = newNode;
		p = p->next;
	}
	sum = 2;
	while (sum--)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = 2;
		p->next = newNode;
		p = p->next;
	}
	p->next = NULL;
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

ListNode* deleteDuplicates(ListNode* head) 
{
	if (head==NULL || head->next == NULL)
	{
		return head;
	}
	//考虑链首或整个链表重复的情况
	/*
	while (head->next!=NULL && head->val==head->next->val)
	{
		head = head->next;
	}*/
	ListNode* p = head;
	while (p != NULL)
	{
		if (p->next!=NULL && p->val == p->next->val)
		{ 
			ListNode* q = p->next;
			while (q!=NULL && q->val==p->val)  //找到与p->val不重复的元素
			{
				q = q->next;
				if (q == NULL)
				{
					break;
				}
			}
			p->next = q;
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
	ListNode* result = deleteDuplicates(head);
	traverse(result);
	system("pause");
	return 0;
}