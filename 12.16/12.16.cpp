#include <iostream>
#include <string>
#include <memory>

using std::string;
using std::unique_ptr;

int main()
{
	unique_ptr<string> p1(new string("busy"));
	unique_ptr<string> p2(p1.release());
	system("pause");
	return 0;
}