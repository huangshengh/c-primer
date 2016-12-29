#ifndef Screen_h
#define Screen_h

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

template<unsigned H,unsigned W>
class Screen
{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(char c):contents(H*W,c){}
	char get()const
	{
		return contents[cursor];
	}
	Screen& move(pos r, pos c);
	friend std::ostream & operator<<(std::ostream&os, const Screen<H, W> & c)
private:
	pos cursor = 0;
	pos height = H, width = W;
	string contents;
};

#endif // !Screen_h#pragma once
