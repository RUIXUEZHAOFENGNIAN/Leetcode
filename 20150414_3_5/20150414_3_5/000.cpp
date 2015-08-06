#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int num[5] = {10,20,30,40,50};
	int ia[3][4] = { {0,1,2,3}, {4,5,6,7}, {8,9,10,11} };
	//using int_array = int[4];
//	typedef int int_array[4];
	for (int (*p)[4] = ia; p != ia+3; p++)
	{
		for (int *q = *p; q != *p+4; q++)
		{
			cout <<*q<<" ";
		}
		cout << endl;
	}
	vector<int> v(begin(num),end(num));
	for (auto n:v)
	{
		cout << n << endl;
	}
	system("pause");
	return 0;
}