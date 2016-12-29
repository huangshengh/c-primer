#include <iostream>

using std::cout;
using std::endl;

class numbered
{
public:
	numbered() { mysn = unique++; }
	numbered(const numbered &orig) : mysn(orig.mysn + 1){}
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
	numbered a, b = a, c = b;//这里是使用了拷贝构造函数。
	f(a);
	f(b);
	f(c);
	system("pause");
	return 0;
}