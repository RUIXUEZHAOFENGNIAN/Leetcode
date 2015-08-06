#include<iostream>
#include<string>
using namespace std;

void oneBitMultiply(int c, string& num, string& tempString)
{
	int add = 0;//进位
	for (auto it = num.rbegin(); it != num.rend(); it++)
	{
		int tempNum = c * (*it-'0') + add;
		tempString.insert(tempString.begin(), (char)('0' + tempNum % 10));
		add = tempNum / 10;
	}
	if (add>0)
	{
		tempString.insert(tempString.begin(),'0'+add);
	}
}

void addTwoString(string& ret,string& temp)
{
	if (!ret.empty())
	{
		int add = 0; //进位
		auto it1 = temp.rbegin();
		auto it2 = ret.rbegin();
		while (it2 != ret.rend())
		{
			int num = add + (*it1 - '0') + (*it2 - '0');
			*it1 = '0' + num % 10;
			add = num / 10;
			it1++;
			it2++;
		}
		while (it1 != temp.rend())
		{
			int num = add + (*it1 - '0');
			*it1 = '0' + num % 10;
			add = num / 10;
			it1++;
		}
		if (add>0)
		{
			temp.insert(temp.begin(), '0' + add);
		}
	}
	ret = temp;
}

string multiply(string num1, string num2) {
	string ret;
	int i = 0;
	for (auto it = num2.rbegin(); it != num2.rend(); it++)
	{
		string temp(i++, '0');
		oneBitMultiply(*it-'0',num1,temp);
		cout << "temp = " << temp << endl;
		addTwoString(ret,temp);
		cout << "ret = " << temp << endl;
		temp.clear();
	}
	return ret;
}

int main()
{
	string num1;
	string num2;
	cin >> num1 >> num2;
	cout << "the multiply of num1 and num2 is: "<< multiply(num1,num2) << endl;
	system("pause");
	return 0;
}