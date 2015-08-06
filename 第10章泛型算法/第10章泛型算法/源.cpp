#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
#include "Sales_data.h"   // Sales_data class
#include<functional>
#include<fstream>
using namespace std;
using namespace placeholders;

//exercise 10.9
bool isShorter(const string& s1,const string& s2)
{
	return s1.size() < s2.size();
}

//exercise 10.12
inline bool
compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
	return sd1.isbn().size() < sd2.isbn().size();
}

//exercise 10.13
bool Size(const string& s)
{
	return s.size() >= 5;
}

// test
string make_plural(size_t ctr,const string &word,const string &end)
{
	return ctr > 1 ? word + end : word;
}

void bigges(vector<string> &words,vector<string>::size_type sz)
{
	sort(words.begin(),words.end());
	auto endUnique = unique(words.begin(),words.end());
	words.erase(endUnique,words.end());
	stable_sort(words.begin(),words.end(),isShorter);
	//��ȡһ����������ָ���һ������ size()>=sz ��Ԫ��
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a){return a.size() > sz; });
	//��������size>=sz��Ԫ�ص���Ŀ
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	//��ӡ���ȴ��ڵ��ڸ���ֵ�ĵ��ʣ�ÿ�����ʺ����һ���ո�
	for_each(wc, words.end(), [](string& s){cout << s << " "; });
	cout << endl;
}

//biggies��partition�汾
void biggies_partition(vector<string> &words, vector<string>::size_type sz)
{
	sort(words.begin(), words.end());
	auto endUnique = unique(words.begin(), words.end());
	words.erase(endUnique, words.end());
	stable_sort(words.begin(), words.end(), isShorter);
	//��ȡһ����������ָ���һ������ size()>=sz ��Ԫ��
	//auto wc = find_if(words.begin(), words.end(), [sz](const string &a){return a.size() > sz; });
	//auto wc = partition(words.begin(), words.end(), [sz](const string& a){return a.size() <= sz; });
	auto wc = stable_partition(words.begin(), words.end(), [sz](const string& a){return a.size() <= sz; });
	//��������size>=sz��Ԫ�ص���Ŀ
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	//��ӡ���ȴ��ڵ��ڸ���ֵ�ĵ��ʣ�ÿ�����ʺ����һ���ո�
	for_each(wc, words.end(), [](string& s){cout << s << " "; });
	cout << endl;
}

//excercise 10.20
/*
size_t bigerThan6(vector<string> vs)
{
	return count_if(vs.begin(), vs.end(), [](string& s){return s.size() > 6; });
}*/

// exercise 10.22
/*
bool check_size(const string &s,size_t size)
{
	if (s.size() >= size)
	{
		return true;
	}
	return false;
}

size_t bigerThan6(vector<string>& vs)
{
	return count_if(vs.begin(), vs.end(), bind(check_size, _1, 6));
}*/

// exercise 10.24
bool check_size(const string &s, size_t size)
{
	if (s.size() < size)
	{
		return true;
	}
	return false;
}

//ʹ��bind �� biggies_partition
void biggies_partition_bind(vector<string> &words, vector<string>::size_type sz)
{
	sort(words.begin(), words.end());
	auto endUnique = unique(words.begin(), words.end());
	words.erase(endUnique, words.end());
	stable_sort(words.begin(), words.end(), isShorter);
	//��ȡһ����������ָ���һ������ size()>=sz ��Ԫ��
	//auto wc = find_if(words.begin(), words.end(), [sz](const string &a){return a.size() > sz; });
	//auto wc = partition(words.begin(), words.end(), [sz](const string& a){return a.size() <= sz; });
	auto wc = stable_partition(words.begin(), words.end(),bind(check_size, _1, sz));
	//��������size>=sz��Ԫ�ص���Ŀ
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	//��ӡ���ȴ��ڵ��ڸ���ֵ�ĵ��ʣ�ÿ�����ʺ����һ���ո�
	for_each(wc, words.end(), [](string& s){cout << s << " "; });
	cout << endl;
}

//exercise 10.41
template<class ForwardIterator,class T>
void replace(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value)
{
	//������������old_value����new_valueȡ��
	for (; first != last; ++first)
	{
		if (*first == old_value)
		{
			*first = new_value;
		}
	}
}

template<class InputIterator,class OutputIterator,class T>
OutputIterator replace_copy(InputIterator first,InputIterator last,OutputIterator result,const T& old_value,const T& new_value)
{
	for( ; first != last; ++first,++result)
	{
		//����������ϵ�Ԫ�ص���old_value,�ͷ�new_value����������
		//����ͽ�Ԫ�ؿ���һ�ݷŽ���������
		*result = *first == old_value ? new_value��old_value;
	}
	return result;
}

template<class ForwardIterator,class Predicate,class T>
void replace_if(ForwardIterator first,ForwardIterator last,Predicate pred,const T& new_value)
{
	for (; first ��= last; ++first)
	{
		if (pred(*first))
		{
			*first = new_value;
		}
	}
}

