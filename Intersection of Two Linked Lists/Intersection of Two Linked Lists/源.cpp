#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

void createLinkA(ListNode* &headA)
{
	headA = (ListNode*)malloc(sizeof(ListNode));
	headA->val = 5;
	ListNode* p = headA;
	for (int i = 7; i < 10; i++)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = i;
		p->next = newNode;
		p = p->next;
	}
	p->next = NULL;
}

void createLinkB(ListNode* &headB)
{
	headB = (ListNode*)malloc(sizeof(ListNode));
	headB->val = 2;
	ListNode* p = headB;
	for (int i = 4; i < 7; i += 2)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = i;
		p->next = newNode;
		p = p->next;
	}
	for (int i = 7; i < 10; i++)
	{
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->val = i;
		p->next = newNode;
		p = p->next;
	}
	p->next = NULL;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	int lenA = 0, lenB = 0;
	ListNode* pA = headA;
	ListNode* pB = headB;
	while (pA != NULL)
	{
		++lenA;
		pA = pA->next;
	}
	while (pB != NULL)
	{
		++lenB;
		pB = pB->next;
	}
	int distance = lenA > lenB ? lenA - lenB : lenB - lenA;
	cout <<lenA<< " "<<lenB<<" "<<distance<< endl;
	ListNode* pA1 = headA;
	if (lenA>lenB)
	{
		for (size_t i = 0; i < distance; i++)
		{
			pA1 = pA1->next;
		}
	}
	ListNode* pB1 = headB;
	if (lenA<lenB)
	{
		for (size_t i = 0; i < distance; i++)
		{
			pB1 = pB1->next;
		}
	}
	cout <<pA1->val<< " " << pB1->val<< endl;
	while (pA1!=NULL || pB1!=NULL)
	{
		if (pA1->val == pB1->val)
		{
			return pA1;
		}
		pA1 = pA1->next;
		pB1 = pB1->next;
	}
	return NULL;
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

int main()
{
	ListNode* headA;
	ListNode* headB;
	createLinkA(headA);
	createLinkB(headB);
	traverse(headA);
	traverse(headB);
	ListNode* result = getIntersectionNode(headA,headB);
	traverse(result);
	system("pause");
	return 0;
}