#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
	vector<string> str{"hello","you","stupid","fool"};
	list<int>list1{ 1,2,3,4 };
	pair<string, int> ha;
	vector<pair<string,int>> vec;
	for (auto c : str)
	{
		for (auto d : list1)
		{
			ha = make_pair(c, d);
			vec.push_back(ha);
		}
	}
	for (auto c : vec)
		cout << c.first<<" "<<c.second << endl;
	system("pause");
	return 0;

}