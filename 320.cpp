#include <iostream>
#include <vector>
using namespace std;
using std::vector;


int main()
{
	vector<int> v1{ 1,2,3,5,8,10,21,20,52,60,80,90 };
	int a,b;
	for (decltype(v1.size()) i = 0; i <= v1.size()/2; i++)
	{
		b = v1.size() - i;
		a = v1[i] + v1[b];
		cout << a << endl;
	}
	system("pause");
	return 0;
}