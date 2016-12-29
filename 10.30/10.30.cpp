#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	istream_iterator<int> in(cin), eof;
	vector<int>vec;
	while (in!=eof)
		//重点是push_back里面的istream_iterator需要解迭代器并且还需要递增，不能直接使用
		vec.push_back(*in++);
	sort(vec.begin(), vec.end());
	ostream_iterator<int>out(cout, " ");
	for (const auto c : vec)
		*out++ = c;
	cout << endl;
	system("pause");
	return 0;
}