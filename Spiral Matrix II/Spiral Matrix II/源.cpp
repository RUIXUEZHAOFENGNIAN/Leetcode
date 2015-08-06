#include<iostream>
#include<vector>
using namespace std;

void traverseVV(vector<vector<int>>& ret)
{
	for (size_t i = 0; i < ret.size(); i++)
	{
		for (auto& c:ret[i])
		{
			cout << c << " ";
		}
		cout << endl;
	}
}

void addElement(vector<vector<int>>& ret,int leftTop,int rightBottom,int& num)
{
	if (leftTop == rightBottom)
	{
		ret[leftTop][rightBottom] = num;
	}
	else
	{
		for (size_t i = leftTop; i <= rightBottom; i++)   //上面一行
		{
			ret[leftTop][i] = num++;
		}
		for (size_t i = leftTop+1; i <= rightBottom; i++)  //右边一列
		{
			ret[i][rightBottom] = num++;
		}
		for (size_t i = rightBottom-1; i >leftTop; i--)   //下面一行
		{
			ret[rightBottom][i] = num++;
		}
		for (size_t i = rightBottom; i > leftTop; i--)   //左边一列
		{
			ret[i][leftTop] = num++;
		}
	}
}

vector<vector<int>> generateMatrix(int n) {
	vector<int> temp(n, 0);
	vector<vector<int>> ret(n, temp);
	int leftTop = 0;
	int rightBottom = n - 1;
	int num = 1;
	while (leftTop<=rightBottom)
	{
		addElement(ret,leftTop,rightBottom,num);
		++leftTop;
		--rightBottom;
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>>  result;
	result = generateMatrix(n);
	traverseVV(result);
	system("pause");
	return 0;
}