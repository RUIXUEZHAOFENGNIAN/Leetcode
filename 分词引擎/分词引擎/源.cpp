#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> dictionary{"我","吃饭","一","个人"};
vector<string> ret;
size_t maxLenOfword = 5;


//基于字典的逆向最大分词算法,分析如下
/*从后向前读入待分词字符串，读入字符串的长度由分词字典中最长单词决定。之后测试读入的字符串是否存在在字典中，如果
存在的话，从原始文本中删除这个字符串，开始重复。如果读入的字符串不存在在字典中，从左向右减小其长度重复在字典中查找，如此循环。*/
void reverseMaxSegment(string& input)
{
	if (dictionary.empty())
	{
		cout <<"字典词库为空，请添加词汇" << endl;
		return;
	}
	while (input.size() > 0)
	{
		//temp是待分割的词汇
		string temp;
		if (input.size() <= maxLenOfword)
		{
			temp = input;
		}
		else
		{
			size_t len = input.length();
			temp = input.substr(len-maxLenOfword+1,maxLenOfword);
		}
		while (temp.size() > 0)
		{
			auto it = find(dictionary.begin(), dictionary.end(), temp);
			//在词典中找到词汇
			if (it != dictionary.end() || temp.length() == 1)
			{
				cout << temp << endl;
				ret.insert(ret.begin(),temp+"/");
				//在删除原始字符串的这部分
				input = input.substr(0,input.length()-temp.length());
				break;

			}
			else//再次分割
			{
				temp = temp.substr(1,temp.length()-1);
			}
		} 
	}
	for (auto &c : ret)
		cout << c << " ";
}

//基于字典的正向最大分词
/* 和逆向正好相反，从输入Strign的最开始开始读入待分词短语，在字典中查找，如果找不到的话将分词短语变短，如此循环 */
int main()
{
	string input("我一个人吃饭");
	reverseMaxSegment(input);
	cout << endl;
	system("pause");
	return 0;
}
