#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
	std::cout << ptr.use_count() << std::endl;
}

int main()
{
	//std::shared_ptr<int>
	int *p= new int(42);
	process(std::shared_ptr<int>(p));
	//std::wcout << p.use_count() << std::endl;
	//auto q = p;
	//std::cout << p.use_count() << std::endl;
	//std::cout << *p << std::endl;
	system("pause");
	return 0;
}