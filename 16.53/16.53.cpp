#include <iostream>
#include <string>

using std::ostream;
using std::cout;
using std::endl;
using std::string;


template<typename T, typename... Args>
ostream& print(ostream& os, const T &t, const Args&...rest)
{
	os << t << ", ";
	return print(os, rest...);//rest中第一个参数绑定到t，剩下的继续形成一个参数包
}

template<typename T>
ostream& print(ostream& os, const T& t)
{
      return os << t;
}

int main()
{
	string a, b, c, d;
	a = "ni", b = "wo", c = "ta", d = "a";
	double i = 1.2;
	double di = 2.1;
	print(cout, a, b, c, d, i, di);
	system("pause");
	return 0;
}