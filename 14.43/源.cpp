#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;

int main()
{
	auto data = { 2,3,4,5,6 };
	int input;
	cin >> input;
	std::modulus<int> mod;
	auto predicator = [&](int i) {return 0 == mod(input, i); };
	auto is_divisible = std::any_of(data.begin(), data.end(), predicator);
	cout << (is_divisible ? "Yse" : "NO") << std::endl;
	system("pause");
	return 0;
}