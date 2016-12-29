#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Screen
{
public:
	typedef string::size_type pos;//s,size()函数返回string对象中字符个数，他也是size_type类型的
								  //类型成员需要先定义在使用。等价于using pos = string::size_type;

	Screen() = default;//定义默认构造函数；
	Screen(pos ht, pos wd) :height(ht), width(wd) {}//使用了默认实参，默认实参之后的参数都必须有默认值，调用函数的时候，是从第一个参数开始的。
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}
	
	//委托构造函数
	Screen(char c) : Screen(5, 5, c) { cout << "used" << endl; }
	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(ostream &os)//根据对象是否是const来重载函数
	{
		do_display(os);
		return *this;
	}
	const Screen &display(ostream& os)const
	{
		do_display(os);
		return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	//不管是否是const对象执行的操作是一样的只是this指针和返回值不同，所以可以定义一个函数表示这个操作过程在重载函数里面调用
	void do_display(ostream &os)const { os << contents; }
};



inline Screen & Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}//返回的是调用这个函数的对象的引用

char Screen::get(pos r, pos c)const
{
	pos row = r * width;
	return contents[row + c];
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this; //将this对象作为左值返回；
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}



int main()
{
	Screen myscreen('a');
	system("pause");
	return 0;
}