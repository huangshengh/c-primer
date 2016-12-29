#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	string word;
	vector<string> test,vec;
	set<string> exclude = { "the","a","an","," };
	while (cin >> word)
	{
		if (exclude.find(word) == exclude.end())
			test.push_back(word);
		else
			continue;
	}
	for (auto c = test.begin(); c != test.end(); ++c)
	{
		auto e = *c;
		for (auto f = e.begin(); f != e.end(); ++f)
		{
			if (ispunct(*f))
			{
				e.erase(e.end()-1);
			}
			*f = tolower(*f);
		}
		vec.push_back(e);
	}
	for (const auto &m : vec)
		cout << m << " ";
	//for (const auto &h : test)
		//++word_count[h];
	//for (const auto &w : word_count)
		//cout << w.first <<" "<< "occurs"<<" " <<w.second << " "<<((w.second > 1)? "times" : "time" )<< endl;
	system("pause");
	return 0;
}