#include<iostream>
using namespace std;

int main()
{
	int x[10];
	int *p = x;
	cout <<sizeof(x)/sizeof(*x) << endl;
	cout << p << endl;
	cout <<*p<< endl;
	cout << sizeof(p) / sizeof(*p) << endl;
	system("pause");
}