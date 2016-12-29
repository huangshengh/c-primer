#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	list<int> l;
	fill_n(back_inserter(l), 10, 0);//这里是用back_insert，因为l是空容器。所以使用back_insert来创建一个迭代器，并用push_back来赋值
	for (auto c : l)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}