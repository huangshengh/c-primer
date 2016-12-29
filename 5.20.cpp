#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word, temp;
	cout << "enter a word once:" << endl;
	while (cin >> word)
	{
		if (word == temp)
			break;
		else
			temp = word;
	}
	if (cin.eof())
		cout << "no word input twice" << endl;
	else
		cout << word << " occurs twice " << endl;
	system("pause");
	return 0;
}