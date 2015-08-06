#include<iostream>
using namespace std;

void reverse(int *left,int *right)
{
	while (left<=right)
	{
		int temp = *right;
		*right = *left;
		*left = temp;
		left++;
		right--;
	}
}
int main()
{
	int n = 6,k=3;
	k = k % n;
	int nums[7] = {1,2,3,4,5,6};
	
	/*方法一*/
	/*
	int j = 0,temj[7];
	for (size_t i = n - k; i<n; i++)
	{
		temj[j++] = nums[i];
	}
	for (size_t i = 0; i<n - k; i++)
	{
		temj[j++] = nums[i];
	}
	for (size_t i = 0; i<n; i++)
	{
		nums[i] = temj[i];
	}
	for (size_t i = 0; i<n; i++)
	{
		cout<<nums[i]<<" ";
	}*/

	/*方法二*/
	/*
	for (size_t i = 0; i < k; i++)
	{
		int temp = nums[n - 1];
		for (size_t j = n-1; j> 0; j--)
		{
			nums[j] = nums[j-1];
		}
		nums[0] = temp;
	}
	for (size_t i = 0; i<n; i++)
	{
		cout << nums[i] << " ";
	}
	*/
	/*方法三*/
	reverse(&nums[0],&nums[n-1]);
	reverse(&nums[0], &nums[k - 1]);
	reverse(&nums[k], &nums[n - 1]);
	for (size_t i = 0; i<n; i++)
	{
		cout << nums[i] << " ";
	}
	system("pause");
	return 0;
}