#include<iostream>

ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *p = head->next;
	ListNode* n = reverseList(p);
	p->next = head;
	head->next = NULL;
	return n;
}