#include<iostream>
#include<string>
using namespace std;

int transf(char c)
{
	switch (c)
	{
	case 'I':return 1; break;
	case 'V':return 5; break;
	case 'X':return 10; break;
	case 'L':return 50; break;
	case 'C':return 100; break;
	case 'D':return 500; break;
	case 'M':return 1000; break;
	default:
		break;
	}
}
int main()
{
	string s;
	cin >> s;
	int result = 0;
	for (int i = 0; i < s.size();i++)
	{
		if (i + 1 < s.size() && transf(s[i]) < transf(s[i + 1]))
		{ 
			result += (transf(s[i+1]) - transf(s[i]));
			i++;
		}
		else
		{
			result += transf(s[i]);
		}
	}
	cout <<result<< endl;
	system("pause");
	return 0;
}