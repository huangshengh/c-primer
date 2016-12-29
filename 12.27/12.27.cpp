#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <istream>

using std::vector;
using std::string;
using std::map;
using std::set;


class QueryResult;

class TextQuery
{
public:
	TextQuery();
	TextQuery(std::ifstream &file) 
	{
		string line;
		while (getline(file, line))
			data.push_back(line);
	};
	set<int> amount_of_line(vector<string> &a)
	{
		for (auto b = 1; b < a.size(); b++)
			set<int> num.insert(b);
		return num;
	 }

private:
	vector<string> data; 
	set<int> num;
	string word;
	map<string, set<int>> result;
};