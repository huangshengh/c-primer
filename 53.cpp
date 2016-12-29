#include <iostream>
using namespace std;

int main()
{
	int sum = 0, val = 1;
	while (val <= 10)
		 sum += val,++val;
	cout << "sum of 1 to 10 is " << sum << endl;
	system("pause");
	return 0;
}