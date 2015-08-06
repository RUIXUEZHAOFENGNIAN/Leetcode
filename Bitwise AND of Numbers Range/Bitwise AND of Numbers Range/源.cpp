#include<iostream>
using namespace std;

/*
//�㷨һ�����Ա�����ʱ�临�Ӷ�o(n),��ʱ
int rangeBitwiseAnd(int m, int n) {
	for (int i = m+1;  i <= n;  i++)
	{
		m &= i;
	}
	return m;
}*/

void process(int num,int* bit)
{
	int i = 0;
	while (num)
	{
		int temp = num % 2;
		if (temp == 0 && bit[i] == 1)
		{
			bit[i] = 0;
		}
		num /= 2;
		i++;
	}
	while (i<32)
	{
		bit[i++] = 0;
	}
}

/*
//�㷨�������ǳ�ʱ��������
int rangeBitwiseAnd(int m, int n) {

	int bit[32];
	for (auto &c : bit)
	{
		c = 1;
	}
	for (int i = m; i <= n; i++)
	{
		process(i,bit);
		bool flag = false;
		for (auto &c:bit)
		{
			if (c==1)
			{
				flag = true;
				break;;
			}
		}
		if (flag)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	for (auto &c:bit)
	{
		cout << c << " ";
	}
	cout << endl;
	int result = 0;
	int temp = 1;
	for (size_t i = 0; i < 32; i++)
	{
		result += bit[i] * temp;
		temp *= 2;
	}
	return result;
}*/

/*
���Ǵ����λ��ʼ�������һ�����ֵ����λ����ͬ�Ļ�������һλ�Ϳ϶��ᱻ���������0.���m!=n,�����λ�϶���Ҫ�������ģ�
��Ϊ���λ�϶�����һ��0��һ��1.��ʱ�����ǿ��Խ�m��n������һλ�������һλ���ԡ���ʱ���������µ�һ��m��n�������ʱm=n,
�ǽ������m�ˡ�������ǵĻ����ǿ��Լ�����һ�εĹ��̣���m��n����һλ���ظ�����������ֱ��m=n�����ʱ�򣬴ӵ�λ����λ����
�������������Ϊ0��λ�����Ѿ�������������λ�����ֽ�����������ᷢ���仯����ʱ��m����n�������ƶ�֮ǰ�ƶ���λ�����õ���
������һ�����ְ�λ���Ľ��

//�㷨�����ȼ��� �� m �� n �����Ʊ����� ͬΪ1��ǰ׺,��������
int rangeBitwiseAnd(int m, int n) {
	int i = 0;
	while (m != n)
	{
		m >>= 1;
		n >>= 1;
		++i;
	}
	return m << i;
}*/

//�㷨�ģ�����n&(n-1)ȥ��n��ĩβ1
int rangeBitwiseAnd(int m, int n) {
	while (n>m)
	{
		n = n&(n-1);
	}
	return n;
}

int main()
{
	int m;
	int n;
	cin >> m >> n;
	cout<<rangeBitwiseAnd(m,n)<<endl;
	system("pause");
	return 0;
}