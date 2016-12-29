#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	size_t a, b, c, d, e, f, g, h, i, j, k, l;
	a = sizeof(int);
	b = sizeof(char);
	c = sizeof(wchar_t);
	d = sizeof(short);
	e = sizeof(int);
	f = sizeof(long);
	g = sizeof(long long);
	h = sizeof(float);
	i = sizeof(double);
	j = sizeof(long double);
	k = sizeof(string);
	l = sizeof(vector<int>);
	cout << a <<' ' << b<<' ' << c <<' '<< d << ' '<< e<<' ' << f<<' ' << g<<' ' << h<<' ' << i<<' ' << j<<' ' << k<<' ' << l << endl;
	system("pause");
	return 0;

}