#include <iostream>
#include <string>
using namespace std;

int main(int argc, char**argv)
{
	string str;
	for(int i = 1;i<=argc;++i)
		str += string(argv[i]) + " ";

	cout << str << endl;
	system("pause");
	return 0;
}