#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
	list<int> intl{ 1,2,3,4,5,6,7 };
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
	vector<int> ivec1(intl.begin(), intl.end());//用迭代器来初始化顺序容器，
	if (ivec1 > ivec)
		cout << "list is larger" << endl;
	else
		cout << "vector is larger" << endl;
	system("pause");
	return 0;
}