#include <iostream>
#include <initializer_list>
using namespace std;

int plusa(initializer_list<int> li)
{
	int a=0;
	for (auto beg = li.begin(); beg != li.end(); ++beg)
		a += *beg;
	return a;
}

int main()
{
	int b = plusa({ 1,2,3,4,5,6,7,8,9,10 });
	cout << b << endl;
	system("pause");
	return 0;
}