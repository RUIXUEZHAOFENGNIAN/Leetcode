#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*˼·���������ų��ִ���< n ʱ���Ϳ��Է����µ������š��������ų��ִ���С�������ų��ִ���ʱ���Ϳ��Է����µ������š�*/
void generateParenthesis(vector<string>&result, int n, string temp,int left, int right)  //ע��������
{
	if (left==n && right==n)   //��֦
	{
		result.push_back(temp);
		return;
	}
	if (left < n)
	{
		temp += "(";
		generateParenthesis(result, n,temp,left+1, right);
		temp.pop_back();   //����
	} 
	if (right < left)
	{
		temp += ")";
		generateParenthesis(result, n,temp,left, right+1);
		temp.pop_back();
	}
}

int main()
{
	int n;
	vector<string> result;
	int left = 0, right = 0;
	string temp;
	cin >> n;
	generateParenthesis(result,n,temp,left,right);
	for (size_t i = 0; i < result.size();i++)
	{
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}