template<class InputIterator,class OutputIterator,class Predicate,class T>
void replace_copy_if(InputIterator first,InputIterator last,OutputIterator result,Predicate pred,const T& new_value)
{
	for (; first != last; ++first,++result)
	{
		*result = pred(*first) ? new_value : *first;
	}
	return result;
}



int main()
{
	//exercise 10.1
	/*
	int val;
	vector<int> vi;
	while (cin>>val && val != 00)
	{
		vi.push_back(val);
	}
	cout << "������Ŀ��ֵ��" << endl;
	int target;
	cin >> target;
	int count = 0;
	for (auto it = vi.begin(); it != vi.end(); it++)
	{
		if (target == *it)
		{
			++count;
		}
	}
	cout << "count = "<< count <<endl;*/
	//exercise 10.2
	/*
	string s;
	list < string > ls;
	while (cin>>s && s != "@q")
	{
		ls.push_back(s);
	}
	cout << "������Ŀ��ֵ��" << endl;
	string target;
	cin >> target;
	int count = 0;
	for (auto it = ls.begin(); it != ls.end(); it++)
	{
		if (target == *it)
		{
			++count;
		}
	}
	cout << "count = " << count << endl;*/

	//exercise 10.5
	/*
	vector<const char *> roster1{ "Mooophy", "pezy", "Queequeg" };
	list<const char *>  roster2{ "Mooophy", "pezy", "Queequeg", "shbling", "evan617" };
	cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin())<<endl;*/

	//exercise 10.6
	/*
	vector<int> vi{1, 2, 3, 4, 5};
	fill_n(vi.begin(),vi.size(),0);
	for (const auto &c:vi)
	{
		cout << c << endl;
	}*/

	//exercise 10.7
	/*
	// (a) ����,��������
	vector<int> vi;
	list<int> lst;
	int i;
	while (cin>>i && i != 00)
	{
		lst.push_back(i);
	}
	auto ret = copy(lst.cbegin(),lst.cend(),back_inserter(vi));
	for (const auto &c : vi)
		cout << c << " ";*/

	//(b) ����
	/*
	vector<int> vi;
	//vi.reserve(10);
	vi.resize(10);
	fill_n(vi.begin(),10,1);
	for (const auto &c : vi)
		cout << c << " ";*/

	//exercise 10.9
	/*
	vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	sort(words.begin(),words.end());
	auto endUnique = unique(words.begin(),words.end());
	words.erase(endUnique,words.end());
	for (const auto &c:words)
	{
		cout << c << " ";
	}
	cout << "\n" << "�����ȴ�С����Ľ����";
	stable_sort(words.begin(),words.end(),isShorter);
	for (const auto &c : words)
	{
		cout << c << " ";
	}
	cout << endl;*/

	// exercise 10.12
	/*
	Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
	vector<Sales_data> v{ d1, d2, d3, d4, d5 };
	//! @note   the elements the iterators pointing to
	//!         must match the parameters of the predicate.
	std::sort(v.begin(), v.end(), compareIsbn);

	for (const auto &element : v)
		std::cout << element.isbn() << " ";
	std::cout << std::endl;*/
    
    //exercise 10.13
    /*
    vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	auto iter_longerLast = partition(words.begin(), words.end(), Size);
	for (auto& it = words.cbegin(); it != iter_longerLast; it++)
		cout << *it << " ";
	cout << endl;*/
     
    //exercise 10.14
    /*
    int val1,val2;
	cin >> val1 >> val2;
	auto f = [val1,val2](){ return (val1 + val2); };
	cout << f() << endl;*/

    //exercise 10.15
    /*
    int val1 = 8;
	auto f = [val1](int temp)->int{ return temp + val1; };
	cout << f() << endl;*/

    //exercise 10.17
    /*
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    vector<Sales_data> v{ d1, d2, d3, d4, d5 };
    //! @note   the elements the iterators pointing to
    //!         must match the parameters of the predicate.
	sort(v.begin(), v.end(), [](const Sales_data& s1, const Sales_data& s2) {return s1.isbn().size() < s2.isbn().size(); });
	for (const auto &e : v)
		cout << e.isbn() << " ";
	cout << endl;*/

    //exercise 10.18   exercise 10.19 
    /*
    vector<string> v{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	cout << "ex10.18: ";
	vector<string> v1(v);
	biggies_partition(v1, 4);*/

	//ex10.20  
    /*
	vector<string> v{"alan", "moophy", "1234567", "1234567", "1234567", "1234567"};
	std::cout << "ex10.20: " << bigerThan6(v) << endl;*/
    
    //exercise 10.21
    /*
    int val = 4;
	auto f = [&val]()->bool{
		if (val == 0) 
			return true;
		else
		{
			--val;
			return false;
		}
		};
	while (!f())
	{
		cout << val << endl;
	}
	cout << val << endl;*/
    
    //exercise 10.22
    /*
    vector<string> authors{ "Mooophy", "pezy", "Queequeg90", "shbling", "evan617" };
	cout << bigerThan6(authors) << endl;*/

    //exercise 10.24
    /*
    vector<int> vi{1,2,3,4,5,6};
	string s("oo");
	auto it = find_if(vi.begin(),vi.end(),bind(check_size, s, _1));
	if (it != vi.end())
	{
		cout << *it << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}*/
   
    //exercise 10.25
    /*
    vector<string> v{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    cout << "ex 10.25: ";
    vector<string> v1(v);
    biggies_partition(v1, 4);*/

    //exercise 10.27
    /*
    vector<int> vi{1, 2, 2, 3, 3, 4, 5, 6, 7};
	list<int> li;
	//unique_copy(vi.cbegin(),vi.cend(),front_inserter(li));
	unique_copy(vi.cbegin(), vi.cend(), inserter(li,li.begin()));
	for (auto &e : li)
		cout << e << " ";*/
    
    //�������� test
    /*
    vector<int> vi;
    istream_iterator<int> in_iter(cin);  //��cin��ȡint
	istream_iterator<int> eof;           //istreamβ�������
	while (in_iter != eof)               //�������ݿɹ���ȡʱ
	{
		vi.push_back(*in_iter++);
	}
	ostream_iterator<int> out(cout," ");
	cout<< "vi�е����ֵ�� ";
	//for (auto &e : vi)
		//out = e;
	//cout << endl;
	copy(vi.begin(),vi.end(),out);*/

    //exercise 10.29
    /*
    ifstream ifs("D:/my codes/rely on VS/��10�·����㷨/test.txt");
    istream_iterator<string> in_iter(ifs),eof;
	vector<string> vs;
	copy(in_iter, eof, back_inserter(vs));
	for (auto &c : vs)
		cout << c << " ";
	cout << endl;*/

    //exercise 10.30 && exercise 10.31
    /*
    istream_iterator<int> in(cin), eof;
	vector<int> vi;
	//copy(in,eof,back_inserter(vi));
	unique_copy(in, eof, back_inserter(vi));
	sort(vi.begin(),vi.end());
	ostream_iterator<int> out(cout," ");
	cout << "������ֵΪ�� ";
	for (auto &c : vi)
		out = c;
	cout << endl;*/
   
    //exercise 10.33
    /*
    ifstream ifs("D:/my codes/rely on VS/��10�·����㷨/input.txt");
	ofstream ofsOdd("D:/my codes/rely on VS/��10�·����㷨/oddOutput.txt",ofstream::app);     //������������ļ�
	ofstream ofsEven("D:/my codes/rely on VS/��10�·����㷨/evenOutput.txt",ofstream::app);   //ż����������ļ�
    istream_iterator<int> in(ifs),in_eof;
	vector<int> vi;
	//copy(in,eof,back_inserter(vi));
	//cout << "vector�е�Ԫ�أ�";
	//for (auto &e : vi)
		//cout << e <<" ";
	//cout << endl;
	ostream_iterator<int> outOdd(ofsOdd," ");
	ostream_iterator<int> outEven(ofsEven,"\n");
	for_each(in, in_eof, [&outOdd, &outEven](const int i){return (i&0x1 ? outOdd : outEven) = i;});*/

   //exercise 10.37
    /*
    vector<int> vi{1,2,3,4,5,6,7,8,9,10};
	list<int> li;
	for (auto it = vi.rbegin()+3; it != vi.rbegin()+8; it++)
	{
		li.push_back(*it);
	}
	for (auto &e : li)
		cout << e << " ";*/

	//exercise 10.38
	//���������
	/*�������ɨ�裬ֻ��������д������֧�ֵĵ��������У�1���Ƚ���������������ȺͲ�����������== �� ��=��
	  �����ƽ���������ǰ�úͺ��õ������㣨++��
	  ���ڶ�ȡԪ�صĽ������������*��....
	*/
	//���������---��������������Ĳ���
	/*�������ɨ�裬ֻд������������֧�ֵĲ����� ��1�������ƽ�������ǰ�úͺ��õĵ������㣨++�� ��2���������������*��ֻ
	  �����ڸ�ֵ���������ࣨҲ���ǽ�ֵд������ָ���Ԫ�أ�
	*/

	//ǰ�������
	/*������ɨ�裬�ɶ�д��ֻ����������һ�������ƶ���֧��������������������
	*/

	//˫�������
	/*�������ݼ�ɨ�裬�ɶ�д����������/�����д�����е�Ԫ�أ�֧���������������������в��������ݼ����㡣���˵�forward_list���⣬
	  ������׼�ⶼ�ṩ����˫�������Ҫ��ĵ�����
	*/

	//������ʵ�����
	/*�ṩ�ڳ���ʱ���ڷ�������������Ԫ�ص�������֧��˫������������в��������е��������λ�õıȽϺ�+n,-n���ƶ�
	*/

	//exercise 10.41
	list<string> ls{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	ls.sort();
	ls.unique();
	for (auto &e : ls)
		cout << e << " ";
	cout << endl;
	system("pause");
	return 0;
}