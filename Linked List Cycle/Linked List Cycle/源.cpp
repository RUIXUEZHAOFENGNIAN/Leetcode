#include<iostream>
#define N 6
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
	//head->next = p;
	for (size_t i = 2; i < N; i++)
	{
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		temp->val = i;
		p->next = temp;
		p = temp;
		
	}
	p->next = head;
}

//������
void traverseCircle(ListNode* head)
{
	cout << head->val<<" ";
	ListNode* q = head->next;
	while (q!=head)
	{
		cout << q->val << " ";
		q = q->next;
	}
	cout << endl;
	cout << "�뻷����" <<q->val << endl;
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
	system("pause");
	return 0;
}