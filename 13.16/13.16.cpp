#include <iostream>

using std::cout;
using std::endl;

//������ʼ����ʹ�ÿ������캯��ʵ�ֵ�
//������ʼ����ʹ�ÿ������캯��ʵ�ֵ�
//������ʼ����ʹ�ÿ������캯��ʵ�ֵ�

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
//�ص㣺
//�������Ĳ�����һ���������͵ģ���ô�������ֻ�ǵ���ʵ�ζ��ѣ������ǲ�����ʲô������ľ���ʲô
//�������Ĳ�������һ���������ͣ���ôʵ����ͨ��������ʼ�����βΣ������ֵ���һ�ο������캯�������Ի��ټ�һ��2.  
{
	cout << s.mysn << endl;
}

int main()
{
	numbered a;//����ʹ�õ���Ĭ�Ϲ��캯���� �����ʹ�õ��ǿ������캯��
	cout << a.mysn << endl;
	numbered b=a;
	cout << b.mysn << endl;
	//b = a;�����Ѿ����ڲ��ô���������һ���Ѿ����ڵĶ�����г�ʼ��  ����ʹ�ÿ�����ֵ�����;
	 numbered c = b;//���󱻴���������һ���Ѿ����ڵĶ�����г�ʼ��  ����ʹ�ÿ������캯��;
	 cout << c.mysn << endl;
	f(a);
	f(b);
	f(c);
	system("pause");
	return 0;
}