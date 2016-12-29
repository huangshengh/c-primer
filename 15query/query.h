#ifndef Query_h
#define Query_h

#include "query_base.h"

//����һ������query_base�̳���ϵ�Ľ����
class Query
{
	//��Щ�������Ҫ����shared_ptr�Ĺ��캯��
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string&s) :q(new wordquery(s)) {}//����һ��wordquery
	QueryResult eval(const TextQuery& t)const
	{
		return q->eval(t); 
	}
	//q��һ��query_base��ָ�룬���ҵ��õ���һ���麯����������������Ҫ������ʱ���ܰ� ������һ���ӿں��������ö�Ӧ�Ĳ���
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
