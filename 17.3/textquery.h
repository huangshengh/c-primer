#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include <tuple>
#include<iostream> 

using std::vector;
using std::string;
using std::map;
using std::set;
using std::cout;
using std::cin;
using std::endl;
using std::tuple;
using std::shared_ptr;


typedef vector<string>::size_type index_Tp;
typedef tuple<string, shared_ptr<set<index_Tp>>, shared_ptr<vector<string>>> result_tuple;
class QueryResult;

class TextQuery
{
public:
	TextQuery(std::ifstream&);
	QueryResult query(const string &s) const;
	result_tuple query_return_tuple(const string&s)const;
private:
	shared_ptr<vector<string>>file;
	map<string,shared_ptr<set<index_Tp>>> wm
};






#endif // !TEXTQUERY_H_
#pragma once
