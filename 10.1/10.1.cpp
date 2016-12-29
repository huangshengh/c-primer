#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> vec{ 1,1,2,2,3,4,5,6,7,1,10,11,1110 };
	auto result = count(vec.begin(), vec.end(), 1);
	cout << result << endl;
	system("pause");
	return 0;
}