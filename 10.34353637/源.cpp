#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec{0, 2, 2, 5, 4, 3, 6, 8, 7, 9};
	vector<int> vec1;
	list<int> list1{ 0,1,0,2,3,6,5,0,8 };
	list<int>list2;
	//list是int的所以find里面不需要引号，那是表示一个字符的
	auto a = find(list1.crbegin(), list1.crend(), 0);
	cout << *a << endl;
	for (auto r = vec.cend()-1; r != vec.cbegin(); --r)
		cout << *r << " ";
	cout << endl;
	for (auto d = vec.cbegin(); d != vec.cend(); ++d)
	{
		if (3 <= (*d) && (*d) <= 7)
		{
			auto e = *d;
			vec1.push_back(e);
		}
		else
			continue;
	}
	sort(vec1.rbegin(),vec1.rend());
	copy(vec1.begin(), vec1.end(), back_inserter(list2.begin()));
	for (const auto c : list2)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}