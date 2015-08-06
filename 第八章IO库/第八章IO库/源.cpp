#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

//��ϰ8.1
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
	ifstream infile(fileName);   //����һ��ifstream���򿪸����ļ�
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
		string line, word;//�ֱ𱣴����������һ�к͵���
		//vector<personInfo> people;  //����������������м�¼
		//���д������ȡ���ݣ�ֱ���ļ�β������������
		while (getline(infile, line))
		{
			personInfo info;//����һ������˼�¼���ݵĶ���
			istringstream record(line); //����¼�󶨵��ն������
			record >> info.name;  //��ȡ����
			while (record >> word)   //��ȡ�绰����
			{
				info.phones.push_back(word);  //��������
			}
			people.push_back(info);
		}
	}
	else
	{
		cerr << "no phone numbers?" << endl;
		return;
	}
	for (const auto &entry:people)  //��people�е�ÿһ��
	{
		ostringstream formatted, badNums; //ÿ��ѭ���������ĵĶ���
		for (const auto &nums:entry.phones)  //��ÿ����
		{
			if (!valid(nums))
			{
				badNums << " " << nums;  //�������ַ�����ʽ����badNums
			}
			else
			{
				//����ʽ�����ַ�����д�롱formatted
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
	cout << "\n" << "��ϰ8.4---" << endl;
	foo1("D:/my codes/rely on VS/�ڰ���IO��/test.txt",ret);
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
	process("D:/my codes/rely on VS/�ڰ���IO��/phoneNumber.txt",people);
	system("pause");
	return 0;
}