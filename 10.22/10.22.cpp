#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std::placeholders;
using namespace std;

//在这里先确定所需要的函数不管这个函数需要几个参数都是可以的，函数可以在不同的泛型算法中使用
bool check_size(const string &s, string::size_type sz)
{
	return s.size() > sz;
}



void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());//先将words按字典序排列
									 //在讲words中重复的放在后面，返回的是不重复部分后一个位置的迭代器
	auto end_unique = unique(words.begin(), words.end());
	//删除，这样words中就没有相同的string元素了
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words)
{
	elimDups(words);
	//使用stable_sort让长度相同的元素按照原来的排序，长的元素排在后面但是都遵循字典序
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	//返回有多个让谓词成真，使用bind函数让，参数个数满足算法的需要。
	auto count = count_if(words.begin(), words.end(), bind(check_size, _1, 6) );
	cout << count << endl;
}


int main()
{
	vector<string> str{ "wodemaya","zenmexue","xiaqua" };
	biggies(str);
	system("pause");
	return 0;
}
