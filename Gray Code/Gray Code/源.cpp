#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> result;
	int n;
	cin >> n;
	/*异或转换方法：二进制码转换成格雷码*/
	for (size_t i = 0; i < (1<<n); i++)
	{
		result.push_back(i^(i>>1));
	}
	for (auto &c : result)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}