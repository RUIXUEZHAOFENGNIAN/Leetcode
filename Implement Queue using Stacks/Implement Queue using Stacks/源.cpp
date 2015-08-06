#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//用两个栈模拟一个队列
stack<int> s1;
stack<int> s2;
// Push element x to the back of queue.
void push(int x) {
	while (!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
	s1.push(x);
}

// Removes the element from in front of queue.
void pop(void) {
	while (!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	s2.pop();
}

// Get the front element.
int peek(void) {
	while (!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	return s2.top();
}

// Return whether the queue is empty.
bool empty(void) {
	if (s1.empty() && s2.empty())
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