#include<iostream>
#include<map>
using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode* next;
	RandomListNode* random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL){}
};

//递归创建链表
void createRandomListNode(RandomListNode*& Listnode)
{
	int label;
	cin >> label;
	if (label == 0)
	{
		Listnode = NULL;
	}
	else
	{
		Listnode = (RandomListNode*)malloc(sizeof(RandomListNode));
		Listnode->label = label;
		createRandomListNode(Listnode->next);
	}
}

//递归遍历链表
void traverseListNode(RandomListNode* Listnode)
{
	if (Listnode)
	{
		cout << Listnode->label << " ";
		traverseListNode(Listnode->next);
	}
}


RandomListNode* copyRandomList(RandomListNode *head)
{
	/*
	if (!head)
	{
		return head;
	}
	RandomListNode* randomList;
	//复制主链表
   //复制头结点
	randomList = (RandomListNode*)malloc(sizeof(RandomListNode));
	randomList->label = head->label;
	RandomListNode* oldHead = head;
	RandomListNode* newHead = randomList;
	newHead->random = oldHead->random;
	//建立新旧链表的映射关系
	map<RandomListNode*, RandomListNode*> m;
	m[oldHead] = randomList;
	while (oldHead)                      //复制链表节点
	{
		RandomListNode* temp;
		oldHead = oldHead->next;
		if (oldHead)
		{
			temp = (RandomListNode*)malloc(sizeof(RandomListNode));
			temp->label = oldHead->label;
			randomList->next = temp;
			randomList = randomList->next;
			m[oldHead] = randomList;
		}
		else
		{
			randomList->next = NULL;;
		}
		randomList->random = oldHead->random;
	}*/
	/**
	* Definition for singly-linked list with a random pointer.
	* struct RandomListNode {
	*     int label;
	*     RandomListNode *next, *random;
	*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	* };
	*/
			map<RandomListNode*, RandomListNode*> relation;

			RandomListNode* copiedHead = NULL;
			RandomListNode* copiedPtr = NULL;
			RandomListNode* ptr = head;

			while (ptr != NULL)
			{
				RandomListNode* new_node = new RandomListNode(ptr->label);
				relation.insert(pair<RandomListNode*, RandomListNode*>(ptr, new_node));
				if (copiedHead == NULL)
				{
					copiedHead = new_node;
					copiedPtr = new_node;
				}
				else
				{
					copiedPtr->next = new_node;
					copiedPtr = copiedPtr->next;
				}
				copiedPtr->random = ptr->random;
				ptr = ptr->next;
			}

			ptr = head;
			copiedPtr = copiedHead;
			while (ptr != NULL)
			{
				if (ptr->random != NULL)
				{
					copiedPtr->random = relation[ptr->random];
				}
				copiedPtr = copiedPtr->next;
				ptr = ptr->next;
			}
			return copiedHead;
}

int main()
{
	RandomListNode* head;
	createRandomListNode(head);
	traverseListNode(head);
	cout << endl;
	RandomListNode* newHead = copyRandomList(head);
	traverseListNode(newHead);
	cout << endl;
	system("pause");
	return 0;
}