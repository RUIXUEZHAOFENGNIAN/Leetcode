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

//��������������һ��������ע�⡰��β����һ����head�ڵ�
void createCircle(ListNode*& head)
{
	ListNode* p = head;
	for (size_t i = 2; i < N; i++)
	{
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		temp->val = i;
		p->next = temp;
		p = temp;

	}
	p->next = head->next;
}

//������
void traverseCircle(ListNode* head)
{
	cout << head->val << " "<<head->next->val<<" ";
	ListNode* q = head->next->next;
	while (q != head->next)
	{
		cout << q->val << " ";
		q = q->next;
	}
	cout << endl;
	cout << "�뻷����" << q->val << endl;
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

bool hasCycle(ListNode *head)
{
	if (!head || !head->next)
	{
		return false;
	}
	ListNode* p = head;
	ListNode* q = head->next;
	while (1)
	{
		if (q == p)   //��ʼ��ǰ�ߵĽڵ��ܵÿ죬׷���˺����ܵ����Ľڵ㣬˵���л�
		{
			return true;
		}
		if (!q || !q->next || !p)   //������β�ͣ�˵���ǵ�����
		{
			return false;
		}
		q = q->next->next;
		p = p->next;
	}
}

ListNode *detectCycle(ListNode *head) 
{
	if (!head || !head->next)
	{
		return NULL;
	}
	ListNode* p = head;
	ListNode* q = head->next;
	while (1)
	{
		if (q == p)   //��ʼ��ǰ�ߵĽڵ��ܵÿ죬׷���˺����ܵ����Ľڵ㣬˵���л�,����p������
		{
			ListNode* start = head;
			p = p->next;   //ע����������Ŀ�ָ���ʼλ����head->next,��������һ��
			while (start != p)
			{
				cout << "flag2" << endl;
				p = p->next;
				start = start->next;
			}
			cout << start->val << endl;
			return start;
		}
		if (!q || !q->next || !p)   //������β�ͣ�˵���ǵ�����
		{
			cout << "flag1"<< endl;
			return NULL;
		}
		q = q->next->next;
		p = p->next;
	}
}

int main()
{
	ListNode* head1;
	ListNode* head2;
	head2 = (ListNode*)malloc(sizeof(ListNode));
	head2->val = 1;
	cout << "������������ֵ��0��ʾΪ��" << endl;
	createLink(head1);
	cout << "�����õĵ��������£�" << endl;
	traverseLink(head1);
	cout << endl;
	createCircle(head2);
	cout << "�����õĻ��������£�" << endl;
	traverseCircle(head2);
	bool result1, result2;
	result1 = hasCycle(head1);
	result2 = hasCycle(head2);
	if (result1)
	{
		cout << "head1�����л�" << endl;
	}
	else
	{
		cout << "head1�����޻�" << endl;
	}
	if (result2)
	{
		cout << "head2�����л�" << endl;
	}
	else
	{
		cout << "head2�����޻�" << endl;
	}
	ListNode* entranceOfCircle1;
	ListNode* entranceOfCircle2;
	entranceOfCircle1 = detectCycle(head1);
	if (entranceOfCircle1)
	{
		cout << entranceOfCircle1->val << endl;
	}
	else
	{
		cout << "NULL" << endl;
	}
	entranceOfCircle2 = detectCycle(head2);
	if (entranceOfCircle2)
	{
		cout << entranceOfCircle2->val << endl;
	}
	else
	{
		cout << "NULL" << endl;
	}
	system("pause");
	return 0;
}