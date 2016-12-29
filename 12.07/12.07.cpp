#include <iostream>
#include <vector>
#include <memory>

using Sptr = std::shared_ptr<std::vector<int>>;

auto make_with_shared_ptr()
{
	return std::make_shared<std::vector<int>>();
}

auto populate(Sptr vec)
{
	for (int i; std::cout << "Please enter:\n", std::cin >> i; vec->push_back(i));
	return vec;
}

auto print(Sptr vec)->std::ostream&
{
	for (auto i : *vec)
		std::cout << i << " ";
	return std::cout;
}

int main()
{
	auto vec = populate(make_with_shared_ptr());
	print(vec) << std::endl;
	system("pause");
	return 0;
}