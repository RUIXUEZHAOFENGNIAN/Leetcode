#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode
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

ListNode* sortList(ListNode* head) {
	vector<int> element;
	ListNode* p = head;
	while (p)
	{
		element.push_back(p->val);
		p = p->next;
	}
	sort(element.begin(),element.end());
	p = head;
	while (p)
	{
		p->val = element.front();
		element.erase(element.begin());
		p = p->next;
	}
	return head;
}

int main()
{
	ListNode* head;
	createList(head);
	traverseList(head);
	cout << endl;
	ListNode* ret = sortList(head);
	traverseList(ret);
	cout << endl;
	system("pause");
	return 0;
}