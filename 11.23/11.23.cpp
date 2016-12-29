#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	multimap<string, string>names;
	cout << "input your name:" << endl;
	for (string lname, cname; cin >> cname >> lname; names.emplace(lname, cname));
	for (auto const& name :names)
		std::cout << name.second << " " << name.first << endl;
	system("pause");
	return 0;

}