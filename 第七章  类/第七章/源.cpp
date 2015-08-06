#include<iostream>
#include<vector>
#include<string>
#include "7_41.h"
using namespace std;

/*
//person��

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
//Sales_data��
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
//Screen��

class Screen
{
	friend class window_mgr; 
	//friend void window_mgr::clear(ScreenIndex);
public:
	typedef string::size_type pos;
	Screen() = default;    //1
	Screen(pos ht, pos wt) :height(ht), width(wt),contents(ht*wt,' '){}
	Screen(pos ht,pos wt,char c):height(ht),width(wt),contents(ht*wt,c){}

	//��ȡ��괦���ַ�
	char get() const
	{
		return contents[cursor];   //��ʽ����
	}
	//��ʽ����
	inline char get(pos r, pos c) const
	{
		pos row = r*width;  //�����е�λ��
		return contents[row+c];  //���ظ����е��ַ�
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
	//�ú���������ʾScreen������
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
//window_mgr��

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
	Screen& s = Screens[i];   //���������ã���Ȼֻ�ǶԸ�������
	s.contents = string(s.height*s.width, ' ');
}*/

/*
//��X����Y
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
//Account��
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

//exercise 7.41 ʹ��ί�й��캯����дSales_data��
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
	Sales_data total;  //���浱ǰ��ͽ���ı���
	if (read(cin,total))  //�����һ�ʽ���
	{
		Sales_data trans;   //������һ���������ݵı��� 
		while (read(cin,trans))  //����ʣ��Ľ���
		{
			if (total.isbn() == trans.isbn())  //���isbn
			{
				total.combine(trans);     //���±���total��ǰ��ֵ
			}
			else
			{
				print(cout, total) << endl;  //������
				total = trans;               //������һ����
			}
		}
		print(cout,total); //������һ������
	}
	else       //û�������κ���Ϣ
	{
		cerr << "No data?!" << endl;  //֪ͨ�û�  
	}*/

	//exercise 7.47
	/*
	Ӧ����explicit�ġ������ܷ�ֹ������������ʽ��������ת������string����ת��ΪSales_data���󣬱�����ɲ���Ҫ��������󡣼���explicit��
	Ҫ����Sales_data�����������ʾ�ش���
	*/
	system("pause");
	return 0;
} 