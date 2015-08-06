#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<string.h>
using namespace std;

//exercise 12.2
/*
class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	StrBlob() : data(make_shared<vector<string>>()) {};
	StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){};
	size_type size() const{ return data->size(); }
	bool empty() const{ return data->empty(); }
	//添加和删除元素
	void push_back(const string &t){ data->push_back(t); }
	void pop_back();
	//元素访问
	string& front();
	string& back();

	//元素访问 const版本
	const string& front() const;
	const string& back() const;

private:
	shared_ptr<vector<string>> data;
	void check(size_type i,const string& msg) const;
};

void StrBlob::check(size_type i, const string& msg) const
{
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}

string& StrBlob::front()
{
	//如果vector为空，check会抛出一个异常
	check(0,"front on empty StrBlob");
	return data->front();
}

const string& StrBlob::front() const
{
	check(0,"front on empty StrBlob");
	return data->front();
}

const string& StrBlob::back() const
{
	check(0,"back on empty StrBlob");
	return data->back();
}

string& StrBlob::back()
{
	//如果vector为空，check会抛出一个异常
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	//如果vector为空，check会抛出一个异常
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}*/

//excercise 12.6
/*
void process(vector<int>*& ptr)
{
	cout << "PLZ enter value: ";
	int val;
	while (cin>>val)
	{
		ptr->push_back(val);
	}
}

void dynamic_vector_print(vector<int>*& ptr)
{
	for (const auto &c:*ptr)
	{
		cout << c << " ";
	}
	cout << endl;
}*/

//exercise 12.7
/*
shared_ptr<vector<int>> shared_ptr_generator()
{
	return  make_shared<vector<int>>();
}

void shared_process(shared_ptr<vector<int>> ptr)  //引用计数值为2
{
	int val;
	while (cin>>val)
	{
		ptr->push_back(val);
	}
}                           //引用计数值减为1

void dynamic_vector_print_share(const shared_ptr<vector<int>> ptr)
{
	for (const auto &e: *ptr)
	{
		cout << e << " ";
	}
	cout << endl;
} 

void process(shared_ptr<int> ptr)
{
	cout << "use_count inside the process function :" <<ptr.use_count() << endl;
}*/

//exercise 12.14
/*
//表示我们正在连接什么
struct destination
{
	string ip;
	int port;
	destination(string s, int val) :ip(s), port(val) {}
};

//使用连接所需的信息
struct connetion
{
	string ip;
	int port;
	connetion(string _ip, int _port) :ip(_ip), port(_port){}
};

//打开连接
connetion connect(destination* pDest)
{
	//打开目的端口
	shared_ptr<connetion> pConn(new connetion(pDest->ip,pDest->port));
	cout << "creating connection(" << pConn.use_count() << ")" << endl;
	return *pConn;
}

//关闭给定的连接
void disconnect(connetion pConn)
{
	cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << endl;
}

//删除器
void end_connection(connetion* pConn) 
{
	 disconnect(*pConn); 
}

void f(destination &d)
{
	//打开连接
	connetion conn = connect(&d);
	shared_ptr<connetion> p(&conn,end_connection);
	cout << "connecting now(" << p.use_count() << ")" << endl;
}*/

