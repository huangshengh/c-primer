#include <vector>
#include <iostream>

std::vector<int>* make()
{
	std::vector<int> *p = new std::vector<int>{ 1,2,3,4,5,6 };
	return p;
}

std::vector<int> read()
{
	std::vector<int> vec;
	auto a = make();
	auto b = *a;
	for (auto c : b)
		vec.push_back(c);
	return vec;
}

void out()
{
	auto d = read();
	for (auto e : d)
		std::cout << e << " ";
	std::cout << std::endl;
}

int main()
{
	out();
	//这个make返回的是指向vector的指针。
	delete make();
	system("pause");
	return 0;
}