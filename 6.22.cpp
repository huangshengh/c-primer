#include <iostream>
using namespace std;

void swap(int* &p, int* &n)//参数是指向引用的指针。这样的话函数可以返回两个值，他这个引用是对变量地址的引用。
{
	auto temp = p;
	p = n;
	n = temp;
}

int main()
{
	int a = 3, b = 4;
	int * k = &a;
	int * j = &b;
	swap(k, j);
	cout << *k << ' ' << *j << endl;
	system("pause");
	return 0;
}