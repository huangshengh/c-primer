#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int>::iterator iffind(vector<int>::iterator a, vector<int>::iterator b, int X)
{
	vector<int>::iterator d;
	while (a <= b)//a��b����begin��end
	{
		if ((*a) == X)
		{
			d = a;
			break;//break���ֻ����ֹ���������for while do-while��switch��䡣 
		}
		else
			++a;
	}
	return d;
}