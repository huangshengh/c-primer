#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool fivecharacter(const string &s1)
{
	return s1.size() > 5;
}

int main()
{
	vector <string> str{ "nishi","hao","haorema" };
	partition(str.begin(), str.end(), fivecharacter);
	for (const auto&c : str)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}