#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void Tset(istringstream & in )
{
	string word;
	ostringstream out;
	while (in >> word)
		out << word;
}

int main()
{
	cout << "enter a string" << endl;
	istringstream input;
}