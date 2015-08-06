#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<forward_list>
#include<string>
#include<deque>
#include<map>
using namespace std;

void compute(double& ret, const double& num, const char& opt);

//exercise 9.50
double sum_double(vector<string> vs)
{
	double sum = 0;
	for (auto &c : vs)
	{
		sum += stod(c);
	}
	return sum;
}

int sum_int(vector<string> vs)
{
	int sum = 0;
	for (auto &c:vs)
	{
		sum += stoi(c);
	}
	return sum;
}

//exercise 9.47
void foo2(const string& s,const string& numbers)
{
	string::size_type pos = 0;
	while ((pos = s.find_first_of(numbers,pos)) != string::npos)
	{
		cout << "find number at index: "<<pos<<" element is "<< s[pos] << endl;
		pos++;
	}
	pos = 0;
	while ((pos = s.find_first_not_of(numbers,pos))!=string::npos)
	{
		cout << "find character at index: "<<pos<<" element is "<<s[pos] << endl;
		pos++;
	}
}

//exercise 9.46
void pre_suffix(string& name,const string& prefix,const string& uffix)
{
	name.insert(0,prefix);
	name.insert(name.size(),uffix);
}

//exercise 9.44
void foo1(string& s,const string& oldVal, const string& newVal)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s.substr(i,oldVal.size()) == oldVal)
		{
			s.replace(i,oldVal.size(),newVal);
		}
	}
}

//exercise 9.43
void foo(string& s,const string& oldVal,const string& newVal)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s.substr(i,oldVal.size()) == oldVal)
		{
			s.erase(i,oldVal.size());
			s.insert(i,newVal);
		}
	}
}

//exercise 9.28
void foo(string& s1,string& s2,forward_list<string>& fl)
{
	auto pre = fl.before_begin();
	auto cur = fl.begin();
	while (cur!=fl.end())
	{
		if (*cur == s1)
		{
			fl.insert_after(cur,s2);
			return;
		}
		else
		{
			pre = cur;
			++cur;
		}
	}
	fl.insert_after(pre, s2);
}

