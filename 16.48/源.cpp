#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::ostream;

template<typename T> 
void debug_rep(const T& t)
{
	ostream ret;
	ret << t;
}

int main()
{
	string s = "woshinibaba";
	debug_rep(s);
	system("pause");
	return 0;
}