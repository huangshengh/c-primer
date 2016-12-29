#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

template<typename T>
void swap(T& a, T&b)
{
	using std::swap;
	swap(a, b);
}

int main()
{
	string a = "ni", b = "wo";
	swap(a, b);
	int c = 1, d = 2;
	swap(c, d);
	system("pause");
	return 0;
}