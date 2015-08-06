#include<iostream>
#include<vector>
using namespace std;

int *reset(int *);
double *reset(double *);
int ff(int a, int b = 0, int c = 0);
//char *init(int ht = 24,int wd,char bckgrnd);

size_t result = 1;
size_t factorial(size_t n)
{
	if (n==1)
	{
		return 1;
	}
	else
	{
		return result = n * factorial(n-1);
	}

}

void exchange(int* p,int* q)
{
	int temp;
	temp = *p;
	*p = *q;;
	*q = temp;
}



int main()
{
	/*Á·Ï°6.3*/
	/*
	size_t num;
	cin >> num;
	cout<<num<<"µÄ½×³ËÊÇ"<<factorial(num)<<endl;
	system("pause");
	*/
	/*Á·Ï°6.10*/
	int a = 0, b = 1;
	exchange(&a,&b);
	cout << a <<"   "<< b << endl;
	system("pause");
	return 0;
}