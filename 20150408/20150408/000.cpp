#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
	string line;
	while (getline(cin,line))
	cout << line <<endl;
	system("pause");
	return 0;
}