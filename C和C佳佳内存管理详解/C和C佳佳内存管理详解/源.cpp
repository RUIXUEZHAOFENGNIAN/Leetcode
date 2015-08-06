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
	//������ֵ�����
	HasPtr& operator=(const HasPtr &hp) {
		string *new_ps = new string(*hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this;
	}
	//Ĭ�ϵĹ��캯��
	HasPtr(const string &s = string()):ps(new string(s)),i(0){}
	//��������
	~HasPtr(){ delete ps; }
private:
	string *ps;
	int i;
};

//exercise 13.13
struct  X
{
	//Ĭ�Ϲ��캯��
	X(){ cout << "X()" << endl; }
	//�������캯��
	X(const X&){ cout << "X(const X&)" << endl;}
	//������ֵ�����
	X& operator=(const X&){ cout << "X& operator=(const X&)" << endl; return *this; }
	//��������
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
	��1�����캯���ĵ�һ�����������������͵����ã����κζ����������Ĭ��ֵ
	��2��ʲôʱ��ʹ��������һ��������Ϊʵ�δ��ݸ�һ�����������͵��βΣ���
	    һ����������Ϊ���������͵ĺ�������һ��ʵ�Σ����ݻ������б��ʼ��һ��
		�����е�Ԫ�ػ�һ���ۺ����еĳ�Ա������һ��ͬ���͵Ķ�����ʾ����ʽ��ʼ��
		һ������
	*/
	//exercise 13.3  �������������͵�
	//exercise 13.4
	/*
	Point global;
	Point foo_bar(Point arg)  //���ô˺���ʱ����ʵ�ζ���ĸ������ݸ��βζ���arg
	{
	    Point local = arg; //ʹ���˿������캯�����ֲ�����local��ʼ��Ϊ�β�arg�ĸ���
		Point *heap = new Point(global);  //ʹ���˿������캯��ֱ�ӳ�ʼ��һ��ȫ�ֶ���global�ĸ�������heapָ��ָ����
		*heap = local; 
		Point pa[4] = {local,*heap}; //ʹ���˻������б��ʼ�������е�Ԫ��
		return *heap;   //�Ӻ������ض���*heap�ĸ���
	}
	*/

	//exercise 13.6
	/*��1�� ������ֵ���������һ��������������ͬ���͵Ĳ�����Ȼ�󷵻�һ��ָ������������������á����ƶ��������á�
	  ��2�� ����Ҫ���忽�����캯��ʱ����Ҫ���帳ֵ�������������һ����(a)���а���ָ�������ݳ�Ա��b�������ڽ��и�ֵ
	        ����ʱ��Ҫ��һЩ�ض��������������Ҫ���帳ֵ������
	  ��3�� ����ĳЩ�࣬�ϳɿ�����ֵ�����������ֹ�����Ͷ���ĸ�ֵ����һ����δ���帳ֵ�����ʱ����������Ϊ���Զ�����
	        һ���ϳɿ�����ֵ�������
	*/

	//exercise 13.9
	/*
	(1) ����������ʲô�������һ����Ա�����������ɲ��˺Ž��������ɡ���û�з���ֵ��Ҳ�����ܲ������ͷŶ���ʹ�õ���Դ������
	                   �ٶ���ķ�static���ݳ�Ա��
	(2) �ϳ������������ʲô����������ĳЩ�࣬�ϳ�����������������ֹ�����͵Ķ������١�
	(3) ʲôʱ������ɺϳ�����������������û�ж�����������ʱ����������Ϊ������һ���ϳ�����������
	*/
	//exercise 13.13
	X *px = new X;
	f(*px, *px);
	delete px;
	system("pause");
	return 0;
}