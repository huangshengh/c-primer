#include <bitset>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v{ 1,2,3,5,8,13,21 };
	std::bitset<32> bits;
	for (auto i : v)
		bits.set(i);
	std::bitset<32 >bit1;
	std::cout << bits << std::endl;
	std::cout << bit1 << std::endl;
	system("pause");
	return 0;
}