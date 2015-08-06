#include<iostream>
#define N 9
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

//�ݹ鹹������
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
		head = (ListNode*)malloc(sizeof(ListNode));
		head->val = val;
		createLink(head->next);
	}
}

//�ݹ��������
void traverseLink(ListNode* head)
{
	if (head)
	{
		cout << head->val << " ";
		traverseLink(head->next);
	}
}

//��������
ListNode* insertionSortList(ListNode* head)
{
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* p = head->next;   //Ҫ����Ľڵ�
	ListNode* start = head;    //�ź���������׽ڵ�
	ListNode* end = head;      //�ź��������β�ڵ㣨��NULL��
	while (end->next)
	{
		if (p->val < start->val)                        //p->val����Ԫ��С�������start�ڵ��ı�,end�ڵ㲻��
		{
			ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
			temp->val = p->val;
			temp->next = start;
			start = temp;
			end->next = p->next;
			ListNode* q = p;
			p = p->next;
			free(q);
		}
		else if (p->val >= end->val)                                 //p->val��ĩβԪ�ش�Ļ�end�ڵ��ı�,start�ڵ㲻��
		{
			end = p;
			p = p->next;
		}
		else                                                     //p->val���м���룬��β�ڵ㲻��
		{
			ListNode* it = start;
			while (it != end)
			{
				if (p->val >= it->val && p->val < it->next->val) //�ҵ�����λ��
				{
					break;
				}
				it = it->next;
			}
			ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
			temp->val = p->val;
			temp->next = it->next;
			it->next = temp;
			end->next = p->next;
			ListNode* q = p;
			p = p->next;
			free(q);
		}
	}
	cout << "end = " << end->val << endl;
	return start;
}

int main()
{
	ListNode* head;
	cout << "������������ֵ��0��ʾΪ��" << endl;
	createLink(head);
	cout << "�����õĵ��������£�" << endl;
	traverseLink(head);
	cout << endl;
	ListNode* result;
	result = insertionSortList(head);
	cout << "���������Ľ����" << endl;
	traverseLink(result);
	cout << endl;
	system("pause");
	return 0;
}

