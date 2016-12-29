#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int>::iterator iffind(vector<int>::iterator a, vector<int>::iterator b, int X)
{
	vector<int>::iterator d;
	while (a <= b)//a和b不是begin和end
	{
		if ((*a) == X)
		{
			d = a;
			break;//break语句只能终止离他最近的for while do-while，switch语句。 
		}
		else
			++a;
	}
	return d;
}