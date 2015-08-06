#include<iostream>
#include<vector>
#include<string>
#include "7_41.h"
using namespace std;

/*
//person类

class Person
{
	friend istream& read(istream& is, Person& person);
	friend ostream& print(ostream& os, const Person& person);

    private:
	string name;
	string address;

    public:
	Person() = default;
	Person(const string s,const string a):name(s),address(a){}
	Person(istream& is){ read(is,*this); }
	string getName() const{ return name;}
	string getAddress() const{ return address; }
};

istream& read(istream& is,Person& person)
{
	is >> person.name >> person.address;
	return is;
}

ostream& print(ostream& os,const Person& person)
{
	os << person.name << " " << person.address;
	return os;
}*/

/*
//Sales_data类
class Sales_data 
{
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
	friend istream& read(istream& is, Sales_data& item);
	friend ostream& print(ostream& os, const Sales_data& item);
	//friend inline double avg_price() const;

    public:
	string isbn()const{ return bookNo; }
	Sales_data& combine(const Sales_data&);

	Sales_data() = default;
	Sales_data(const string& s,const unsigned n,const double r):bookNo(s),units_sold(n),revenue(r) {}
	Sales_data(istream& is){};

    private:
	inline double avg_price() const;

    private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline double Sales_data::avg_price() const
{

	return units_sold?revenue / units_sold:0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

istream& read(istream& is,Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

ostream& print(ostream& os,const Sales_data& item)
{
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return os;
}*/

/*
//Screen类

class Screen
{
	friend class window_mgr; 
	//friend void window_mgr::clear(ScreenIndex);
public:
	typedef string::size_type pos;
	Screen() = default;    //1
	Screen(pos ht, pos wt) :height(ht), width(wt),contents(ht*wt,' '){}
	Screen(pos ht,pos wt,char c):height(ht),width(wt),contents(ht*wt,c){}

	//读取光标处的字符
	char get() const
	{
		return contents[cursor];   //隐式内联
	}
	//显式内联
	inline char get(pos r, pos c) const
	{
		pos row = r*width;  //计算行的位置
		return contents[row+c];  //返回给定列的字符
	}
	Screen& move(pos r,pos c);

	Screen& set(char);
	Screen& set(pos,pos,char);

	Screen& display(ostream& os)
	{
		do_display(os);
		return *this;
	}
	const Screen& display(ostream& os) const
	{
		do_display(os);
		return *this;
	}

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

private:
	//该函数负责显示Screen的内容
	void do_display(ostream& os) const
	{
		os << contents;
	}
};

inline Screen& Screen::move(pos r,pos c)
{
	pos row = r*row;
	cursor = row + c;
	return *this;
}

inline Screen& Screen:: set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos r,pos col,char ch)
{
	contents[r*width+col] = ch;
	return *this;
}*/

/*
//window_mgr类

class window_mgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex);

private:
	vector<Screen> Screens{ Screen(24, 80, ' ') };
};

void window_mgr::clear(ScreenIndex i)
{
	if (i>=Screens.size())
	{
		return;
	}
	Screen& s = Screens[i];   //必须用引用，不然只是对副本操作
	s.contents = string(s.height*s.width, ' ');
}*/

/*
//类X和类Y
class X
{
private:
	Y* pY;
};

class Y
{
private:
	X x1;
};*/

/*
//Account类
class Account
{
public:
	void caculate(){ amount += amount*interestRate; }
	static double rate(){ return interestRate;}
	static void rate(double newRate){ interestRate = newRate; }

private:
	string owner;
	double amount;
	static double interestRate;
	static constexpr  int todyRate = 8.8;
	static double initRate(){ return todyRate; }
};

double Account::interestRate = initRate();*/

//exercise 7.36
/*
struct x
{
	x(int i, int j) : base(i), rem(base%j){};
	int rem, base;
};*/

//exercise 7.41 使用委托构造函数编写Sales_data类
// constructor
Sales_data::Sales_data(std::istream &is) : Sales_data()
{
	std::cout << "Sales_data(istream &is)" << std::endl;
	read(is, *this);
}

// member functions.
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

// friend functions
std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}


std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

//exercise 7.43
class NoDefault
{
public:
	NoDefault(int i){}
};

class C
{
public:
	C() : ND (0) {}
private:
	NoDefault ND;
};

int main()
{
	/*
	Sales_data total;  //保存当前求和结果的变量
	if (read(cin,total))  //读入第一笔交易
	{
		Sales_data trans;   //保存下一条交易数据的变量 
		while (read(cin,trans))  //读入剩余的交易
		{
			if (total.isbn() == trans.isbn())  //检查isbn
			{
				total.combine(trans);     //更新变量total当前的值
			}
			else
			{
				print(cout, total) << endl;  //输出结果
				total = trans;               //处理下一本书
			}
		}
		print(cout,total); //输出最后一条交易
	}
	else       //没有输入任何信息
	{
		cerr << "No data?!" << endl;  //通知用户  
	}*/

	//exercise 7.47
	/*
	应该是explicit的。这样能防止编译器进行隐式的类类型转换，即string对象转换为Sales_data对象，避免造成不必要的语义错误。加上explicit后，
	要创建Sales_data对象则必须显示地创建
	*/
	system("pause");
	return 0;
} 