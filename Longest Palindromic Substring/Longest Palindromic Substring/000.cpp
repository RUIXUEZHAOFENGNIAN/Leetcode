#include<iostream>
#include<string>
#include<iterator>
using namespace std;

/*  //�㷨һ�������㷨����ٳ����еĻ����ֶΣ��Ƚϵó����ġ��������ʱ�临�Ӷ�o(n^3)��
bool isPalindrome(string &s,int start,int end)
{
	while (start<end)
	{
		if (s[start] == s[end])
		{
			start++;
			end--;
		}
		else
		{
			return false;
		}
	}
	return true;
}

string longestPalindrome(string s) 
{
	int len = s.length();
	int maxPalindrome = 0;    //������ֶ�
	int tempStart = 0;    //�����ֶ��±�
	int tempEnd = 0;
	for (size_t i = 0; i < len; i++)
	{
		int start = i;
		int end = len - 1;
		while (start<end)
		{
			if (isPalindrome(s, start, end))
			{
				if ((end-start+1)>maxPalindrome )
				{
					maxPalindrome = end - start + 1;
					tempStart = start;
					tempEnd = end;
				}
			}
			end--;
		}
	}
	cout <<tempStart<<"  "<<tempEnd<< endl;
	string result;
	for (size_t i = tempStart; i <= tempEnd; i++)
	{
		result.push_back(s[i]);
	}
	return result;
}
*/

//�㷨�����Ľ��������㷨���������⡣ʱ�临�Ӷ�o(n^2)
int lengthPalindromeOdd(string &s, int mid)
{
	int left = mid - 1;
	int right = mid + 1;
	int result = 1;
	while (left >= 0 && right<s.length() && (s[left] == s[right]))
	{
			result += 2;
			left--;
			right++;
	}
	return result;
}

int lengthPalindromeEven(string &s, int j)
{
	int left = j;
	int right = j + 1;
	int result = 0;
	while (left >= 0 && right<s.length() && (s[left] == s[right]))
	{
			result += 2;
			left--;
			right++;
	}
	return result;
}

string longestPalindrome(string s)
{
	int max = 1;
	int tempI = 0;
	bool flag = true; //ֵΪtrue��ʾ������������
	for (int i = 0; i < s.length(); i++)
	{
		//���������������ֶ��ж�
		int oddPalindrome = lengthPalindromeOdd(s, i);
		if (oddPalindrome > max)
		{
			max = oddPalindrome;
			flag = true;
			tempI = i;
		}
		//����ż���������ֶ��ж�
		int evenPalindrome = lengthPalindromeEven(s, i);
		if (evenPalindrome > max)
		{
			max = evenPalindrome;
			flag = false;
			tempI = i;
		}
	}
	cout << max << endl;
	string longestPalindrome;
	if (flag)
	{
		for (size_t i = (tempI - max / 2); i <= (tempI + max / 2); i++)
		{
			longestPalindrome.push_back(s[i]);
		}
	}
	else
	{
		for (size_t i = (tempI - max / 2 + 1); i <= (tempI + max / 2); i++)
		{
			longestPalindrome.push_back(s[i]);
		}
	}
	return longestPalindrome;
}

int main()
{
	string s = "cefabaabagh";
	cout<<longestPalindrome(s)<<endl;
	system("pause");
	return 0;
}