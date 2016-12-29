#include <iostream>
#include <string>
#include <map>
#include <functional>

using std::string;
using std::function;
using std::map;

int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) {return i%j; };
struct Div
{
	int operator()(int i, int j)const
	{
		return i / j;
	}
};

auto binops = map<string,function<int(int,int)>>
{
	{"+",add},
	{"-",std::minus<int>()},
	{"/",Div()},
	{"*",[](int i,int j) {return i*j; }},
	{"%",mod}
};


int main()
{
	while(true)
	{
		std::cout << "enter\n";
		int lhs, rhs;
		string op;
		std::cin >> lhs >> op >> rhs;
		std::cout << binops[op](lhs, rhs) << std::endl;
	}
	system("pause");
	return 0;
}
