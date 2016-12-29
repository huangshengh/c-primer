#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word, temp;
	cout << "enter a word once:" << endl;
	while (cin >> word && !word.empty())
	{
		if (word == temp)
		{
			if (isupper(word[0]))
				break;
			else
				continue;
		}
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