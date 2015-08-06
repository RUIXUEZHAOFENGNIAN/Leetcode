#include<iostream>
#include<vector>
using namespace std;

	void dfs( int num[], int cur)
	{
		if (3 == cur)
		{
			//ret.push_back(num);
			//for (int i = 0; i < 3;i++)
			//{
			//	cout <<num[i]<< " ";
			//}
			printf("%d %d %d", num[0],num[1],num[2]); 
			cout << endl;
		}
		else
		{
			for (int i = cur; i < 3; ++i)
			{
				int temp = num[cur];
				num[cur] = num[i];
				num[i] = temp;
				dfs(num, cur + 1);
			    temp = num[cur];
				num[cur] = num[i];
				num[i] = temp;
				printf("######");
				cout << endl;
			}
		}
	}

int main()
{
	//vector<vector<int> > ret;
	int num[] = {1,2,3};
	dfs(num, 0);
	system("pause");
}