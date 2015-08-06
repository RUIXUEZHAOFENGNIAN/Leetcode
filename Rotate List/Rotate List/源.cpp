#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
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

//算法一：先计算链表长度
ListNode* rotateRight(ListNode* head, int k) {
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* fast = head;
	ListNode* slow = head;
	int len = 0;
	while (fast)
	{
		++len;
		fast = fast->next;
	}
	k = k%len;
	if (k==0)
	{
		return head;
	}
	fast = head;
	while (k-- && fast)
	{
		fast = fast->next;
	}
	while (fast->next)
	{
		fast = fast->next;
		slow = slow->next;
	}
	ListNode* newHead = slow->next;
	slow->next = NULL;
	fast->next = head;
	return newHead;
}

int main()
{
	ListNode* head;
	cout << "请创建链表：" << endl;
	createList(head);
	traverseList(head);
	cout << endl;
	int K;
	cout << "请输入K值： ";
	cin >> K;
	ListNode* ret = rotateRight(head,K);
	traverseList(ret);
	cout << endl;
	system("pause");
	return 0;
}