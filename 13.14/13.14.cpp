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
	numbered a, b = a, c = b;//����ʹ�õ��ǺϳɵĿ�����ֵ����������Ǽ򵥵�ȫ����a����b��c
	f(a);
	f(b);
	f(c);
	system("pause");
	return 0;
}