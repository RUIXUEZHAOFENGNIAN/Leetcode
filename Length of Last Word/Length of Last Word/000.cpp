#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s;
	cin >> s;
	unsigned size = s.size();
	//cout << size << endl;
	int lw_len = 0;
	int k = size - 1;
	while (k>=0)
	{
		if (s[k]==' ')
		{
			k--;
			continue;
		}
		else
		{
			break;
		}
		
	}
	for (int i = k; i >= 0 && s[i] != ' '; --i, lw_len++);
	cout <<lw_len<< endl;
	system("pause");
	return 0;
}