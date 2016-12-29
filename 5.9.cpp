#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	string text;
	int count = 0;
	while (cin >> text)
	{
		for (auto i : text)
		{
			if (i == 'a' || i == 'e')
	        	count += 1;
			else if (i == 'i' || i == 'o')
				count += 1;
			else if (i == 'u')
				count += 1;
			else
				count += 0;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
