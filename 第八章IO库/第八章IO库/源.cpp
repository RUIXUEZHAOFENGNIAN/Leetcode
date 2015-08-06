#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

//练习8.1
istream&  foo(istream& is)
{
	string buf;
	while (is>>buf)
	{
		cout << buf << endl;
	}
	is.clear();
	return is;
}

//exercise8_4
void foo1(const string& fileName,vector<string>& ret)
{
	ifstream infile(fileName);   //构筑一个ifstream并打开给定文件
	if (infile)
	{
		string buf;
		 
		while (getline(infile,buf))
		{
			ret.push_back(buf);
		}
			/*
		while (infile>>buf)
		{
			ret.push_back(buf);
		}*/
	}
}

//exercise 8.13
struct personInfo
{
	string name;
	vector<string> phones;
};

bool valid(const string& str)
{
	return isdigit(str[0]);
}

string format(const string& str)
{
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

void process(const string& fileName,vector<personInfo>& people)
{
	ifstream infile(fileName);
	if (infile)
	{
		string line, word;//分别保存来自输入的一行和单词
		//vector<personInfo> people;  //保存来自输入的所有记录
		//逐行从输入读取数据，直至文件尾（或其他错误）
		while (getline(infile, line))
		{
			personInfo info;//创建一个保存此记录数据的对象
			istringstream record(line); //将记录绑定到刚读入的行
			record >> info.name;  //读取名字
			while (record >> word)   //读取电话号码
			{
				info.phones.push_back(word);  //保持它们
			}
			people.push_back(info);
		}
	}
	else
	{
		cerr << "no phone numbers?" << endl;
		return;
	}
	for (const auto &entry:people)  //对people中的每一项
	{
		ostringstream formatted, badNums; //每个循环步创建的的对象
		for (const auto &nums:entry.phones)  //对每个数
		{
			if (!valid(nums))
			{
				badNums << " " << nums;  //将数的字符串形式存入badNums
			}
			else
			{
				//将格式化的字符串“写入”formatted
				formatted << " " << format(nums);
			}
		}
		if (badNums.str().empty())
		{
			cout << entry.name << " " << formatted.str() << endl;
		}
		else
		{
			cerr << "input error: " << entry.name << "invalid number(s) " << badNums.str() << endl;
		}
	}
}
 
int main()
{
	/*
	istream& is = foo(cin);
	cout << is.rdstate() << endl;*/
	vector<string> ret;
	cout << "\n" << "练习8.4---" << endl;
	foo1("D:/my codes/rely on VS/第八章IO库/test.txt",ret);
	istringstream record;
	for (auto& s:ret)
	{
		record.str(s);
		string c;
		while (record>>c)
		{
			cout << c << endl;
		}
	}
	//istringstream iss("hello");
	//foo(iss);
	vector<personInfo> people;
	process("D:/my codes/rely on VS/第八章IO库/phoneNumber.txt",people);
	system("pause");
	return 0;
}