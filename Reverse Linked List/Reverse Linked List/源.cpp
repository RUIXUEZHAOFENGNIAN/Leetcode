#include <iostream>
#include<cstring>
#include <vector>
#include <assert.h>
using namespace std;

typedef struct ListNode
{
	int m_key;
	ListNode* next;
}ListNode;


void createList(ListNode* &pHead)
{
	pHead = new ListNode;
	pHead->m_key = 0;
	pHead->next = NULL;
	ListNode* p = pHead;
	for (int i = 1; i<10; i++)
	{
		ListNode* pNewNode = new ListNode;
		pNewNode->m_key = i;
		pNewNode->next = NULL;
		p->next = pNewNode;
		p = pNewNode;
	}
}

void destoryList(ListNode* pHead)
{
	assert(pHead != NULL);
	ListNode* pNext = pHead->next;
	while (pNext != NULL)
	{
		delete pHead;
		pHead = pNext;
		pNext = pHead->next;
	}
	delete pHead;
	pHead = NULL;
	return;
}

void traverse(ListNode* pHead)
{
	while (pHead!=NULL)
	{
		cout << pHead->m_key << endl;
		pHead = pHead->next;
	}
}

/*单链表反转---递归法*/
ListNode* reverseList(ListNode* head)
{
	if (head==NULL || head->next ==NULL)
	{
		return head;
	}
	ListNode *p = head->next;
	ListNode* n = reverseList(p);
	p->next = head;
	head->next = NULL;
	return n;
}

int main()
{
	ListNode* head = NULL;
	createList(head);
	traverse(head);
	ListNode *consult;
	consult = reverseList(head);
	traverse(consult);
	//destoryList(head);
	system("pause");
	return 0;
}