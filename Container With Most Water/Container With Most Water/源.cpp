#include<iostream>
#include<vector>
using namespace std;

/*
//������ⷨ--ʱ�临�Ӷ�o(n^2)
int maxArea(vector<int>& height)
{
	if (height.size() == 0 || height.size() == 1)
	{
		return 0;
	}
	int max = 0;
	for (size_t i = 0; i < height.size()-1; i++)
	{
		for (size_t j = i + 1; j < height.size(); j++)
		{
			if (height[j]>height[i] && j != height.size()-1)
			{
				continue;
			}
			int h = height[i] >= height[j] ? height[j] : height[i]; //���εĸ߶��Խ϶̵��߶�Ϊ׼
			int area = h * (j-i);
			if (area>max)
			{
				max = area;
				cout << "max = " << max << endl;
			}
		}
	}
	return max;
}
*/

//̰�Ĳ���--ʱ�临�Ӷ�
int maxArea(vector<int>& height)
{
	if (height.size() == 0 || height.size() == 1)
	{
		return 0;
	}
	int max = 0;
	int i = 0;
	int j = height.size()-1;
	while (i<j)
	{
		int area = 0;
		int h = height[i] >= height[j] ? height[j] : height[i]; //���εĸ߶��Խ϶̵��߶�Ϊ׼
		area = h * (j - i);
		if (area > max)
		{
			max = area;
		}
		if (height[j] >= height[i])
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return max;
}

int main()
{
	vector<int> height;
	int val;
	while (cin>>val)
	{
		height.push_back(val);
	}
	int result = maxArea(height);
	cout << "max = " <<result << endl;
	system("pause");
	return 0;
}