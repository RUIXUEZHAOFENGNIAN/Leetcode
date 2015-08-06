#include<iostream>
#include<string>
#include<fstream>
using namespace std;
/*
class Sales_data {
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p)
	{
		std::cout << "Sales_data(const std::string&, unsigned, double)" << std::endl;
	}

	Sales_data() : Sales_data("", 0, 0.0f)
	{
		std::cout << "Sales_data()" << std::endl;
	}

	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f)
	{
		std::cout << "Sales_data(const std::string&)" << std::endl;
	}

	Sales_data(std::istream &is);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

private:
	inline double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline
double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

// declarations for nonmember parts of the Sales_data interface.
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);*/

class Sales_data
{
	friend istream& read(istream& is, Sales_data &item);
	friend ostream& print(ostream& os, const Sales_data &item);
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
public:
	//接受三个实参的默认构造函数
	Sales_data(string s, unsigned cnt, double price) :bookNo(s), units_sold(cnt), revenue(cnt*price)
	{
		cout << "Sales_data(string s, unsigned cnt, double price)" << endl;
	}
	//其余构造函数全都委托给另一个构造函数
	Sales_data() :Sales_data("", 0, 0)
	{
		cout << "Sales_data()" << endl;
	}
	Sales_data(string s) :Sales_data(s,0,0)
	{
		cout << "Sales_data(string s)" << endl;
	}
	Sales_data(istream &is);
	Sales_data& combine(const Sales_data&);
	//返回书版本号
	string isbn() const { return bookNo;}

private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	inline double avg_price() const{ return units_sold ? revenue / units_sold : 0; };
};

//declarations for nonmember parts of the Sales_data interface
//Sales_data类中的非成员函数声明
istream& read(istream& is,Sales_data &item);
ostream& print(ostream& os,const Sales_data &item);
Sales_data add(const Sales_data &lhs,const Sales_data &rhs);