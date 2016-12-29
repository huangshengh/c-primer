#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::bitset;

void question()
{
	bitset<10> bits;
	for (auto i = 0; i < 10; ++i)
	{
		cout << "question:" << endl;
		cin >> bits;
	}
	cout << "It's done" << endl;
	cout << bits << endl;

}

int main()
{
	question();
	system("pause");
	return 0;
}