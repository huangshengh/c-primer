#include <iostream>
using namespace std;

void swap(int* &p, int* &n)//������ָ�����õ�ָ�롣�����Ļ��������Է�������ֵ������������ǶԱ�����ַ�����á�
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