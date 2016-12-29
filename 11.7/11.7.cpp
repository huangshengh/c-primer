#include <iostream>
#include <vector>
#include <map>
#include <string> 
#include <algorithm>

using namespace std;


void new_family(const string &a, map<string, vector<string>> b)
{
	b[a];
}


void new_members(const string &a, map<string, vector<string>>b,const string &c)
{
	b[a].push_back(c);
}

int main()
{
	string line;
	vector<string> first_name;
	map<string, vector<string>> family;
	cout << "new_family:" << endl;
	while (cin >> line)
		new_family(line, family);
	cout << "new_members:" << endl;

}