#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;


void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());//使用sort排序，之后的words都是排序之后的。
	for (auto c : words)
		cout << c << " ";
	cout << endl;
	auto end_unique = unique(words.begin(), words.end());//end_uniuqe的返回是消除重复之后的，不重复部分的后一个位置的迭代器。
	for (auto c : words)
		cout << c << " ";
	cout << endl;
	words.erase(end_unique, words.end());//把重复部分删除掉
	for (auto c : words)
		cout << c << " ";
	cout << endl;
}

bool isShorter(const string&s1, const string&s2)
{
	return s1.size() < s2.size();
}

int main()
{
	vector<string> str{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(str);
	//stable_sort维持想等元素的原有顺序
	stable_sort(str.begin(), str.end(), isShorter);//这里使用了谓词所以这里的<重载了，用isshoter来比较元素而不是之前的<
	for (const auto&s : str)
		cout << s << " ";
	cout << endl;
	system("pause");
	return 0;
}