#include<iostream>
#include <stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

void qsort(int *low,int *high)
{
	int *temp_low = low;
	int *temp_high = high;
	int key = *low;
	while (low<=high)
	{
		while (low<high && *high>=key)
		{
			--high;
		}
		//int temp = *low;
		*low = *high;
		//*high = *low;
		while (low<high && *low <= key)
		{
			++low;
		}
		//int temp = *low;
		*high = *low;
		//*high = *low;
	}
	*low = key;
	qsort(temp_low, low - 1);
	qsort(high+1,temp_high);
}

int main()
{
	vector<int> nums = {1,2,3,2,4,2,5,2,7,2,6,2,2,2};
	int n = nums.size();
	qsort(&nums[0],&nums[n-1]);
	/*·½·¨Ò»*/
	/*
	sort(nums.begin(),nums.end());  
    cout<<nums[n/2]<<endl;
	*/
	for (size_t i = 0; i < n; i++)
	{
		cout << nums[i] << " ";
	}
	system("pause");
	return 0;
}