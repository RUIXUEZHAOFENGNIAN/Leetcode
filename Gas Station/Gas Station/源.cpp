#include<iostream>
#include<vector>
using namespace std;

//贪心法  时间复杂度o(n)
//http://www.cnblogs.com/felixfang/p/3814463.html

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int total = 0;
	int diff = 0;
	int start = 0;
	for (size_t i = 0; i < gas.size(); i++)
	{
		int temp = gas[i] - cost[i];
		diff += temp;
		if (diff < 0)   //从x..i-1站，但无法到达i站,相差diff油，从i+1站开始考虑
		{
			total += diff;
			diff = 0;
			start = i+1;
		}
	}
	return (total + diff) < 0 ? -1 : start;
}

int main()
{
	vector<int> gas =  {1,2};
	vector<int> cost = {2,1};
	cout << canCompleteCircuit(gas,cost) << endl;
	system("pause");
	return 0;
}