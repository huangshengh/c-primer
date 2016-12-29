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
	auto name = ch16::make_ptr<string>(10, '9');//显示的使用模板实参，显示模板实参按从左到右的顺序. 
	std::cout << *name << '\n';
	system("pause");
	return 0;  
}