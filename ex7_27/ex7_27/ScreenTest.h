#include<iostream>
#include<string>
using namespace std;
/*
Screen类
*/
class Screen
{
public:
	typedef string::size_type pos;
	Screen() = default;    //1
	Screen(pos ht, pos wt) :height(ht), width(wt), contents(ht*wt, ' '){}
	Screen(pos ht, pos wt, char c) :height(ht), width(wt), contents(ht*wt, c){}

	//读取光标处的字符
	char get() const
	{
		return contents[cursor];   //隐式内联
	}
	//显式内联
	inline char get(pos r, pos c) const
	{
		pos row = r*width;  //计算行的位置
		return contents[row + c];  //返回给定列的字符
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
	//该函数负责显示Screen的内容
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