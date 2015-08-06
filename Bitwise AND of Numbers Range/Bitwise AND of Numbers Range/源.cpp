#include<iostream>
using namespace std;

/*
//算法一：线性遍历，时间复杂度o(n),超时
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
//算法二：还是超时，呜呜呜
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
我们从最低位开始。如果这一组数字的最低位不相同的话，那这一位就肯定会被消掉，变成0.如果m!=n,那最低位肯定是要被消掉的，
因为最低位肯定会是一个0，一个1.这时，我们可以将m和n都右移一位，将最后一位忽略。此时，又有了新的一组m和n。如果此时m=n,
那结果就是m了。如果不是的话，那可以继续上一段的过程，将m和n右移一位。重复上述操作，直到m=n。这个时候，从低位往高位所有
进行与操作后结果为0的位数都已经被消掉，而高位的数字进行与操作不会发生变化，此时的m或者n再向左移动之前移动的位数，得到的
就是这一组数字按位与后的结果

//算法三：等价于 求 m 与 n 二进制编码中 同为1的前缀,分析如上
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

//算法四：利用n&(n-1)去掉n的末尾1
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