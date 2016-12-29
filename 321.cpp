#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(10,42);
	for (auto i = v.cbegin(); i != v.cend() && !isspace(*i); ++i)
		cout << (*i) << endl;
	system("pause");
	return 0;
}