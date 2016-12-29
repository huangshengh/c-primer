#include <iostream>

using std::cout;
using std::endl;

class numbered
{
public:
	numbered() { mysn = unique++; }
	int mysn;
	static int unique; 
private:
	int bb;
};

int numbered::unique = 10;

void f(numbered s)
{
	cout << s.mysn << endl;
}

int main()
{
	numbered a, b = a, c = b;//这里使用的是合成的拷贝赋值运算符，就是简单的全部把a赋给b，c
	f(a);
	f(b);
	f(c);
	system("pause");
	return 0;
}