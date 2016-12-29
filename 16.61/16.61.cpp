#include <iostream>
#include <memory>
#include <string>
#include <utility>

using std::string;

namespace ch16
{
	template<typename T,typename...Args>
	std::shared_ptr<T> make_ptr(Args&&...s)
	{
		return std::shared_ptr<T>(new T(std::forward<Args>(s)...));
	}
}


int main()
{
	auto name = ch16::make_ptr<string>(10, '9');//��ʾ��ʹ��ģ��ʵ�Σ���ʾģ��ʵ�ΰ������ҵ�˳��. 
	std::cout << *name << '\n';
	system("pause");
	return 0;  
}