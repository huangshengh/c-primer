#ifndef query_base_h
#define query_base_h

#include "text.h"

//抽象基类
class query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~query_base() = default;
private:
	//返回与当前query匹配的queryresult；
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;//表示查询的一个string
};


#endif//query_base
