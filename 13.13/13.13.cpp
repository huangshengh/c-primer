#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
 

struct X
{
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&) 
	{ 
		std::cout << "X& operator=(const X&)" << std::endl; 
	    return *this;
	}//拷贝复制运算符，使用的时候要返回左值。
	~X() { std::cout << "~X()" << std::endl; }
};  

void f(const X&rx, X x)
{
	std::vector<X> vec;
	vec.reserve(2);
	vec.push_back(rx);
	vec.push_back(x);
	//在函数调用完成之后，会使用和析构和函数来销毁vector和X；
}

int main()
{
	X *px = new X;//这里使用默认构造函数来初始化这个类X
	f(*px, *px);//拷贝构造函数是用来初始化的，拷贝复制运算符是用来赋值的。
	X c;
	c = *px;//这里用的应该是拷贝赋值运算符；
	system("pause");
	return 0;
}