#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
int compare(const void* a,const void* b)
{
	int* pa = (int*)a;
	int* pb = (int*)b;
	return (*pa) - (*pb);  //ÉýÐò
}
*/

int maxProfit(vector<int>& prices) 
{
	if (prices.size() == 0) return 0;
	int maxProfit = 0;
	int minPrice = prices[0];
	for (size_t i = 1; i < prices.size(); i++)
	{
		if ((prices[i] - minPrice) > maxProfit)
		{
			maxProfit = prices[i] - minPrice;
		}
		if (prices[i]<minPrice)
		{
			minPrice= prices[i];
		}
	}
	return maxProfit;
}

int main()
{
	vector<int> price = {1,2,9,5,13,3,5,4,3,7,15,8,1};
	int result = maxProfit(price);
	cout << result << endl;
	system("pause");
	return 0;
}