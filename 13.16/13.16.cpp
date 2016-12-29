#include <iostream>

using std::cout;
using std::endl;

//拷贝初始化是使用拷贝构造函数实现的
//拷贝初始化是使用拷贝构造函数实现的
//拷贝初始化是使用拷贝构造函数实现的

class numbered
{
public:
	numbered() { mysn = ++unique; }
	numbered(const numbered &orig):mysn(orig.mysn+2){}
	int mysn;
	static int unique;
private:
	int bb;
};

int numbered::unique = 10;

void f(const  numbered& s)
//重点：
//如果这里的参数是一个引用类型的，那么这个函数只是调用实参而已，所以是参数是什么，输出的就是什么
//如果这里的参数不是一个引用类型，那么实参是通过拷贝初始化给形参，所以又调用一次拷贝构造函数，所以会再加一个2.  
{
	cout << s.mysn << endl;
}

int main()
{
	numbered a;//这里使用的是默认构造函数， 后面的使用的是拷贝构造函数
	cout << a.mysn << endl;
	numbered b=a;
	cout << b.mysn << endl;
	//b = a;对象已经存在不用创建，且用一个已经存在的对象进行初始化  就是使用拷贝赋值运算符;
	 numbered c = b;//对象被创建，且用一个已经存在的对象进行初始化  就是使用拷贝构造函数;
	 cout << c.mysn << endl;
	f(a);
	f(b);
	f(c);
	system("pause");
	return 0;
}