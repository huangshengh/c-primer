#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
	ifstream is;
	int size = 100000;
	char sink [100000];
	char delim = '\t';
	is.open("D:\\t.txt");
	while (is.getline(sink, size,'\t'))
		cout << sink << endl;

	system("pause");
	return 0;
}