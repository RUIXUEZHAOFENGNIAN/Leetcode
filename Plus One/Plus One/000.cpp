#include<iostream>
#include<vector>
using namespace std;

void plusOne(vector<int>& digits) {
	int c = 1;//½øÎ»
	for (auto it = digits.rbegin(); it != digits.rend(); it++)
	{
		int temp = *it + c;
		*it = temp % 10;
		c = temp / 10;
	}
	if (c > 0)
	{
		digits.insert(digits.begin(),c);
	}
}
int main()
{
	vector<int> v = {9,9,9};
	plusOne(v);
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout <<*it<<" " ;
	}
	system("pause");
	return 0;
}