#include <iostream>
#include <string>
using namespace std;

int main()
{
	string numbers{ "123456789" };
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string str{ "ab2c3d7R4E6" };
    
	for (string::size_type pos = 0; (pos = str.find_first_not_of(numbers, 0)) != string::npos; ++pos)
		str.erase(pos,1);
	for (auto c : str)
		cout << c << " ";
	cout << "\n";
	system("pause");
	return 0;

}