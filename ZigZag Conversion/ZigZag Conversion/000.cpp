#include<iostream>
#include<string>
using namespace std;

/*http://blog.csdn.net/zhouworld16/article/details/14121477 */

int main()
{
	string s;
	cin >> s;
	int nRows;
	cin >> nRows;
	if (nRows <= 1 || s.length() == 0)
		cout<< s <<endl;

	string res = "";
	int len = s.length();
	for (int i = 0; i < len && i < nRows; ++i)
	{
		int indx = i;
		res += s[indx];

		for (int k = 1; indx < len; ++k)
		{
			//��һ�л����һ�У�ʹ�ù�ʽ1��  
			if (i == 0 || i == nRows - 1)
			{
				indx += 2 * nRows - 2;
			}
			//�м��У��ж���ż��ʹ�ù�ʽ2��3  
			else
			{
				if (k & 0x1)  //����λ  
					indx += 2 * (nRows - 1 - i);
				else indx += 2 * i;
			}

			//�ж�indx�Ϸ���  
			if (indx < len)
			{
				res += s[indx];
			}
		}
	}
	cout<< res<<endl;
	system("pause");
	return 0;
}