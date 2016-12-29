#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Screen
{
public:
	typedef string::size_type pos;//s,size()��������string�������ַ���������Ҳ��size_type���͵�
								  //���ͳ�Ա��Ҫ�ȶ�����ʹ�á��ȼ���using pos = string::size_type;

	Screen() = default;//����Ĭ�Ϲ��캯����
	Screen(pos ht, pos wd) :height(ht), width(wd) {}//ʹ����Ĭ��ʵ�Σ�Ĭ��ʵ��֮��Ĳ�����������Ĭ��ֵ�����ú�����ʱ���Ǵӵ�һ��������ʼ�ġ�
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}
	
	//ί�й��캯��
	Screen(char c) : Screen(5, 5, c) { cout << "used" << endl; }
	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(ostream &os)//���ݶ����Ƿ���const�����غ���
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
	//�����Ƿ���const����ִ�еĲ�����һ����ֻ��thisָ��ͷ���ֵ��ͬ�����Կ��Զ���һ��������ʾ����������������غ����������
	void do_display(ostream &os)const { os << contents; }
};



inline Screen & Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}//���ص��ǵ�����������Ķ��������

char Screen::get(pos r, pos c)const
{
	pos row = r * width;
	return contents[row + c];
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this; //��this������Ϊ��ֵ���أ�
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