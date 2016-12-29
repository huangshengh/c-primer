#include <iostream>
#include <string>
using namespace std;

istream& put(istream & a)
{
	string word;
	while (a >> word)
	{
		cout << word<<endl;
	}
	a.clear();
	return a;
}
 

int main()
{
	istream& i = put(cin);
	cout << i.rdstate() << endl;
	system("pause");
	return 0;
}