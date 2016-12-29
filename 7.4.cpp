#include <string>
#include <vector>
using namespace std;


struct Person 
{
	string name;
	string address;
	vector<string> info() const
	{
		vector<string> list;
		list.push_back(name);
		list.push_back(address);
		return list;
	}
};