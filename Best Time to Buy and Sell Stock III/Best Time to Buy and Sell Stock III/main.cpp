#include<iostream>
#include<vector>
using namespace std;

/*ʱ�临�Ӷ�o(longN),�ֳ�0��i��i��n�������䣬��ǰ��������ֱ�ɨ��prices�õ�0��i��n��i���������*/
int maxProfit(vector<int>& prices)
{
	if (prices.size() == 0)
	{
		return 0;
	}
	vector<int> profit(prices.size(),0);
	cout << profit.size() << endl;
	for (auto &c : profit)
		cout << c << " ";
	cout << endl;
	int miniPrice = prices[0];
	int max = 0;
	for (size_t i = 1; i < prices.size(); i++)
	{
		if (prices[i]<miniPrice)
		{
			miniPrice = prices[i];
		}
		if ((prices[i] - miniPrice)>max)
		{
			max = prices[i] - miniPrice;
			profit[i] = max;
		}
		else
		{
			profit[i] = max;
		}
	}
	for (auto &c : profit)
		cout << c << " ";
	cout << endl;
	vector<int> reverseProfit(prices.size(), 0);
	int maxPrices = prices[prices.size()-1];
	cout << maxPrices << endl;
	cout << reverseProfit.size() << endl;
	cout << prices.size() << endl;
	for (auto &c : reverseProfit)
		cout << c << " ";
	cout << endl;
	int i = prices.size() - 2;
	int reverseMax = 0;
	while (i>=0)
	{
		if (prices[i]>maxPrices)
		{
			maxPrices = prices[i];
		}
		if ((maxPrices - prices[i])>reverseMax)
		{
			reverseMax = maxPrices - prices[i];
			reverseProfit[i] = reverseMax;
		}
		else
		{
			reverseProfit[i] = reverseMax;
		}
		--i;
	}
	for (auto &c : reverseProfit)
		cout << c << " ";
	cout << endl;
	int result = 0;
	for (size_t i = 0; i < prices.size(); i++)
	{
		int temp = profit[i] + reverseProfit[i];
		if (temp>result)
		{
			result = temp;
		}
	}
	return result;
}

int main()
{
	//vector<int> prices = { 4, 9, 4, 2, 4, 3, 8, 6, 3, 9, 6, 2, 1, 5};
	vector<int> prices = { 2, 1, 2, 0, 1 };
	int result = maxProfit(prices);
	cout << result << endl;
	system("pause");
	return 0;
}