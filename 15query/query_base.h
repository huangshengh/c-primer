#ifndef query_base_h
#define query_base_h

#include "text.h"

//�������
class query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~query_base() = default;
private:
	//�����뵱ǰqueryƥ���queryresult��
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;//��ʾ��ѯ��һ��string
};


#endif//query_base
