#include<iostream>
#include<algorithm>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
	int retangleArea1 = (C - A)*(D-B);
	int retangleArea2 = (G - E)*(H-F);
	int tempArea = 0;
	int X1=max(A,E);
	int Y1= max(B,F);
	int X2=min(C, G);
	int Y2=min(H, D);
	//case1
	if (X2<=X1 || Y2<=Y1)
	{
		return retangleArea1 + retangleArea2;
	}
	return retangleArea1 + retangleArea2 - (X2-X1)*(Y2 - Y1);
}

int main()
{
	int A, B, C, D, E, F, G, H;
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;
	cin >> E;
	cin >> F;
	cin >> G;
	cin >> H;
	int result;
	result = computeArea(A, B, C, D, E, F, G, H);
	cout << result << endl;
	system("pause");
	return 0;
}