#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string new_s = "1";
	for (size_t i = 1; i <n; i++)
	{
		string old_s = new_s;
		new_s.clear();
		int count = 1;
		for (size_t j = 0; j < old_s.size(); j++)
		{
			
			if (j + 1<old_s.size() && old_s[j] == old_s[j+1])
			{
				count++;
			}
			else
			{
				new_s += to_string(count) + old_s[j];
				count = 1;
			}
		}
	}
	cout << new_s << endl;
	system("pause");
	return 0;
}