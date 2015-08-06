#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle) {
	if (needle.size() == 0)  return 0;
	if (haystack.size() == 0 || haystack.size()<needle.size())  return -1;
	int lenght = haystack.size() - needle.size();
	size_t i = 0;
	while (i <= lenght)
	{
		//在haystack中找到needle的首字母
		while (i<=lenght && haystack[i] != needle[0])
		{
			i++;
		}
		cout << haystack[i] << endl;
		size_t j = 0;
		size_t k = i;
		while (j<needle.size())
		{
			if (haystack[k] != needle[j])
			{
				break;
			}
			k++;
			j++;
			if (j == needle.size())
			{
				return i;
			}
		}
		i++;
	}
	return -1;
}

int main()
{
	string haystack;
	string needle;
	cin >> haystack;
	cin >> needle;
	cout << haystack << endl;
	cout << needle << endl;
	int index = strStr(haystack,needle);
	cout << "index = " <<index << endl;
	system("pause");
	return 0;
}