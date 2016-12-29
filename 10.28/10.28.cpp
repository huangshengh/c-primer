#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
using namespace std;

int main()
{
	vector<int>vec1{ 1,2,3,4,5,6,7,8,9 };
	vector<int>vec2, vec3;
	list<int> list1;
	copy(vec1.cbegin(), vec1.cend(), back_inserter(vec2));//1,2,3,
	copy(vec1.cbegin(), vec1.cend(), inserter(vec3, vec3.begin()));//1,2,3,
	copy(vec1.cbegin(), vec1.cend(), front_inserter(list1));//9,8,7,vector不能使用front
	for (const auto s : vec2)
		cout << s << " ";
	cout << endl;
	for (const auto s : vec3)
		cout << s << " ";
	cout << endl;
	for (const auto s : list1)
		cout << s << " ";
	cout << endl;
	system("pause");
	return 0;
}