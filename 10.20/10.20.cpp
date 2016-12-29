#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());//先将words按字典序排列
	//在讲words中重复的放在后面，返回的是不重复部分后一个位置的迭代器
	auto end_unique = unique(words.begin(), words.end());
	//删除，这样words中就没有相同的string元素了
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	//使用stable_sort让长度相同的元素按照原来的排序，长的元素排在后面但是都遵循字典序
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	//返回有多个让谓词成真
	auto count = count_if(words.begin(), words.end(), [sz](const string &a) {return a.size() > sz; });
	cout << count << endl;
}


int main()
{
	vector<string> str{ "wodemaya","zenmexue","xiaqua" };
	biggies(str, 6);
	system("pause");
	return 0;
}
