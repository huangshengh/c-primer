#include "19.h"
#include <fstream>
#include <iostream>

int main()
{
	StrBlob blob;
	for (std::string str; std::getline(std::cin, str); )
		blob.push_back(str);
	std::cout << std::endl;
	for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
		std::cout << pbeg.deref() << std::endl;
	system("pause");
	return 0;
}