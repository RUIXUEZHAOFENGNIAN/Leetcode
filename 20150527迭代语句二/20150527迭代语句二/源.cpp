#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	/*练习5.20*/
	/*
	string s1, prestr;
	int flag = 0;
	while (cin>>s1 && !s1.empty())
	{
		if (s1[0]>'Z' || s1[0]<'A')
		{
			continue;
		}
		if (s1 == prestr)
		{
			cout << s1 << endl;
			flag = 1;
			break;
		}
		prestr = s1;
	}
	if (flag == 0)
	{
		cout << "no successive word" << endl;
	}
	*/

	/*5.6.3节练习：异常处理*/
	size_t num1, num2;
	//cout << "try again? Enter Y or N" << "\n" << endl;
	while (cin>>num1>>num2)
	{
		//if (num2 == 0)
		//{	throw runtime_error("除数不能为0");}
		try{
			if (num2 == 0) throw runtime_error("divisor is 0");
			cout << static_cast<double>(num1) / num2 << endl;
		} catch(runtime_error err){
			cout << err.what() << "\n"<< "Try again? Enter Y or N"<<endl;
			char c;
			cin >> c;
			if (c=='N')
			{
				break;
			}
		}
	}
	system("pause");
	return 0; 
}