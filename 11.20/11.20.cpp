#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	map<string, size_t>word_count;
	string word;
	cout << "input words:" << endl;
	while (cin >> word)
	{
		auto ret = word_count.insert({ word,1 });
		if (!ret.second)
			++ret.first->second;
	}
	for (auto c : word_count)
		cout << c.first << " " << "occurs" << c.second <<" " << ((c.second > 1) ? "times" : "time") << endl;
	system("pause");
	return 0;
}