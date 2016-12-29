#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

template<typename T> void f(T t)
{
	cout << t << endl;
}
template<typename T> void f(const T* t)
{
	cout << *t << endl;
}
template<typename T> void g(T t)
{
	cout << t << endl;
}
template<typename T> void g(T* t)
{
	cout << *t << endl;
}

int main()
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42);
	g(p);
	g(ci);
	g(p2);
	f(42);
	f(p);
	f(ci);
	f(p2);
	system("pause");
	return 0;
}