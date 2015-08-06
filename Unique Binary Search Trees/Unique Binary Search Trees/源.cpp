#include<iostream>
#include<vector>
using namespace std;

/*�Ӵ���������ĽǶ�������ѡȡһ�����Ϊ�����Ͱѽ���г�������������������Ϊ���Ŀ��ж�����
�������������������ж����������ĳ˻��������ܵ������ǽ������н��Ϊ���Ŀ��н���ۼ�����*/
int numTrees(int n) 
{
	if (n==0 || n==1)
	{
		return 1;
	}
	else
	{
		vector<int> temp;
		temp.push_back(1);
		temp.push_back(1);
		for (size_t i = 2; i <= n; i++)
		{
			int a = 0;
			for (size_t j = 0; j < i; j++)
			{
				a += (temp[j] * temp[i-j-1]);
			}
			temp.push_back(a);
		}
		return temp.back();
	}
}

int main()
{
	int n;
	cin >> n;
	int result = numTrees(n);
	cout << result << endl;
	system("pause");
	return 0;
}