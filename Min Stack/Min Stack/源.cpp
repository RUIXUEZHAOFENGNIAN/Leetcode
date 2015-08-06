#include<iostream>
#include<stack>
using namespace std;

stack<int> stack1;
stack<int> stack2;

void push(int x) {
	stack1.push(x);
	if (stack2.empty() || x<stack2.top())
	{
		stack2.push(x);
	}
}

void pop() {
	if (stack1.top() == stack2.top())
	{
		stack2.pop();
	}
	stack1.pop();
}

int top() {
	return stack1.top();

}

int getMin() {
	return stack2.top();
}

int main()
{
	system("pause");
	return 0;
}