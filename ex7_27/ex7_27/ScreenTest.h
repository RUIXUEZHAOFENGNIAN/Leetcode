#include<iostream>
#include<string>
using namespace std;
/*
Screen��
*/
class Screen
{
public:
	typedef string::size_type pos;
	Screen() = default;    //1
	Screen(pos ht, pos wt) :height(ht), width(wt), contents(ht*wt, ' '){}
	Screen(pos ht, pos wt, char c) :height(ht), width(wt), contents(ht*wt, c){}

	//��ȡ��괦���ַ�
	char get() const
	{
		return contents[cursor];   //��ʽ����
	}
	//��ʽ����
	inline char get(pos r, pos c) const
	{
		pos row = r*width;  //�����е�λ��
		return contents[row + c];  //���ظ����е��ַ�
	}
	Screen& move(pos r, pos c);

	Screen& set(char);
	Screen& set(pos, pos, char);

	Screen& display(ostream& os)
	{
		do_display(os);
		return *this;
	}
	const Screen& display(ostream& os) const
	{
		do_display(os);
		return *this;
	}

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

private:
	//�ú���������ʾScreen������
	void do_display(ostream& os) const
	{
		os << contents;
	}
};

inline Screen& Screen::move(pos r, pos c)
{
	pos row = r*width;
	cursor = row + c;
	return *this;
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}