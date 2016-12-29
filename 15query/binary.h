#ifndef binary_h
#define binary_h

#include "query_base.h"
#include "query.h"
#include"text.h"
#include <memory>
#include <algorithm>
#include <iterator>

class BinaryQuery :public query_base
{
protected:
	BinaryQuery(const Query&l, const Query&r, std::string s) :lhs(l),rhs(r),opSym(s){}
	std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;  
};


class AndQuery :public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query&lhs, const Query &rhs) :BinaryQuery(lhs, rhs, "&"){}
	QueryResult eval(const TextQuery& text) const
	{
		auto left = lhs.eval(text), right = rhs.eval(text);
		auto ret_lines = make_shared<set<line_no>>();
		set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
		return QueryResult(rep(), ret_lines, left.get_file());
	}
};

inline Query operator&(const Query&lhs, const Query &rhs)
{
	return shared_ptr<query_base>(new AndQuery(lhs, rhs));
}

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query&lhs, const Query&rhs) :BinaryQuery(lhs, rhs, "|") {}
	QueryResult eval(const TextQuery& text)const
	{
		auto right = rhs.eval(text), left = lhs.eval(text);
		auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
		ret_lines->insert(right.begin(), right.end());
		return QueryResult(rep(), ret_lines, left.get_file);
	}
};

inline Query operator|(const Query&lhs, const Query&rhs)
{
	return shared_ptr<query_base>(new OrQuery(lhs, rhs));
}
#endif // !binary_h#pragma once
