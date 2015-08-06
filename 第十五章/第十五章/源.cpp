#include<iostream>
#include<string>
using namespace std;

class quote
{
public:
	quote() = default;  //默认构造函数
	quote(const string s, double val) : bookNo(s), price(val){}
	string isbn() const { return bookNo;}     //函数声明,返回版本号
	virtual double net_price(size_t n) const  //函数声明，虚函数，返回给定数量的书籍的销售总额  //派生类负责改写并使用不同的折扣计算算法
	{
		return n*price;
	}
	virtual ~quote() = default;   //对析构函数进行动态绑定
private:
	string bookNo;        //书籍的ISBN编号
protected:
	double price = 0.0;   //代表普通状态下的不打折的价格
};

class Bulk_quote : public quote  //Bulk_quote继承了Quote
{   
public:
	Bulk_quote() = default;  
	Bulk_quote(const string& s,double,size_t,double);
	//覆盖基类的函数版本以实现基于大量购买的折扣政策
	double net_price(size_t) const override;
private:
	size_t min_qty = 0;      //适用折扣政策的最低购买量
	double discount = 0.0;   //以小数表示的折扣额
};

//计算并打印销售给定数量的某种书籍所得的费用
double print_total(ostream &os, const quote &item, size_t n)
{
	//根据传入item形参的对象类型调用Quote::net_price
	//或者Bult_quote::net_price
	double ret = item.net_price(n);
	//调用Quote:isbn
	os << "ISBN: "<< item.isbn()  << " # sold: " << n << " total due: "<< ret <<endl;
}

int main()
{
	//15.1 什么是虚成员？对于某些函数，基类希望它的派生类各自定义适合自身的版本，此时基类就将这些函数声明成虚函数
	//在类中被声明为virtual的成员，基类希望这种成员在派生类中重定义。除了构造函数外，任意非static成员都可以为虚成员

	//15.2 protected访问说明符与private有何区别？派生类不能访问私有成员，但是能访问受保护成员，受保护成员同时还禁止其它用户访问
	/*protected为受保护的访问标号，protected成员可以被该类的成员、友元和派生类成员（非友元）访问，而不可以被该类型的普通用户访问。
	  而private成员，只能被基类的成员和友元访问，派生类不能访问*/


	system("pause");
	return 0;
}