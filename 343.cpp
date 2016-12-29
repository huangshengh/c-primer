#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};
	for (int(*p)[4] = begin(ia); p != end(ia); ++p)
	{
		for (int *q = begin(*p); q != end(*p); ++q)
			cout << *q << ' ';
		cout << endl;
	}
	system("pause");
	return 0;
}