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

int main()
{
	vector<string> book{ "you","should","learn","how","to","forget","it","to","be","better" };
	elimDups(book);
	system("pause");
	return 0;
}