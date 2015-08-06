#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;

int main()
{
	/*单词计数器*/
//	/*
	unordered_map<string, size_t> word_count;
	string word;
	set<string> exclude = {"a","an"};
	while (cin>>word)
	{
		if (exclude.find(word) == exclude.end())
		{
			++word_count[word];
		}
		
	}
	auto map_it = word_count.cbegin();
	while (map_it!=word_count.cend())
	{
		cout << map_it->first << "出现 " << map_it->second << ((map_it->second >1) ? "times" : "time") << endl;
		++map_it;
	}
	system("pause");
	return 0;
}