#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i : a)
	{
		int b[10];
		for (auto n : b)
		{
			n = i;
			cout << n << endl;
		}
	}
	system("pause");
	return 0;
}