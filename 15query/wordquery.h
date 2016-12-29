#ifndef wordquery_h
#define wordquery_h

#include "query.h"
#include "query_base.h"
#include "text.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;  


class wordquery :public query_base
{
	friend class Query;
	wordquery(const string&s):query_word(s){}
	
	QueryResult eval(const TextQuery&t)const
	{
		return t.query(query_word);
	}

	string rep() const { return query_word; }
	string query_word;
};


class NotQuery :public query_base
{
	friend Query operator~(const Query&);
	NotQuery(const Query&q) :query(q){}
	string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&t) const
	{
		auto result = query.eval(t);
		auto ret_lines = make_shared<set<line_no>>();
		auto beg = result.begin(), end = result.end();
		auto sz = result.get_file()->size();
		for (size_t n = 0; n != sz; ++n)
		{
			if (beg == end || *beg != n)
				ret_lines->insert(n);
			else if(beg != end)
				++beg;
		}
		return QueryResult(rep(), ret_lines, result.get_file());
	};
	
	Query query;
};

inline Query operator~(const Query&operand)
{
	return shared_ptr<query_base>(new NotQuery(operand)); 
}

#endif // !wordquery_h#pragma once
