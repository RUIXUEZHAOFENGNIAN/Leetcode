#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
	vector<int> numbers = { 2, 7, 11, 15 };
	map<int, int> mapping;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		mapping[numbers[i]] = i;
	}
	vector<int> result;
	int target = 9;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		const int temp = target - numbers[i];
		if (mapping.find(temp) != mapping.end() && mapping[temp] > i)
		{
			result.push_back(i+1);
			result.push_back(mapping[temp]+1);
			break;
		}
	}
	for (auto c:result)
	{
		cout << c << " ";
	}
	system("pause");
	return 0;
}