#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> dictionary{"��","�Է�","һ","����"};
vector<string> ret;
size_t maxLenOfword = 5;


//�����ֵ���������ִ��㷨,��������
/*�Ӻ���ǰ������ִ��ַ����������ַ����ĳ����ɷִ��ֵ�������ʾ�����֮����Զ�����ַ����Ƿ�������ֵ��У����
���ڵĻ�����ԭʼ�ı���ɾ������ַ�������ʼ�ظ������������ַ������������ֵ��У��������Ҽ�С�䳤���ظ����ֵ��в��ң����ѭ����*/
void reverseMaxSegment(string& input)
{
	if (dictionary.empty())
	{
		cout <<"�ֵ�ʿ�Ϊ�գ�����Ӵʻ�" << endl;
		return;
	}
	while (input.size() > 0)
	{
		//temp�Ǵ��ָ�Ĵʻ�
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
			//�ڴʵ����ҵ��ʻ�
			if (it != dictionary.end() || temp.length() == 1)
			{
				cout << temp << endl;
				ret.insert(ret.begin(),temp+"/");
				//��ɾ��ԭʼ�ַ������ⲿ��
				input = input.substr(0,input.length()-temp.length());
				break;

			}
			else//�ٴηָ�
			{
				temp = temp.substr(1,temp.length()-1);
			}
		} 
	}
	for (auto &c : ret)
		cout << c << " ";
}

//�����ֵ���������ִ�
/* �����������෴��������Strign���ʼ��ʼ������ִʶ�����ֵ��в��ң�����Ҳ����Ļ����ִʶ����̣����ѭ�� */
int main()
{
	string input("��һ���˳Է�");
	reverseMaxSegment(input);
	cout << endl;
	system("pause");
	return 0;
}
