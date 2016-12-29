#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> v(begin(a), end(a));
	int b[10];
	int *p = b;
	for (auto c : v)
	{
		*p = c;
		*p++;
	}
	for (auto i : b)
		cout << i << ' ';

	system("pause");
	return 0;
}