#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list; 
using std::cout;
using std::endl;

template<typename A,typename B>
auto ifind(A a, A b, const B& c)
{
	A m;
	for (m = a; m != b; ++m)
	{
		if (*m == c)
		{
			return m;
			break;
		}
		else
			continue;
	}
	return m;
}

int main()
{
	vector<int> vec1{ 1,2,3,4,5,6,7,8,9 };
	list<string> str{ "hello","this","word" };
	auto result = ifind(vec1.begin(), vec1.end(), 5);
	cout << "the result is" << (result == vec1.end() ? " not existed" : "  existed") << endl;
	auto resu = ifind(str.begin(), str.end(), "wo");
	cout << "the result is" << (resu == str.end() ? " not existed" : " existed") << endl;
	system("pause");
	return 0;

}