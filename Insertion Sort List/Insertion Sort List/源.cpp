#include<iostream>
#define N 9
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

//递归构建链表
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

//递归遍历链表
void traverseLink(ListNode* head)
{
	if (head)
	{
		cout << head->val << " ";
		traverseLink(head->next);
	}
}

//插入排序
ListNode* insertionSortList(ListNode* head)
{
	if (!head || !head->next)
	{
		return head;
	}
	ListNode* p = head->next;   //要插入的节点
	ListNode* start = head;    //排好序的链表首节点
	ListNode* end = head;      //排好序的链表尾节点（非NULL）
	while (end->next)
	{
		if (p->val < start->val)                        //p->val比首元素小的情况下start节点会改变,end节点不变
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
		else if (p->val >= end->val)                                 //p->val比末尾元素大的话end节点会改变,start节点不变
		{
			end = p;
			p = p->next;
		}
		else                                                     //p->val在中间插入，首尾节点不变
		{
			ListNode* it = start;
			while (it != end)
			{
				if (p->val >= it->val && p->val < it->next->val) //找到插入位置
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
	cout << "请输入链表数值，0表示为空" << endl;
	createLink(head);
	cout << "构建好的单链表如下：" << endl;
	traverseLink(head);
	cout << endl;
	ListNode* result;
	result = insertionSortList(head);
	cout << "插入排序后的结果：" << endl;
	traverseLink(result);
	cout << endl;
	system("pause");
	return 0;
}

