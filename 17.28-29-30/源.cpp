#include <iostream>
#include <string>
#include <random>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	std::default_random_engine e(528);
	std::uniform_int_distribution<unsigned> u(0, 9);
	vector<int> vec;
	for (size_t i = 0; i < 10; ++i)
	{
		vec.push_back(u(e));
	}
	//cout << "the vector is: " << endl; 
//	for (auto i : vec)
//		cout << i << endl;
	cout << e() <<" "<< e.min()<<" "<<e.max()<<endl;
	system("pause");
	return 0;

}