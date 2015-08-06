#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//用队列来模拟栈
queue<int> q1;
queue<int> q2;
// Push element x onto stack.
void push(int x) {
	q1.push(x);
	if (q1.size()>1)
	{
		q2.push(q1.front());
		q1.pop();
	}
}

// Removes the element on top of the stack.
void pop() {
	if (q1.size()==1)
	{
		q1.pop();
	}
	queue<int> temp;
	while (!q2.empty())
	{
		if (q2.size() == 1)
		{
			q1.push(q2.front());     //q1维持只有一个元素
		}
		else
		{
			temp.push(q2.front());
		}
		q2.pop();
	}
	while (!temp.empty())
	{
		q2.push(temp.front());
		temp.pop();
	}


}

// Get the top element.
int top() {
	if (q1.size() == 1)
	{
		return q1.front();
	}
}

// Return whether the stack is empty.
bool empty() {
	if (q1.empty() && q2.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	system("pause");
	return 0;
}