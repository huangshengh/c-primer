#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

bool iffind(vector<int>::iterator a, vector<int>::iterator b, int X)
{
	bool m = false;
	while (a != b)
	{
		if ((*a) == X)
			m = true;
		else
			++a;
	}
	return m;
}