int main()
{
	//exercise 12.1
	// 都是四个

	//exercise 12.2
	/*
	const StrBlob csb{ "hello", "world", "pezy" };
	StrBlob sb{ "hello", "world", "Mooophy" };
	cout << csb.front() << " " << csb.back() << endl;
	sb.back() = "pezy";
	cout << sb.front() << " " << sb.back() << endl;*/

	//exercise 12.6
	/*
	vector<int>* ptr = new vector<int>();
	process(ptr);
	dynamic_vector_print(ptr);
	delete ptr;*/

	//exercise 12.7
	/*
	shared_ptr<vector<int>> ptr = shared_ptr_generator();  // 引用计数值为1
	//shared_ptr<vector<int>> ptr = make_shared<vector<int>>();
	shared_process(ptr);                                   
	dynamic_vector_print_share(ptr);  //此时引用计数为1，待main()函数结束时引用计数为0*/

	//exercise 12.10
	/*
	shared_ptr<int> p(new int(42));
	process(shared_ptr<int>(p));
	cout << "now the use_count is:" << p.use_count() << endl;

	auto q = p;
	cout << "after update the use_count is:" << p.use_count() << "\n";
	cout << "the int p now points to is:" << *p << "\n"; */

	//exercise 12.13
	//error --- double free
	/*
	{
		auto sp = std::make_shared<int>();
		auto p = sp.get();
		delete p;
	}*/

	//exercise 12.14
	/*
	destination dest("202.118.176.67", 3316);
	f(dest);*/

	//exercise 12.16
	//unique_ptr<int> p(new int(11));
	//unique_ptr<int> q(p);

	//exercise 12.17
	/*
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	//(a)
	//  error : invalid conversion from 'int' to 'std::unique_ptr<int>::pointer {aka int*}'[-fpermissive]
	//IntP p0(ix);

	//(b)
	/*
	* @brief The code below can compile, but will cause error at run time.
	*        The reason is that when the unique_ptr p1 is out of scope, delete will be called
	*        to free th object. But the object is not allocate using new.Thus, an error
	*        would be thrown by operating system.
	*  @badcode
	IntP p1(pi);
	*/

	//(c)
	/**
	* @brief This code can compile, but cause a dangling pointer at run time.
	*        The reason is that the unique_ptr will free the object the raw pointer
	*        is pointing to.
	* @badcode
	*/
	//IntP p2(pi2);

	//(d)
	/**
	* @brief   When the unique_ptr goes out of scope, it will call delete to free an
	*          obeject not allocated using new.
	* @badcode
	*/
	//IntP p3(&ix);

	//(e)
	/**
	* @brief   Recommended.
	*/
	// IntP p4(new int(2048));

	/**
	* @brief   error:   double free or corruption at run time
	*          two unique_ptr are pointing to the same object. Thus, when both are out of
	*          scope, Operating system will throw double free or corruption.
	* @badcode
	
	//IntP p2(new int(555));
	//(f)
	IntP p2(new int(555));
	IntP p5(p2.get()); */
    
    //exercise 12.23

// dynamically allocated array of char
/*
    char *concatenate_string = new char[255]();
    strcat(concatenate_string, "hello ");
    strcat(concatenate_string, "world");
    std::cout << concatenate_string << std::endl;
    delete[] concatenate_string;

    string s1("I Love ");
	string s2("oo");
	cout << s1+s2<< endl;*/
     
    //test
    /*
    allocator<string> alloc;          //可以分配string的allocator对象
	auto const p = alloc.allocate(8); //分配8个未初始化的string对象
	auto q = p;                     //q指向最后构造的元素之后的位置 
	//alloc.construct(q++);          //*q为空字符串
	//cout << *p << endl;
	alloc.construct(q++,10,'c');   //*q为cccccccccc
	//cout << *p << endl;
	alloc.construct(q++,"Hi");     //*q为hi!
	cout << *p << endl;
	//cout << *q << endl;  q指向未构造的内存
	alloc.deallocate(p,8);*/

    //exercise 12.26
     /*
    string *const p = new string[8];  //构造8个空的string
	string s;
	string* q = p;
	while (cin>>s && s!="@q" && q != p+8)
	{
		*q++ = s;               //赋予*q一个新值
	}
	const size_t size = q - p;  //记住我们读取了多少个string
	//使用数组
	while (q != p)
	{
		--q;
		cout << *q << " ";
	}
	cout << endl;
	delete[] p;  //指向一个数组，得用delete[]来释放*/

	//用allocator类来写
     /*
	allocator<string> alloc;
	auto p = alloc.allocate(8);
	auto q = p;
	string s1;
	while (cin>>s1 && s1!="@q" && q != p+8)
	{
		alloc.construct(q++,s1);
	}
	//逆序输出
	//销毁元素
	while (q != p)
	{
		--q;
		cout << *q << " ";
		alloc.destroy(q);  //释放我们真正构造的string
	}
	//释放内存
	alloc.deallocate(p,8);*/
	system("pause");
	return 0;
}