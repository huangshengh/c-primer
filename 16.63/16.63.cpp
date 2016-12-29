#include <string>
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::endl;
using std::string;

template<typename T>
void foundtimes(T &s,const vector<T>&a)
{
	int i = 0;
	for (auto b : a)
	{
		if (b == s)
		{
			++i;
		}
		else
			continue;
	  }
	cout << "has " << i << " " << s << endl;
}

template<>
void foundtimes(const char* &s, const vector<const char *> &a)
{
	int i = 0;
	for (auto b : a)
	{
		if (b == s)
		{
			++i;
		}
		else
			continue;
	}
	cout << "has " << i << " " << *s << endl;
}


int main()
{
	string s = "za";
	vector<string> b = { "zale","mei","shi","za","za","za"};
	//foundtimes(s, b);
	const char* c = "hello";
	vector<const char*> a = { "helloworld","hello","world","helloworld" };
	//foundtimes(c, a); 
	system("pause");
	return 0;
}