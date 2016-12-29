#include "ex14.05.h"

int main()
{
	Book b1(123, "CP5", "LIPMAN", "2012");
	Book b2(123, "CP5", "LIPMAN", "2012");

	if (b1 == b2)
		std::cout << b1 << std::endl;
	std::cout << "enter no" << " " << "enter name" << " " << "enter author" << " " << std::endl;
	Book b3;
	std::cin >> b3;
	std::cout<<"\n" << b3 << std::endl;
	system("pause");
	return 0;
}