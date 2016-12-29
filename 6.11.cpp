#include <iostream>
using namespace std;


int reset(int & i)
{
	i = 0;
	return 0;
}

int main()
{
	int a = 10;
	reset(a);
	cout << a << endl;
	system("pause");
	return 0;
}