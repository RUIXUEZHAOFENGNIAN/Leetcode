#include<iostream>
#include<vector>
using namespace std;

/*�����������������ڵĲ��������������ͬһ�������������в��֮�� = �������۸� -  ������С�۸�*/
int maxProfit(vector<int>& prices)
{
	int result = 0;
	for (size_t i = 0; i+1 < prices.size(); i++)
	{
		if (prices[i+1]>prices[i])
		{
			result += (prices[i+1] - prices[i]);
		}
	}
	return result;
}

int main()
{
	vector<int> prices = {4,9,4,6};
	int result = maxProfit(prices);
	cout << result << endl;
	system("pause");
	return 0;
}