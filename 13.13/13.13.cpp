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
	}//���������������ʹ�õ�ʱ��Ҫ������ֵ��
	~X() { std::cout << "~X()" << std::endl; }
};  

void f(const X&rx, X x)
{
	std::vector<X> vec;
	vec.reserve(2);
	vec.push_back(rx);
	vec.push_back(x);
	//�ں����������֮�󣬻�ʹ�ú������ͺ���������vector��X��
}

int main()
{
	X *px = new X;//����ʹ��Ĭ�Ϲ��캯������ʼ�������X
	f(*px, *px);//�������캯����������ʼ���ģ����������������������ֵ�ġ�
	X c;
	c = *px;//�����õ�Ӧ���ǿ�����ֵ�������
	system("pause");
	return 0;
}