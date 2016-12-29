#include <iostream>
#include <string>
using namespace std;

bool upper(const string &s)
{
	bool a;
	for (auto i = 0; i != s.size()-1; ++i)
	{
		if (isupper(s[i]))
		{
			a = true;
			break;
		}
		else
			a = false;
	}
	return a;
}


int main()
{
	string sentence;
	cout << "input a sentence:" << endl;
	cin >> sentence;
	if (upper(sentence))
		cout << "there is upper." << endl;
	else
		cout << "ther is no upper." << endl;
	system("pause");
	return 0;
}