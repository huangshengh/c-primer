#include <iostream>
#include <string>
#include <memory>
#include <vector>

using std::string;
using std::vector;
using std::allocator;


struct Deletee
{
	template<typename T>
	auto operator() (T* p) const
	{
		delete p;
	}
};

template <typename T>
T* class shareptr
{
	shareptr (T)
private: 
	T* ptr;
	allocator<T> alloc;
};
