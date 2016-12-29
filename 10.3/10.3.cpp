#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
	vector<double> vec{ 1.0,2.0,3.0,4.0,5.0,65.0 };
	int sum = accumulate(vec.cbegin(), vec.cend(), 0);//
	cout << sum << endl;
	system("pause");
	return 0;
}