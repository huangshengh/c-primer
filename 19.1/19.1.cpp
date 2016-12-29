#include <iostream>
#include <string>
#include <new>
#include <cstdlib>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::bad_alloc;

void * operator new(size_t size)
{
	if (void * mem = malloc(size))
		return mem;
	else
		throw std::bad_alloc();
}

void  operator delete(void *mem) noexcept
{
	free(mem);
}

int main()
{
	

}