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
//two-pass�㷨
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
	if (sum-n == 0)   //����ÿ���ɾ����һ��Ԫ�ص��������Ϊɾ��Ԫ�ص�ǰһλ�ò�����
	{
		head = head->next;
		return head;
	}
	ListNode* p2 = head;
	int i = 0;
	while ((i != sum-n-1) && p2 != NULL)     //�ҵ�Ҫɾ��Ԫ�ص�ǰһ��λ��
	{
		p2 = p2->next;
		i++;
	}
	cout << "Ҫɾ��Ԫ�ص�ǰһ���� " <<p2->val << endl;
	ListNode* q = p2->next;
	p2->next = q->next;
	free(q);
	return head;
}*/

//one-pass�㷨,˼·��������ָ����n,��������β�������ҵ�Ҫɾ����Ԫ��  �ָ���--�ύ��leetcode��Ȼʱ�䳤��one-pass�㷨
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode* p = head;
	ListNode* q = head;
	int distance = n;
	while (distance--)
	{
		q = q->next;
	}
	if (q==NULL)  //˵��Ҫɾ����Ԫ��������
	{
		head = head->next;
		return head;
	}
	while (q->next != NULL)  //�ҵ�Ҫɾ��Ԫ�ص�ǰһλ��:pָ���λ��
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