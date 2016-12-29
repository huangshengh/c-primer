#include <iostream>
#include <vector>
#include <list>
#include <string>

// the same as std::begin
template<typename T, unsigned size>
T* begin_def(T(&arr)[size])
{
	return arr;
}


// the same as std::end
template<typename T, unsigned size>
T* end_def(T(&arr)[size])
//We usually don't use a function name which is the same as the function of standard libary
//This should not be const
{
	return arr + size;
}

int main()
{
	std::string s[] = { "sssss","ss","ss","ssssszzzz" };
	std::cout << *(begin_def(s) + 1) << std::endl;
	std::cout << *(end_def(s) - 1) << std::endl;
	return 0;
}