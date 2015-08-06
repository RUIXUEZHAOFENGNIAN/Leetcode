#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	while (cin >> n)
	{
		v.push_back(n);
	}
	unsigned len = v.size();
	/*for (int i = 0; i < len-1; i+=2)
	{
		cout << v[i] + v[i+1]<< endl;
	}*/
	for (int i = 0,j=len-1; i < j; i++,j--)
	{
		cout << v[i] + v[j]<<endl;
	}
	system("pause");
	return 0;
}