#include<iostream>
using namespace std;

//把链表中小于X的元素放到X前，大于X的元素放到X后，并在这两部分保持以前的相对顺序
struct  ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

void createList(ListNode*& head)
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
		createList(head->next);
	}
}

void traverseList(ListNode*& head)
{
	if (head)
	{
		cout << head->val << " ";
		traverseList(head->next);
	}
}

//分析：遍历一遍head链表，把小于x的元素放在head1链表，大于等于x的链表放到head2链表，然后把head2连到head1上
ListNode* partition(ListNode* head, int x) {
	ListNode* head1 = NULL;
	ListNode* p1 = NULL;
	ListNode* head2 = NULL;
	ListNode* p2 = NULL;
	ListNode* p = head;
	while (p)
	{
		if (p->val < x)
		{
			if (head1==NULL)
			{
				head1 = new ListNode(p->val);
				p1 = head1;
			}
			else
			{
				ListNode* temp = new ListNode(p->val);
				p1->next = temp;
				p1 = p1->next;
			}
		}
		else
		{
			if (head2 == NULL)
			{
				head2 = new ListNode(p->val);
				p2 = head2;
			}
			else
			{
				ListNode* temp = new ListNode(p->val);
				p2->next = temp;
				p2 = p2->next;
			}
		}
		p = p->next;
	}
	if (p1)
	{
		p1->next = head2;
	}
	else
	{
		head1 = head2;
	}
	return head1;
}

int main()
{
	ListNode* head;
	createList(head);
	cout << "head链表： ";
	traverseList(head);
	cout << endl;
	int x;
	cin >> x;
	ListNode* ret = partition(head,x);
	traverseList(ret);
	system("pause");
	return 0;
}