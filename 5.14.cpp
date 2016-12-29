#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<char> ch;
	char word;
	int i;
	cout << "enter a sentence:" << endl;
	while (cin >> word)
	{
		ch.push_back(word);
	}
	for(auto c:ch)
		cout << c; 
	system("pause");
	return 0;
}