#include<iostream>
#include<string>
#include<vector>
using namespace std;

int judge(char left,char right)
{
	if (left == '(' && right == ')')  return 1;
	if (left == '[' && right == ']')  return 1;
	if (left == '{' && right == '}')  return 1;
	return 0;
}

int main()
{
	vector<char> v;
	string s;
	cin >> s;
	if (s.size() < 2)
		cout << "´íÎó" << endl;
	int index = 0;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		v.push_back(*it);
		index++;
		if (v.size() > 1)
		{
			if (judge(v[index-2], v[index-1]))
			{
				v.pop_back(); index--;
				v.pop_back(); index--;
			}
		}
	}
	if (v.size() == 0)
		cout << "ÕýÈ·" << endl;
	system("pause");
	return 0;
}