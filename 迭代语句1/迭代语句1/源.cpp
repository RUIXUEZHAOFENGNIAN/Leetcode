#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	//��¼�����ظ����ֵ��������Լ���Ӧ�ĵ���
	size_t cnt = 0, maxCnt = 0;
	string ch, maxCh, preCh = "\0";
	while (getline(cin, ch))
	{
	if (ch==preCh)
	{
	++cnt;
	//continue;
	}
	else
	{
	cnt=0;
	}
	if (cnt>maxCnt)
	{
		maxCh = ch;
		maxCnt = cnt;
	}
	preCh = ch;
	}
	cout << maxCh << endl;
	cout << maxCnt + 1 << endl;
	system("pause");
	return 0;
}