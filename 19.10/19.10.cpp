#include <iostream>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	class A
	{
	public:
		A() = default;
		virtual ~A()=default;
	};
	class B :public A
	{
	public:
		B() = default;
		virtual ~B()=default;
	};
	class C :public B
	{
	public:
		C() = default;
		virtual ~C()=default;
	};

	A *pa = new C;
	cout << typeid(pa).name() << endl;
	C cobj;
	A & ra = cobj;
	cout << typeid(&ra).name() << endl;
	B *px = new B;
	A& ra2 = *px;
	//cout << typeid( &ra2).name << endl;
	system("pause");
	return 0;
}