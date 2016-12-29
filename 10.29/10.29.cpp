#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main()
{
	ifstream ifs("D:\\data.txt");
	istream_iterator<string> in(ifs), eof;
	ostream_iterator<string> out(cout, " ");
	vector<string> vec;
	copy(in, eof, back_inserter(vec));
	for (const auto c : vec)
		*out++ = c;
	cout << endl;
	system("pause");
	return 0;
}