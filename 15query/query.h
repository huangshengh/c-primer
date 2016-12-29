#ifndef Query_h
#define Query_h

#include "query_base.h"

//这是一个管理query_base继承体系的借口类
class Query
{
	//这些运算符需要接受shared_ptr的构造函数
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string&s) :q(new wordquery(s)) {}//创建一个wordquery
	QueryResult eval(const TextQuery& t)const
	{
		return q->eval(t); 
	}
	//q是一个query_base的指针，并且调用的是一个虚函数，所以他的类型要到运行时才能绑定 。这是一个接口函数，调用对应的操作
	string rep() const { return q->rep(); }
private:
	Query(shared_ptr<query_base> query):q(query){}
	shared_ptr<query_base> q;
};

std::ostream& operator<<(std::ostream&os, const Query& quer)
{
	return os << quer.rep();
}

#endif // !Query_h#pragma once