int main()
{	
	//exercise9.26
	/*
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	vector<int> v(ia,end(ia));
	for (auto it = v.begin(); it != v.end(); )
	{
		if ((*it)%2==0)  //删除偶数
		{
			it = v.erase(it);
		}
		else
		{
			it++;
		}
	}
	for (auto &c:v)
	{
		cout << c << " ";
	}
	cout << endl;
	list<int> l(ia,end(ia));
	for (auto it = l.begin(); it != l.end();)  //删除奇数
	{
		if ((*it)%2==1)
		{
			it = l.erase(it);
		}
		else
		{
			it++;
		}
	}
	for (auto &c : l)
	{
		cout << c << " ";
	}
	cout << endl;*/
	//exercise_9.24
	/*
	vector<int> svec(1,1);
	cout << svec.at(0) << endl;
	cout << *svec.begin() << endl;
	cout << svec.front() << endl;
	cout << svec[0] << endl;*/
	
	//excercise 9.18
	/*
	deque<string> dq;
	string input;
	while (cin>>input)
	{
		dq.push_back(input);
	}
	for (deque<string>::iterator it = dq.begin(); it != dq.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;*/

	//excercise 9.19
	/*
	string input;
	list<string> l;
	while (cin>>input)
	{
		l.push_back(input);
	}
	for (list<string>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;*/

	//excercise 9.20
	/*
	list<int> l{1,2,3,4,5,7,9,10};
	deque<int> dq0, dq1;
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		if (*it % 2 == 0)
		{
			dq0.push_back(*it);
		}
		else
		{
			dq1.push_back(*it);
		}
	}*/

	//exercise 9.21
	/*
	list<string> l;
	vector<string> v;
	auto iter = v.begin();
	string word;
	while (cin>>word)
	{
		iter = v.insert(v.begin(),word);
	}
	for (auto &c:v)
	{
		cout << c << " ";
	}
	cout << endl;*/

    //exercise 9.27
     /*
    forward_list<int> fl = {1,2,3,4,5,6,7,8,9};
	forward_list<int>::iterator pre = fl.before_begin();
	forward_list<int>::iterator cur = fl.begin();
	while (cur != fl.end())
	{
		if (*cur % 2 != 0)
		{
			cur = fl.erase_after(pre);
		}
		else
		{
			pre = cur;
			++cur;
		}
	}
	for (auto &c:fl)
	{
		cout << c << " ";
	}*/

    //exercise 9.28
    /*
    string s1 = "abc";
	string s2 = "def";
	//forward_list<string> fl{"abc","ghi","jkl"};
	forward_list<string> fl{ "bc", "ghi", "jkl" };
	foo(s1,s2,fl);
	for (auto& c:fl)
	{
		cout << c << " ";
	}
	cout << endl;*/

   //exercise 9.31  删除偶数值元素并复制奇数值元素
   /*
    cout << "list的例子" << endl;
    list<int> li = {0,1,2,3,4,5,6,7,8,9};
	//list<int>::iterator it = li.begin();
	auto it = li.begin();
	while (it!=li.end())
	{
		if (*it%2==1)  //复制奇数值元素
		{
			it = li.insert(it,*it);
			//it += 2;
			advance(it,2);
		}
		else   //删除偶数值元素
		{
			it = li.erase(it);
		}
	}
	for (auto& c:li)
	{
		cout << c << " ";
	}
	cout << endl<<"forward_list 的例子"<<endl;
	forward_list<int> fl{1,2,3,4,5,6,7,8,9};
	forward_list<int>::iterator cur = fl.begin();
	forward_list<int>::iterator pre = fl.before_begin();
	while (cur != fl.end())
	{
		if (*cur%2==0)  //删除偶数
		{
			cur = fl.erase_after(pre);
		}
		else   //复制奇数
		{
			cur = fl.insert_after(pre,*cur);
			//cur += 2;
			advance(pre, 2);
			advance(cur,2);
		}
	}
	for (auto& c:fl)
	{
		cout << c << " ";
	}
	cout << endl;*/

/*
    //exercise 9.41
    vector<char> vi{'a','b','c','d','e'};
	string s1(vi.begin(),vi.end());
	cout << "s1 = " << s1 << endl;*/

    //exercise 9.42
    /*
    string s;
	vector<string> vs;
	s.reserve(100);
	while (cin>>s)
	{
		vs.push_back("s");
	}*/

    //exercise 9.43
    /*
    string s = { "To drive straight thru is a foolish, tho courageous act." };
	foo(s,"tho","thought");
	cout << s << endl;
	foo(s, "thru", "through");
	cout << s << endl;*/
    
    //exercise 9.44
    /*
    string s = { "To drive straight thru is a foolish, tho courageous act." };
	foo1(s, "tho", "thought");
	cout << s << endl;
	foo1(s, "thru", "through");
	cout << s << endl; */

    //exercise 9.46
    /*
    string name("alan");
	pre_suffix(name, "Mr.", ",Jr.");
	cout << name << endl;*/

    //exercise 9.47
    /*
    string s1("ab2c3d7R4E6");
	string numbers("0123456789");
	foo2(s1,numbers);*/

    //exercise 9.48
    /*
    string name("r2d2");
	string numbers("0123456789");
	cout<< numbers.find(name);*/
    
    //exercise 9.50
    /*
    vector<string> vs{"1","2","3","4","5","6.5"};
	cout<< "sum_int = " <<sum_int(vs) <<endl;
	cout << "sum_double = " <<sum_double(vs) << endl;*/

    //exercise 9.52
    /*
    string s;
	stack<string> sk;
	while (cin >> s && s!=")")
	{
		sk.push(s);
	}
	double ret = 0;
	map<string, bool> mp_opt{ make_pair("+", true), make_pair("-", true), make_pair("*", true), make_pair("/", true),};
	char opt = ' ';
	double temp;
	while (!sk.empty() && sk.top() != "(")
	{
		if (mp_opt[sk.top()])
		{
			opt = sk.top().front();
		}
		else
		{
			temp = stod(sk.top());
			compute(ret, temp, opt);
		}
		sk.pop();
	}
	sk.pop();
	cout << ret << endl;*/
	system("pause");
	return 0;
}

//只能计算加减法 ╮(╯▽╰)╭
void compute(double& ret, const double& num, const char& opt)
{
	if (opt == ' ') //表达式还没遇到运算符
	{
		ret += num;
	}
	else
	{
		switch (opt)
		{
		case '+':ret += num; break;
		case '-':ret = num - ret; break;
		//case '*':ret *= 
		default:
			break;
		}
	}
}