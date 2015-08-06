#include<iostream>
#include<vector>
#include<string>
using namespace std;

//exercise 13.13
/*
struct X
{
	//Ĭ�Ϲ��캯��
	X(){ cout << "X()" << endl;}
	//�������캯��
	X(const X&){ cout << "X(const X&)" << endl;}
	//������ֵ�����
	X& operator=(const X&){ return *this; }
    //��������
	~X(){ cout << "~X()" << endl; }
};

void f(const X &rx, X x)  //X x ������ʼ��1  ��������1
{
	std::vector<X> vec;
	vec.reserve(2);
	vec.push_back(rx);  //������ʼ��2   ��������2
	vec.push_back(x);   //������ʼ��3   ��������3
}*/
//exercise 13.5
/*
class foo
{
public:
	foo() :i(0), s(" "), p(new string) { }
	foo(int i1, string s1) :i(i1), s(s1), p(new string()){ cout << "���ù��캯��" << std::endl;}
	foo(const foo &f)
	{
		i = f.i;
		s = f.s;
		p = new std::string(*f.p);
		std::cout << "���ÿ������캯��" << std::endl;
	}
	foo& operator=(const foo&f)
	{
		i = f.i;
		s = f.s;
		p = new std::string(*f.p);
		std::cout << "���ø�ֵ���캯��" << std::endl;
		return *this;
	}
	~foo()
	{
		delete p;
		std::cout << "��������" << std::endl;
	}

private:
	int i;
	std::string s;
	std::string *p;
};

foo fun1(foo f)  //���ÿ������캯��1        ��������3
{
	foo f2(f);   //���ÿ������캯��2        ��������2
	foo f3;     
	f3 = f2;     //���ÿ�����ֵ�����1      ��������1
	return f2;   //���ÿ������캯��3
}*/

//exercise 13.14---13.17
class numbered
{
public:
	//���캯�� 13.14
	numbered()
	{
		static int unique = 10;
		mysn = unique++;
	};
	//�������캯�� 13.15
	numbered(const numbered& n){ mysn = n.mysn + 1; }
	//������ֵ���� 
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
	foo f1(1, "123");  //���ù��캯��1      ��������4
	fun1(f1);*/
	//exercise 13.13
	/*
	X *px = new X; // ����ָ�룬���캯��1
	f(*px, *px); //��������4
	delete px; */    

	//exercise 13.14---13.17
	//exercise 13.14--ʹ�úϳɿ������ƺ���
	//exercise 13.15--ʹ�ÿ������ƺ�������һ���µ����
	numbered a,b=a,c=b;
	f(a);
	f(b);
	f(c);
	system("pause");
	return 0; 
	
}