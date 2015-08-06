#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

int main()
{
	//exercise 11.2/11.3 单词计数程序
	/*
	string s;
	map<string, size_t> wordCount;
	while (cin >> s)
	{
		for (auto &c:s)
		{
			c = tolower(c);
		}
		s.erase(remove_if(s.begin(),s.end(),ispunct),s.end());
		++wordCount[s];
	}
	for (const auto &w : wordCount)
	{
		cout << w.first<<" occurs "<< w.second << (w.second > 1? " times":" time") << endl;
	}*/

	//exercise 11.7
	/*
	map<string, vector<string>> family;
	string lastname;
	string chilName;
	while (cout << "PLZ enter LastName: " << endl && cin >> lastname && lastname != "@q")
	{
		cout << "PLZ enter chilName: "<< endl;
		while (cin>> chilName && chilName!="@q")
		{
			family[lastname].push_back(chilName);
		}
	}
	//! iterate through the map.
	for (auto e : family)
	{
		cout << e.first << ":\n";

		//! iterate through the vector.
		for (auto c : e.second)
			cout << c << " ";
	    cout << "\n";
	}*/
	//exercise 11.9
	/*
	map<string, list<size_t>>  m;

	//exercise 11.10
	map<vector<int>::iterator, int> mv;
	map<list<int>::iterator, int> ml;

	vector<int> vi;
	list<int> li;
	mv.insert(make_pair(vi.begin(),0));
	ml.insert(make_pair(li.begin(),0));*/

	//exercise 11.12
	/*
	vector<pair<string, int>> vp;
	pair<string, int> temp;
	string s;
	int num;
	//版本一
	while (cin>>s>>num)
	{
		temp.first = s;
		temp.second = num;
		vp.push_back(temp);
	}
	//版本二
	while (cin >> s >> num)
	{
		vp.push_back(make_pair(s, num));
	}
	//版本三
	while (cin >> s >> num)
	{
		vp.push_back({s,num});
	}
	//版本四
	while (cin >> s >> num)
	{
		vp.emplace_back(s,num);
	}*/

	//exercise 11.14
	//在excercise 11.7 的基础上保存生日
	/*
	map<string, vector<pair<string,string>>> family;
	string lastname;
	string chilName;
	string birthday;
	while (cout << "PLZ enter LastName: " << endl && cin >> lastname && lastname != "@q")
	{
		cout << "PLZ enter chilName: " << endl;
		while (cin >> chilName >> birthday && chilName != "@q")
		{
			family[lastname].emplace_back(chilName,birthday);
		}
	}
	//! iterate through the map.
	for (auto e : family)
	{
		cout << e.first << ":\n";

		//! iterate through the vector.
		for (auto c : e.second)
			cout << c.first << " "<< c.second;
		cout << "\n";
	}*/
    
     //exercise 11.18 
     /*
     map<string, size_t> word_count;
	 map<string, size_t>::const_iterator it = word_count.cbegin();
	 for (; it != word_count.cend(); it++)
	 {
	 cout << it->first << " " << it->second << endl;
	 }*/

    //exercise 11.22
    /*
    map<string, vector<int>> mv;
	pair<map<string, vector<int>>::iterator, bool> ret;
	string s;
	vector<int> vi;
	ret = mv.insert(make_pair(s,vi));*/

    //excercise 11.28
    /*
    map<string, vector<int>> m;
	m = { { "Alan", { 1, 2, 3, 4, 5, } }, { "John", { 1, 5, 6, 7, 8 } } };
	string s;
	vector<int> temp;
	map<string, vector<int>>::iterator it = m.find(s);*/
    
    //exercise 11.31 11.32
    /*
    multimap<string, string> authors{ { "alan", "DMA" },
                                      { "pezy", "LeetCode" },
                                      { "alan", "CLRS" },
                                      { "wang", "FTP" },
                                      { "pezy", "CP5" },
                                      { "wang", "CPP-Concurrency" } };
	for (auto& c : authors)
	{
		cout << c.first << "  " << c.second << endl;
	}
	//pair<multimap<string, string>::iterator, multimap<string, string>::iterator> pos;
	for (auto pos = authors.equal_range("pezy"); pos.first != pos.second;)
	{
		pos.first = authors.erase(pos.first);
	}
	cout << "删除后的结果：" << endl;
	for (auto& c:authors)
	{
		cout << c.first<<"  "<< c.second << endl;
	}*/
    
    
	system("pause");
	return 0;
}