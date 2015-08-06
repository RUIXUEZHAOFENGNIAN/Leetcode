#include<iostream>
#include<vector>
using namespace std;

//exercise 13.5
/*
class  HasPtr
{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
	HasPtr(const HasPtr& hp):ps(new string(*(hp.ps))),i(hp.i) { }
private:
	string *ps;
	int i;
};*/

//exercise 13.8  13.11
class HasPtr
{
public:
	//拷贝赋值运算符
	HasPtr& operator=(const HasPtr &hp) {
		string *new_ps = new string(*hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this;
	}
	//默认的构造函数
	HasPtr(const string &s = string()):ps(new string(s)),i(0){}
	//析构函数
	~HasPtr(){ delete ps; }
private:
	string *ps;
	int i;
};

//exercise 13.13
struct  X
{
	//默认构造函数
	X(){ cout << "X()" << endl; }
	//拷贝构造函数
	X(const X&){ cout << "X(const X&)" << endl;}
	//拷贝赋值运算符
	X& operator=(const X&){ cout << "X& operator=(const X&)" << endl; return *this; }
	//析构函数
	~X(){ cout << "~X()" << endl; };
};

void f(const X &rx, X x)
{
	vector<X> vec;
	vec.reserve(2);
	vec.push_back(rx);
	vec.push_back(x);
}

int main()
{
	//exercise 13.1
	/*
	（1）构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值
	（2）什么时候使用它？将一个对象作为实参传递给一个非引用类型的形参；从
	    一个返回类型为非引用类型的函数返回一个实参；根据花括号列表初始化一个
		数组中的元素或一个聚合类中的成员；根据一个同类型的对象显示或隐式初始化
		一个对象
	*/
	//exercise 13.3  参数非引用类型的
	//exercise 13.4
	/*
	Point global;
	Point foo_bar(Point arg)  //调用此函数时，将实参对象的副本传递给形参对象arg
	{
	    Point local = arg; //使用了拷贝构造函数将局部对象local初始化为形参arg的副本
		Point *heap = new Point(global);  //使用了拷贝构造函数直接初始化一个全局对象global的副本，让heap指针指向它
		*heap = local; 
		Point pa[4] = {local,*heap}; //使用了花括号列表初始化数组中的元素
		return *heap;   //从函数返回对象*heap的副本
	}
	*/

	//exercise 13.6
	/*（1） 拷贝赋值运算符接受一个与其所在类相同类型的参数，然后返回一个指向其左侧运算对象的引用。控制对象间的引用。
	  （2） 在需要定义拷贝构造函数时，需要定义赋值操作符，即如果一个类(a)类中包含指针型数据成员（b）或者在进行赋值
	        操作时需要做一些特定工作，则该类需要定义赋值操作符
	  （3） 对于某些类，合成拷贝赋值运算符用来禁止该类型对象的赋值。当一个类未定义赋值运算符时，编译器会为它自动生成
	        一个合成拷贝赋值运算符。
	*/

	//exercise 13.9
	/*
	(1) 析构函数是什么？是类的一个成员函数，名字由波浪号接类名构成。它没有返回值，也不接受参数。释放对象使用的资源，并销
	                   毁对象的非static数据成员。
	(2) 合成析构函数完成什么工作？对于某些类，合成析构函数被用来阻止该类型的对象被销毁。
	(3) 什么时候会生成合成析构函数？当类中没有定义析构函数时，编译器会为它定义一个合成析构函数。
	*/
	//exercise 13.13
	X *px = new X;
	f(*px, *px);
	delete px;
	system("pause");
	return 0;
}