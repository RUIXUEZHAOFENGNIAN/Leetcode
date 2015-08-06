#include<iostream>
using namespace std;

//��������С��X��Ԫ�طŵ�Xǰ������X��Ԫ�طŵ�X�󣬲����������ֱ�����ǰ�����˳��
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

//����������һ��head������С��x��Ԫ�ط���head1�������ڵ���x������ŵ�head2����Ȼ���head2����head1��
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
	cout << "head���� ";
	traverseList(head);
	cout << endl;
	int x;
	cin >> x;
	ListNode* ret = partition(head,x);
	traverseList(ret);
	system("pause");
	return 0;
}