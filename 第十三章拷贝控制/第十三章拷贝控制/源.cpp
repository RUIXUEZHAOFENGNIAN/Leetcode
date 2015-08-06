#include<iostream>
#include<vector>
#include<string>
using namespace std;

//exercise 13.13
/*
struct X
{
	//默认构造函数
	X(){ cout << "X()" << endl;}
	//拷贝构造函数
	X(const X&){ cout << "X(const X&)" << endl;}
	//拷贝赋值运算符
	X& operator=(const X&){ return *this; }
    //析构函数
	~X(){ cout << "~X()" << endl; }
};

void f(const X &rx, X x)  //X x 拷贝初始化1  析构函数1
{
	std::vector<X> vec;
	vec.reserve(2);
	vec.push_back(rx);  //拷贝初始化2   析构函数2
	vec.push_back(x);   //拷贝初始化3   析构函数3
}*/
//exercise 13.5
/*
class foo
{
public:
	foo() :i(0), s(" "), p(new string) { }
	foo(int i1, string s1) :i(i1), s(s1), p(new string()){ cout << "调用构造函数" << std::endl;}
	foo(const foo &f)
	{
		i = f.i;
		s = f.s;
		p = new std::string(*f.p);
		std::cout << "调用拷贝构造函数" << std::endl;
	}
	foo& operator=(const foo&f)
	{
		i = f.i;
		s = f.s;
		p = new std::string(*f.p);
		std::cout << "调用赋值构造函数" << std::endl;
		return *this;
	}
	~foo()
	{
		delete p;
		std::cout << "析构函数" << std::endl;
	}

private:
	int i;
	std::string s;
	std::string *p;
};

foo fun1(foo f)  //调用拷贝构造函数1        析构函数3
{
	foo f2(f);   //调用拷贝构造函数2        析构函数2
	foo f3;     
	f3 = f2;     //调用拷贝赋值运算符1      析构函数1
	return f2;   //调用拷贝构造函数3
}*/

//exercise 13.14---13.17
class numbered
{
public:
	//构造函数 13.14
	numbered()
	{
		static int unique = 10;
		mysn = unique++;
	};
	//拷贝构造函数 13.15
	numbered(const numbered& n){ mysn = n.mysn + 1; }
	//拷贝赋值函数 
	numbered& operator=(const numbered&){ return *this; }

	int mysn;
};

void f(numbered& s)
{
	cout << s.mysn << endl;
}

int main()
{
	//exercise 13.13
	/*
	foo f1(1, "123");  //调用构造函数1      析构函数4
	fun1(f1);*/
	//exercise 13.13
	/*
	X *px = new X; // 内置指针，构造函数1
	f(*px, *px); //析构函数4
	delete px; */    

	//exercise 13.14---13.17
	//exercise 13.14--使用合成拷贝控制函数
	//exercise 13.15--使用拷贝控制函数生成一个新的序号
	numbered a,b=a,c=b;
	f(a);
	f(b);
	f(c);
	system("pause");
	return 0; 
	
}