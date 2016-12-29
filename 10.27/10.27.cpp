#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<string> str{ "nihao","nihao","nihao","wohao","nixianzai","nihao" };
	list<string>list1;
	//很重要两点是，一unique只会检查相邻的重复，二，copy呢是要改变list的，所以需要用到插入迭代器。
	unique_copy(str.begin(), str.end(),back_inserter(list1));
	for_each(list1.begin(), list1.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
	system("pause");
	return 0;
}