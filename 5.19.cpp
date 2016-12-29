#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cout << "enter two sentence:" << endl;
	cin >> s1 >> s2 ;
	auto i1 = s1.size(), i2 = s2.size();
	string s;
	s = i1 > i2 ? s1 : s2;
	cout << s << endl;
	system("pause");
	return 0;
}