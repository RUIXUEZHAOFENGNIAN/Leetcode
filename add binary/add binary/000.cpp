#include<iostream>
#include<string>
#include<iterator>
using namespace std;

string reverse(string s,int n)
{
	string temp;
	for (int i = n; i >=0; i--)
	{
		temp += s[i];
	}
	return temp;
}
int main()
{
	string a, b,s3;
	string::iterator it1, it2,it3;
	cin >> a;
	cin >> b;
	int len1 = a.size()-1,len2 = b.size()-1,len_min;
	len_min = len1 < len2 ? len1 : len2;
	string re_a = reverse(a,len1);
	string re_b = reverse(b, len2);
	string s_long = re_a.size() > re_b.size() ? re_a : re_b;
	cout << re_a<< endl;
	cout << re_b<< endl;
	int add = 0;
	for (int i = 0;i<=len_min;i++)
	{
		int temp = (re_a[i] - '0') + (re_b[i] - '0') + add;
		switch (temp)
		{
		case 3:s3 += '1', add = 1; break;
		case 2:s3 += '0', add = 1; break;
		case 1:s3 += '1', add = 0; break;
		case 0:s3 += '0', add = 0; break;
		default:
			break;
		}
	}
	cout << add<< endl;
	cout << len_min<< endl;
	cout << s_long.size() << endl;
	cout << s_long<< endl;
	for (int j = len_min + 1; j < s_long.size();j++)
	{
		if (s_long[j]-'0'+add == 2)
		{ 
			s3 += '0';
			add = 1;
		}
	    if(s_long[j] - '0' + add == 1)
		{
			s3 += '1';
			add = 0;
		}
		if (s_long[j] - '0' + add == 0)
		{
			s3 += '0';
			add = 0;
		}
	}
	if (add == 1)
	{
		s3 += '1';
	}
	cout << s3<< endl;
	cout << reverse(s3, s3.size() - 1) << endl;
	system("pause");
	return 0;
}