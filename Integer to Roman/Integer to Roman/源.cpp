#include<iostream>
#include<string>
using namespace std;

//Input: the range from 1 to 3999
string intToRoman(int num) {
	string ret;
	while (num)
	{
		if (num>=1000)
		{
			ret += 'M';
			num -= 1000;
		}
		else if (num >= 900)
		{
			ret += "CM";
			num -= 900;
		}
		else if (num >= 800)
		{
			ret += "DCCC";
			num -= 800;
		}
		else if (num>=700)
		{
			ret += "DCC";
			num -= 700;
		}
		else if (num>=600)
		{
			ret += "DC";
			num -= 600;
		}
		else if (num >= 500)
		{
			ret += "D";
			num -= 500;
		}
		else if (num >= 400)
		{
			ret += "CD";
			num -= 400;
		}
		else if (num >= 300)
		{
			ret += "CCC";
			num -= 300;
		}
		else if (num >= 200)
		{
			ret += "CC";
			num -= 200;
		}
		else if (num >= 100)
		{
			ret += "C";
			num -= 100;
		}
		else if (num >= 90)
		{
			ret += "XC";
			num -= 90;
		}
		else if (num >= 80)
		{
			ret += "LXXX";
			num -= 80;
		}
		else if (num >= 70)
		{
			ret += "LXX";
			num -= 70;
		}
		else if (num >= 60)
		{
			ret += "LX";
			num -= 60;
		}
		else if (num >= 50)
		{
			ret += "L";
			num -= 50;
		}
		else if (num >= 40)
		{
			ret += "XL";
			num -= 40;
		}
		else if (num >= 30)
		{
			ret += "XXX";
			num -= 30;
		}
		else if (num >= 20)
		{
			ret += "XX";
			num -= 20;
		}
		else if (num >= 10)
		{
			ret += "X";
			num -= 10;
		}
		else if (num == 9)
		{
			ret += "IX";
			num -= 9;
		}
		else if (num == 8)
		{
			ret += "VIII";
			num -= 8;
		}
		else if (num == 7)
		{
			ret += "VII";
			num -= 7;
		}
		else if (num == 6)
		{
			ret += "VI";
			num -= 6;
		}
		else if (num == 5)
		{
			ret += 'V';
			num -= 5;
		}
		else if (num == 4)
		{
			ret += "IV";
			num -= 4;
		}
		else if (num == 3)
		{
			ret += "III";
			num -= 3;
		}
		else if (num == 2)
		{
			ret += "II";
			num -= 2;
		}
		else if (num == 1)
		{
			ret += 'I';
			num -= 1;
		}
	}
	return ret;
}

int main()
{
	int num;
	cin >> num;
	cout<<intToRoman(num)<<endl;
	system("pause");
	return 0;
}