#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	long long num = 0;
	getline(cin, str);
	unsigned len = str.size();
	int i = 0;
	while (str[i] == ' ' && i<len)
	{
		i++;
	}
	int sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		sign = 1;
		i++;
	}
	else
	{
		sign = 1;
	}
	for (; i < len; i++)
	{
		if (str[i]<'0' || str[i] > '9')
		{
			break;
		}
		num = num * 10 + str[i] - '0';
		if (num > INT_MAX)
		{
			cout << INT_MAX << endl;
			break;
		}
		if (num < INT_MIN)
		{
			cout << INT_MIN << endl;
			break;
		}
	}
	
		cout << num*sign << endl;
	//s = transfor(s);
	
	system("pause");
	return 0;
}