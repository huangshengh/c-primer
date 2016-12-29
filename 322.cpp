#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string text("hello this is test one");
	for (auto it = text.begin(); it != text.end() && !isspace(*it); it++)
	{
		*it = toupper(*it);
		cout << *it << endl; 
	}
	system("pause");
	return 0;
}