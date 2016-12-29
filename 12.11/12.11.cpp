#include <iostream>
#include <memory>
#include <stdexcept>

void process(std::shared_ptr<int> ptr)
{
	std::cout << ptr.use_count() << std::endl;
}

int main()
{
	try
	{
		std::shared_ptr<int> p(new int(42));
		process(std::shared_ptr<int>(p.get()));
	}
	catch (std::runtime_error)
	{
		std::cout << std::endl;
	}
	system("pause");
 	return 0;
}