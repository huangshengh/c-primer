#include "12.19.h"
#include <iostream>

int main()
{
	StrBlob blob;
	for (std::string str; std::getline(std::cin, str); )
		blob.push_back(str);
	
	system("pause");
	return 0;
}