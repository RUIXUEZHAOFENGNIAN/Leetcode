#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int trap(vector<int>& height) {
	if (height.size() < 3)
	{
		return 0;
	}
	int sum = 0;
	int l = 0;
	int r = height.size() - 1;
	while (l<r)
	{
		cout << "l = " << l << endl;
		cout << "r = " << r << endl;
		//�϶̵�һ�����м��ƶ�
		if (height[l]<height[r])
		{
			//���ְ���
			if (l + 2<=r && height[l] > height[l + 1])
			{
				sum -= height[l + 1];
				size_t toRight = l + 2;
				while (toRight <= r)
				{
					//�����ҵ��׸���nums[l]�����ڵ�Ԫ��
					if (height[toRight] >= height[l])
					{
						break;
					}
					sum -= height[toRight];
					++toRight;
					cout << "toRight = " << toRight << endl;
				}
				cout<<height[l] * (toRight - l - 1)<<endl;
				sum += height[l] * (toRight - l - 1);
				cout << "sum(Left) = " << sum << endl;
				l = toRight;
			}
			else
			{
				++l;
			}
		}
		else
		{
			//���ְ���
			if (r - 2 >= l && height[r-1] < height[r])
			{
				sum -= height[r - 1];
				size_t toLeft = r - 2;
				while (toLeft >= l)
				{
					//�����ҵ��׸���nums[r]�����ڵ�Ԫ��
					if (height[toLeft] >= height[r])
					{
						break;
					}
					sum -= height[toLeft];
					--toLeft;
				}
				sum += height[r] * (r - 1 - toLeft);
				cout << "sum(Right)  = " << sum << endl;
				r = toLeft;
			}
			else
			{
				--r;
			}
		}
	}
	return sum;
}

int main()
{
	vector<int> nums = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	cout << trap(nums) << endl;
	system("pause");
	return 0;
}