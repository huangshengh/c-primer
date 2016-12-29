#include <string>
#include <vector>
#include <list>
#include <deque>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

template<typename T>
std::ostream& output(const T& rhs,std::ostream& os)
{
	typedef T::size_type size_type;
	size_type length = rhs.size();
	size_type i = length - length;
	for (i; i <= length; ++i)
		os << rhs[i] << " ";
	os << endl;
	return os;
}

int main()
{
	vector<string> vec{ "wo","ren","shi","dao" };
    output(vec,cout); 
	system("pause");
	return 0;
}