#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
		head = new ListNode(val);
		createLink(head->next);
	}
}

void traverseLink(ListNode* head)
{
	if (head)
	{
		cout << head->val << " ";
		traverseLink(head->next);
	}
}

//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3
//Given 1->1->1->2->2, return 
//找到链表头
void findHead(ListNode*& head, ListNode*& p, ListNode*& q)
{
	if (!head || !q || p->val != q->val)
	{
		return;
	}
	bool flag = false;
	while (q && p->val == q->val)
	{
		flag = true;
		q = q->next;
		p = p->next;
	}
	if (flag)
	{
		head = q;
		if (q)
		{
			q = q->next;
		}
		if (p)
		{
			p = p->next;
		}
		flag = false;
	}
	findHead(head, p, q);
}

ListNode* deleteDuplicates(ListNode* head) {
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* p = head;
	ListNode* q = head->next;
	findHead(head, p, q);
	bool flag = false;
	while (q)
	{
		//遇到duplicate node
		if (q->next && q->val == q->next->val)
		{
			flag = true;
			q = q->next;
			continue;
		}
		if (flag)
		{
			p->next = q->next;
			q = q->next;
			flag = false;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	return head;
}

int main()
{
	ListNode* head;
	createLink(head);
	traverseLink(head);
	cout << endl;
	traverseLink(deleteDuplicates(head));
	cout << endl;
	system("pause");
	return 0;
}