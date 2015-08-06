#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

/*
//�㷨һ �����������ÿ���±꿪ʼ�����������������,���ϳ�ʱ����
int compute(int start,vector<int>& height)
{
	int max = height[start];
	int ht = height[start];
	for (size_t i = start+1; i < height.size(); i++)
	{
		ht = min(ht, height[i]);
		if (ht*(i+1-start)>max)
		{
			max = ht*(i + 1 - start);
		}
	}
	return max;
}

int largestRectangleArea(vector<int>& height) {
	if (height.size() == 0)
	{
		return 0;
	}
	int maxArea = 0;
	for (size_t j = 0; j < height.size(); j++)
	{
			int curArea = compute(j,height);
			if (curArea > maxArea)
			{
				maxArea = curArea;
			}
	}
	return maxArea;
}*/

/*
int largestRectangleArea(vector<int>& height) {
	height.push_back(0);
	stack<int> stk;
	int i = 0;
	int maxArea = 0;
	while (i < height.size()){
		if (stk.empty() || height[stk.top()] <= height[i]){
			stk.push(i++);
			cout << "i = "<< i << endl;
		}
		else {
			int t = stk.top();
			stk.pop();
			maxArea = max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));
			cout << maxArea << endl;
		}
	}
	return maxArea;
}*/

int largestRectangleArea(vector<int>& height) {
	height.push_back(0);   	//heightĩβ����Ԫ��0���ܰ�ջ������Ԫ�ص���
	stack<int> stk;
	int maxArea = 0;
	int i = 0;
	while (i < height.size())
	{
		if (stk.empty() || height[i] >= height[stk.top()])   //����ջ��Ԫ�ص�����Ҳ����˵��һ��Ԫ������С��
		{
			stk.push(i++);
		}
		else                   //��ջ�������
		{
			int temp = stk.top();
			stk.pop();
			cout << "stk.size() = "<<stk.size()<< endl;
			cout <<"i = "<<i<< "  width = " <<( stk.empty() ? i : i - stk.top() - 1)<< endl;
			int curArea = height[temp] * (stk.empty() ? i : i - stk.top()-1);
			//int curArea = height[temp] * (i-temp);
			cout << "index = " << temp << "   curArea = " << curArea << endl;
			if (curArea > maxArea)
			{
				maxArea = curArea;
			}
		}
	}
	return maxArea;
}

int main()
{
	vector<int> height = { 2, 1, 5, 6, 2, 3};
	vector<int> height1 = {2, 1, 2 };
	vector<int> height2 = {4, 2, 0, 3, 2, 5};
	cout<< largestRectangleArea(height) <<endl;
	system("pause");
	return 0;
}