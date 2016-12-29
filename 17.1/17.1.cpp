#include <iostream>
#include <tuple>
#include <algorithm>
#include <string>
#include <vector>
#include <utility> 

using std::tuple;
using std::string;
using std::vector;
using std::pair;


int main()
{
	tuple<int, int, int>i(10, 20, 30);
	string a = "helloworld";
	vector<string>v1(10, "a");
	pair<string, int> pa("hello", 5);
	tuple<string, vector<string>, pair<string, int>>mu(a,v1,pa);
	//std::cout << i << std::endl;
	system("pause");
	return 0;
}