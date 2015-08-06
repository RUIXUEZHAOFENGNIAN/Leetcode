#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

void createLink(ListNode*& head)
{
	int val;
	cin >> val;
	if (val==0)
	{
		head = NULL;
	}
	else
	{
		head = new ListNode(val);
		createLink(head->next);
	}
}

void traverseLink(ListNode* head)
{
	if (head)
	{
		cout << head->val << " ";
		traverseLink(head->next);
	}
}

/*
//算法一：时间复杂度o(n),空间复杂度o(n)
bool isPalindrome(ListNode* head) {
	if (!head || !head->next)
	{
		return true;
	}
	//把链表数据放到数组里面
	ListNode* p = head;
	vector<int> numberOfLink;
	while (p)
	{
		numberOfLink.push_back(p->val);
		p = p->next;
	}
	delete p;
	int start = 0;
	int end = numberOfLink.size() - 1;
	while (start <= end)
	{
		if (numberOfLink[start] != numberOfLink[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}*/

//算法二 时间复杂度o(n),空间复杂度o(1)
void dfs(ListNode*& head,ListNode* tail,bool& flag)
{
	if (tail->next)
	{
		dfs(head,tail->next,flag);
	}
	cout << head->val << " " << tail->val << endl;
	if (head->val != tail->val)
	{
		flag = false;
		return;
	}
	head = head->next;
}

bool isPalindrome(ListNode* head) {
	if (!head || !head->next)
	{
		return true;
	}
	ListNode* tail = head;
	bool flag = true;
	dfs(head,tail,flag);
	return flag;
}


int main()
{
	ListNode* head;
	createLink(head);
	traverseLink(head);
	cout << endl;
	if (isPalindrome(head))
	{
		cout<< "Yes" <<endl;
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}