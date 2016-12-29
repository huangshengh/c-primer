#include <iostream>
#include <memory>

int main()
{
	auto sp = std::make_shared<int>();
	auto p = sp.get();
	delete p;
	system("pause");
	sp=nullptr;
	return 0;
}