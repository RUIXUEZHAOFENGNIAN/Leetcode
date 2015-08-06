#include<iostream>
#include<vector>
using namespace std;

//À„∑®“ª£∫o(n)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	vector<int> temp;
	for (auto &c:matrix)
	{
		for (auto &c1:c)
		{
			temp.push_back(c1);
		}
	}
	//int lenght = matrix.size() * matrix[0].size();
	int low = 0;
	int high = temp.size()-1;
	while (low<=high)
	{
		int mid = (low + high) / 2;
		if (temp[mid] == target)
		{
			return true;
		}
		else if (target>temp[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return false;
}

int main()
{
	vector<vector<int>> matrix = { { 1, 3, 5, 7 },
	                               { 10, 11, 16, 20 },
	                               { 23, 30, 34, 50 } };
	bool ret = searchMatrix(matrix,3);
	if (ret)
	{
		cout << "find it" << endl;
	}
	else
	{
		cout << "not find it" << endl;
	}
	system("pause");
	return 0;
}