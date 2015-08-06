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
	ListNode* p = head;
	for (int i = 2; i < 6; i++)
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
		cout << p->val << endl;
		p = p->next;
	}
}
/*
//two-pass算法
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	int sum = 0;
	ListNode* p1 = head;
	while (p1!=NULL)
	{
		++sum;
		p1 = p1->next;
	}
	cout <<"sum: "<<sum << endl;
	if (sum-n == 0)   //必须得考虑删除第一个元素的情况，因为删除元素的前一位置不存在
	{
		head = head->next;
		return head;
	}
	ListNode* p2 = head;
	int i = 0;
	while ((i != sum-n-1) && p2 != NULL)     //找到要删除元素的前一个位置
	{
		p2 = p2->next;
		i++;
	}
	cout << "要删除元素的前一个： " <<p2->val << endl;
	ListNode* q = p2->next;
	p2->next = q->next;
	free(q);
	return head;
}*/

//one-pass算法,思路：设两个指针间隔n,遍历到链尾，即可找到要删除的元素  分割线--提交到leetcode后竟然时间长于one-pass算法
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode* p = head;
	ListNode* q = head;
	int distance = n;
	while (distance--)
	{
		q = q->next;
	}
	if (q==NULL)  //说明要删除的元素是链首
	{
		head = head->next;
		return head;
	}
	while (q->next != NULL)  //找到要删除元素的前一位置:p指针的位置
	{
		p = p->next;
		q = q->next;
	}
	ListNode* del = p->next;
	p->next = del->next;
	free(del);
	return head;
}

int main()
{
	ListNode* head = NULL;
	createLink(head);
	traverse(head);
	ListNode* result = removeNthFromEnd(head, 2);
	traverse(result);
	system("pause");
	return 0;
}