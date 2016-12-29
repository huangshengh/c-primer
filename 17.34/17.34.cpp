#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	cout << std::boolalpha << true << " " << false << std::noboolalpha << endl;
	cout << true << " " << false << endl;
	cout << std::uppercase << std::showbase << std::hex << 20 << " " << 1024 << std::nouppercase << std::noshowbase << std::dec << endl;
	cout << "default format: " << 100 * sqrt(2.0) << '\n' << "scientific" << std::scientific << \
		100 * sqrt(2.0) << '\n' << "fixed decimal" << std::fixed << 100 * sqrt(2.0) << '\n' << \
		"hexadecimal: " << std::hexfloat << 100 * sqrt(2.0) << '\n' << "use default: " << std::defaultfloat << \
		100 * sqrt(2.0) << '\n';
	system("pause");
	return 0;
}